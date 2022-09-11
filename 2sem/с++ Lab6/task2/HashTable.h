#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QString>

template <typename Type, typename TypeKey>
class HashStack
{
public:
    HashStack()
    {
        current = 0;
    }
    ~HashStack()
    {
        while(current)
        {
            Pop();
        }
    }
    bool Empty()
    {
        return current == 0;
    }
    void Push(Type data, TypeKey key)
    {
        HashNode* nextNode = new HashNode;
        nextNode->set(data, key, current);
        current = nextNode;
    }
    Type Peek_Data()
    {
        if (!Empty())
            return current->getValue();
        return 0;
    }
    TypeKey Peek_Key()
    {
        if (!Empty())
            return current->getKey();
        return 0;
    }
    void Pop()
    {
        if (!Empty())
        {
            HashNode* other = current->getNext();
            delete current;
            current = other;
        }
    }
    QString PrintHashStack()
    {
        HashNode* temp = current;
        QString result;
        while(temp)
        {
            result += " Data: " + QString::number(temp->getValue()) + " " + "Key: " +  QString::number(temp->getKey()) + " ";
            temp = temp->getNext();
        }
        return result;
    }
private:
    class HashNode
    {
    public:
        HashNode()
        {
            key = TypeKey();
            value = Type();
            next = nullptr;
        }
        TypeKey getKey() const
        {
            return key;
        }
        Type getValue() const
        {
            return value;
        }
        void set(Type value, Type key, HashNode* nextNode)
        {
            this->value = value;
            this->key = key;
            this->next = nextNode;
        }
        HashNode *getNext() const
        {
            return next;
        }
    private:
        TypeKey key;
        Type value;
        HashNode* next;
    };
    HashNode* current;
};

template <typename Type, typename TypeKey>
class HashTable
{
public:
    HashTable()
    {
        table = new HashStack<Type, TypeKey>* [10]();
        for (int i = 0; i < 10; i++)
            table[i] = new HashStack<Type, TypeKey>();
    }
    ~HashTable()
    {
        for (int i = 0; i < 10; ++i)
        {
            HashStack<Type, TypeKey>* temp = table[i];
            temp->Pop();
            table[i] = nullptr;
        }
        delete[] table;
    }
    bool Get(Type& value, const TypeKey& key)
    {
        unsigned long hashValue = hashFunction(key);
        HashStack<Type, TypeKey>* currentStack = table[hashValue];
        HashStack<Type, TypeKey>* temp = new HashStack<Type, TypeKey>;
        while (!currentStack->Empty())
        {
            if (currentStack->Peek_Key() == key)
            {
                value = currentStack->Peek_Data();
                temp->Push(currentStack->Peek_Data(), currentStack->Peek_Key());
                currentStack->Pop();
                table[hashValue] = temp;
                return true;
            }
            temp->Push(currentStack->Peek_Data(), currentStack->Peek_Key());
            currentStack->Pop();
            table[hashValue] = temp;
        }
        return false;
    }
    void Add(const Type& value, const TypeKey& key)
    {
        unsigned long hashValue = hashFunction(key);
        HashStack<Type, TypeKey>* temp = nullptr;
        HashStack<Type, TypeKey>* currentStack = table[hashValue];
        if (currentStack == nullptr)
        {
            currentStack = new HashStack<Type, TypeKey>;
            currentStack->Push(value, key);
            table[hashValue] = currentStack;
        }
        else
        {
            temp = new HashStack<Type, TypeKey>;
            while (!currentStack->Empty())
            {
                temp->Push(currentStack->Peek_Data(), currentStack->Peek_Key());
                currentStack->Pop();
            }
            temp->Push(value, key);
            table[hashValue] = temp;
        }
    }
    void Remove(const TypeKey& key)
    {
        unsigned long hashValue = hashFunction(key);
        HashStack<Type, TypeKey>* temp = nullptr;
        HashStack<Type, TypeKey>* currentStack = table[hashValue];
        if (currentStack == nullptr)
            return;
        else
        {
            temp = new HashStack<Type, TypeKey>;
            while (!currentStack->Empty())
            {
                if (currentStack->Peek_Key() == key)
                {
                    currentStack->Pop();
                    continue;
                }
                temp->Push(currentStack->Peek_Data(), currentStack->Peek_Key());
                currentStack->Pop();
            }
        }
        table[hashValue] = temp;
    }
    QString* Print()
    {
        QString* result;
        result = new QString[10];
        HashStack<Type, TypeKey>* currentStack;
        for (int i = 0; i < 10; i++)
        {
            currentStack = table[i];
            if (!currentStack)
                break;
            result[i] += "ID" + QString::number(i) + currentStack->PrintHashStack();
        }
        return result;
    }
protected:
    unsigned long hashFunction(TypeKey key)
    {
        return abs(key) % 10;
    }
    HashStack<Type, TypeKey>** table = nullptr;
};

#endif // HASHTABLE_H
