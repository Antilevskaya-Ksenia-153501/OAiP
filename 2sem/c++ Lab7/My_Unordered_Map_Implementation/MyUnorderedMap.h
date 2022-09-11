#ifndef MYUNORDEREDMAP_H
#define MYUNORDEREDMAP_H
#include <QString>
#include <forward_list>
#include <list>
#include <iterator>
#include<QMessageBox>

template <typename TypeKey, typename Type, class Hash = std::hash<TypeKey>>
class MyUnorderedMap
{
public:
    typedef std::pair<TypeKey, Type> element;
    MyUnorderedMap(Hash hasher_temp = Hash{})
    {
        Table = new std::forward_list<element>[10];
        size_of_map = 10;
        number_of_elem = 0;
        hasher = hasher_temp;
    }
    ~MyUnorderedMap()
    {
        for (int i = 0; i < 10; ++i)
        {
           Table[i].clear();
        }
        delete[] Table;
        number_of_elem = 0;
    }
    void Insert(const TypeKey& key, const Type& value)
    {
        if (Contains(key))
            return;
        Rehash(number_of_elem);
        size_t hashValue = hashFunction(key);
        Table[hashValue].push_front(element(key, value));
        list_of_elements.push_back(element(key, value));
        ++number_of_elem;
    }
    void Erase(const TypeKey& key)
    {
        size_t hashValue = hashFunction(key);
        if (Table[hashValue].empty())
            return;
        else
        {
            for(typename std::forward_list<element>::iterator it = Table[hashValue].begin(); it != Table[hashValue].end(); it++)
            {
                element temp = *it;
                if (temp.first == key)
                {
                    Table[hashValue].remove(*it);
                    list_of_elements.remove(*it);
                    --number_of_elem;
                    break;
                }
            }
        }
    }
    bool Contains(const TypeKey& key)
    {
        size_t hashValue = hashFunction(key);
        for(typename std::forward_list<element>::iterator it = Table[hashValue].begin(); it != Table[hashValue].end(); it++)
        {
            element temp = *it;
            if (temp.first == key)
            {
                return true;
            }
        }
        return false;
    }
    typename std::forward_list<element>::iterator Find(const TypeKey& key)
    {
        size_t hashValue = hashFunction(key);
        typename std::forward_list<element>::iterator it = Table[hashValue].begin();
        for(;it != Table[hashValue].end(); it++)
        {
            if (it->first == key)
            {
                return it;
            }
        }
        it = Table[hashValue].end();
        return it;
    }
    void Clear()
    {
        for (int i = 0; i < 10; ++i)
        {
           Table[i].clear();
        }
    }
    Type& operator[](const TypeKey& findKey)
    {
        static typename std::forward_list<element>::iterator temp ;
        temp = Find(findKey);
        if (!Contains(findKey))
            Insert(findKey, Type());
        return temp->second;
    }
    Type at(const TypeKey& findKey)
    {
        static typename std::forward_list<element>::iterator temp ;
        temp = Find(findKey);
        if (!Contains(findKey))
            throw std::out_of_range("Key doesn't exist");
        return temp->second;
    }
    QString* Print()
    {
        QString* result;
        result = new QString[size_of_map];
        for (size_t i = 0; i < size_of_map; i++)
        {
            for(typename std::forward_list<element>::iterator it = Table[i].begin(); it != Table[i].end(); it++)
            {
                element temp = *it;
                result[i] += " ID" + QString::number(i) + " Key: " + QString::number(temp.first) + " Value: " + QString::number(temp.second);
            }
        }
        return result;
    }
    size_t hashFunction(TypeKey key)
    {
        return hasher(key) % size_of_map;
    }
    void Rehash(size_t count)
    {
        if (count <= size_of_map)
            return;
        Clear();
        delete[] Table;
        size_of_map = count + 5;
        Table = new std::forward_list<element>[size_of_map];
        for(typename std::list<element>::iterator it = list_of_elements.begin(); it != list_of_elements.end(); it++)
        {
           element temp = *it;
           size_t hashValue = hashFunction(temp.first);
           Table[hashValue].push_front(element(temp.first, temp.second));
        }
        return;
    }
    size_t NumberofElem()
    {
        return number_of_elem;
    }
    size_t MapSize()
    {
        return size_of_map;
    }
private:
    Hash hasher;
    std::forward_list<element>* Table;
    std::list<element> list_of_elements;
    size_t size_of_map;
    size_t number_of_elem;
};



#endif // MYUNORDEREDMAP_H
