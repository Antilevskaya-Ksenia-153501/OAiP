#ifndef MYMAP_H
#define MYMAP_H
#include <mytree.h>

template <typename TypeKey, typename Type>
class MyMap
{
public:
    class MyMapIterator;
    class MyMapIterator_List;
    ~MyMap()
    {
        map.~MyTree();
    }
    MyMapIterator Begin()
    {
       MyTreeNode<TypeKey, Type>* ptr = map.GetRoot();
       if (ptr != nullptr)
       {
           while (ptr->left != nullptr)
               ptr = ptr->left;
       }
       return MyMapIterator(ptr);
    }
    MyMapIterator End()
    {
        if (map.GetRoot() == nullptr)
            return 0;
        return  MyMapIterator(map.GetRoot()->parent);
    }
    MyMapIterator_List Begin_List()
    {
       MyMapIterator_List ptr(map.GetRoot());
       return ptr;
    }
    MyMapIterator_List End_List()
    {
        return MyMapIterator_List(map.GetRoot()->parent);
    }
    Type& operator[](const TypeKey& findKey)
    {
        MyMapIterator temp(map.GetSearch(findKey));
        if (temp.Get() == nullptr)
            temp = (Insert(std::pair<TypeKey, Type>(findKey, Type()))).first;
        return temp.Get()->data.second;
    }
    Type at(const TypeKey& findKey)
    {
        MyMapIterator temp(map.GetSearch(findKey));
        if (temp == End())
            throw std::out_of_range("Key doesn't exist");
           return temp.Get()->data.second;
    }
    std::pair<MyMapIterator, bool> Insert(std::pair<TypeKey, Type> val)
    {
        MyTreeNode<TypeKey, Type>* temp(map.GetSearch(val.first));
        MyTreeNode<TypeKey, Type>* res_temp = new MyTreeNode<TypeKey, Type>(val.first, val.second);
        MyMapIterator res(res_temp);
        std::pair<MyMapIterator, bool> result(res, true);
        if(temp && temp->data.first == val.first)
        {
            result.second = false;
            return result;
        }
        else
        {
            map.AddTreeNode(val.first, val.second);
            return result;
        }
        delete res_temp;
    }
    std::pair<std::pair<TypeKey, Type>, bool> Emplace(TypeKey key, Type value)
    {
        std::pair<TypeKey, Type> temp(key, value);
        return Insert(temp);
    }
    std::pair<TypeKey, Type> Find(TypeKey findKey)
    {
        MyTreeNode<TypeKey, Type>* temp(map.GetSearch(findKey));
        if (temp)
            return temp->data;
        else
        {
            std::pair<TypeKey, Type> notFound(0, 0);
            return notFound;
        }
    }
    void Erase(const TypeKey& DeleteKey)
    {
        map.Remove(DeleteKey);
    }
private:
    MyTree<TypeKey, Type> map;
};

template<typename TypeKey, typename Type> class MyMap<TypeKey, Type>:: MyMapIterator
{
public:
    MyMapIterator() = default;
    ~MyMapIterator() = default;
    MyMapIterator(MyTreeNode<TypeKey, Type>* temp)
    {
        current = temp;
    }
    MyMapIterator(const MyMapIterator& ptr)
    {
        current = ptr.current;
    }
    MyMapIterator& operator=(const MyMapIterator& ptr)
    {
        current = ptr.current;
        return *this;
    }
    bool operator==(const MyMapIterator& ptr)
    {
        return current == ptr.current;
    }
    bool operator !=(const MyMapIterator& ptr)
    {
        return current != ptr.current;
    }
    MyMapIterator& operator++()
    {
        if (current->right)
        {
            current = current->right;
            while (current->left)
                current = current->left;
        }
        else
        {
            MyTreeNode<TypeKey, Type>* before;
            do
            {
                before = current;
                current = current->parent;
            } while (current && before == current->right);
        }
        return *this;
    }
    MyMapIterator operator++(int)
    {
        MyMapIterator temp(*this);
        ++(*this);
        return temp;
    }
    MyMapIterator& operator--()
    {
        if (current->left)
        {
            current = current->left;
            while (current->right)
                current = current->right;
        }
        else
        {
            MyTreeNode<TypeKey, Type>* before;
            do
            {
                before = current;
                current = current->parent;
            } while (current && before == current->left);
        }
        return *this;
    }
    MyMapIterator operator--(int)
    {
        MyMapIterator temp(*this);
        --(*this);
        return temp;
    }
    TypeKey& operator*() const
    {
        return current->data.first;
    }
    std::pair<TypeKey, Type>* operator->() const
    {
        return &(current->data);
    }
    MyTreeNode<TypeKey, Type>* Get() const
    {
        return current;
    }
private:
    MyTreeNode<TypeKey, Type>* current;
};

template<typename TypeKey, typename Type> class MyMap<TypeKey, Type>:: MyMapIterator_List
{
public:
    MyMapIterator_List() = default;
    MyMapIterator_List(MyTreeNode<TypeKey, Type>* temp)
    {
        StoreNodes(temp);
    }
    MyMapIterator_List(const MyMapIterator_List& ptr)
    {
        MyTreeList = ptr.MyTreeList;
    }
    MyMapIterator_List& operator++()
    {
        MyTreeList.pop_front();
        return *this;
    }
    const MyMapIterator_List operator++(int)
    {
        MyMapIterator_List temp(*this);
        MyTreeList.pop_front();
        return temp;
    }
    MyMapIterator_List& operator--()
    {
        MyTreeList.pop_back();
        return *this;
    }

    const MyMapIterator_List operator--(int)
    {
        MyMapIterator_List temp(*this);
        MyTreeList.pop_back();
        return temp;
    }
    bool operator==(const MyMapIterator_List& ptr)
    {
        return MyTreeList.front() == ptr.MyTreeList.front();
    }
    bool operator !=(const MyMapIterator_List& ptr)
    {
        return MyTreeList.front() != ptr.MyTreeList.front();
    }
    TypeKey& operator*() const
    {
        MyTreeNode<TypeKey, Type>* curr = MyTreeList.front();
        return curr->data.first;
    }
    std::pair<TypeKey, Type>* operator->() const
    {
        MyTreeNode<TypeKey, Type>* curr = MyTreeList.front();
        return &(curr->data);
    }
private:
    std::list<MyTreeNode<TypeKey, Type>*> MyTreeList;
    void StoreNodes(MyTreeNode<TypeKey, Type>* root)
    {
        if (root != nullptr)
        {
            StoreNodes(root->left);
            MyTreeList.push_back(root);
            StoreNodes(root->right);
        }
    }
};
#endif // MYMAP_H
