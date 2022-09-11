#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "weak_ptr.h"
#include<QString>
class Node
{
public:
    QString Data;
    Shared_Ptr<Node> Next = nullptr;
    Weak_Ptr<Node> Previous;
    Node(QString temp_Data)
    {
        Data = temp_Data;
    }
    Node(QString temp_Data, Shared_Ptr<Node> prev)
    {
        Data = temp_Data;
        Previous = prev;
    }
};

class Doubly_Linked_List
{
public:
    Doubly_Linked_List()
    {
    }
    void Insert(QString data)
    {
        Insert(data, Size);
    }
    void Insert(QString data, unsigned int index)
    {
        if (!First)
        {
            First = make_shared_ptr<Node>(data);
            Size++;
            return;
        }
        Shared_Ptr<Node> node = getNodeByIndex(index);
        if (!node)
        {
            insert(getNodeByIndex(Size - 1), data);
        }
        else
        {
            insert(node->Previous.lock(), data);
        }
    }
    bool Delete(const QString& data)
    {
        Shared_Ptr<Node> node = getNodeByData(data);
        if (Size == 1)
        {
            --Size;
            return true;
        }
        if (!node)
            return false;
        Shared_Ptr<Node> prevNode = node->Previous.lock();
        if (!prevNode)
        {
            node->Next->Previous.lock() = nullptr;
            First = node->Next;
        }
        else
        {
            prevNode->Next = node->Next;
            if (node->Next)
            {
                node->Next->Previous = node->Previous;
            }
        }
        --Size;
        return true;
    }
    Shared_Ptr<Node> operator[](unsigned int index) const
    {
        return getNodeByIndex(index);
    }

    unsigned int GetLength() const
    {
        return Size;
    }
private:
    void insert(Shared_Ptr<Node> node, QString data)
    {
        Shared_Ptr<Node> newNode = make_shared_ptr<Node>(data, node);
        Size++;
        if (!node)
        {
            newNode->Next = First;
            First->Previous = newNode;
            First = newNode;
            return;
        }
        if (node->Next)
        {
            newNode->Next = node->Next;
            node->Next->Previous = newNode;
        }
        node->Next = newNode;
        newNode->Previous = node;
    }
    Shared_Ptr<Node> getNodeByData(const QString& data)
    {
        if (!First)
            return nullptr;
        Shared_Ptr<Node> node = First;
        while (node)
        {
            if (node->Data == data)
            {
                break;
            }
            node = node->Next;
        }
        return node;
    }
    Shared_Ptr<Node> getNodeByIndex(unsigned int index) const
    {
        if (index >= Size)
            return nullptr;
        unsigned int i = 0;
        Shared_Ptr<Node> node = First;
        while (node)
        {
            if (i == index)
            {
                break;
            }
            node = node->Next;
            i++;
        }
        return node;
    }
public:
    Shared_Ptr<Node> First = nullptr;
    size_t Size = 0;

};

#endif // DOUBLY_LINKED_LIST_H
