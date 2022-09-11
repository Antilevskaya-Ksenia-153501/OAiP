#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "unique_ptr.h"
#include "shared_ptr.h"
#include <QString>

template <typename Type>
class MyQueue
{
private:
    class MyQueue_Element
    {
    public:
        Type data;
        Shared_Ptr<MyQueue_Element> next = nullptr;
        MyQueue_Element(const Type& value)
        {
            data = value;
        }
    };
    Shared_Ptr<MyQueue_Element> head, tail;
    int size;
public:
    MyQueue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~MyQueue()
    {
    }
    void Push_Back(const Type& value)
    {
        Shared_Ptr<MyQueue_Element> elem = make_shared_ptr<MyQueue_Element>(value);
        if (!head)
        {
            head = tail = elem;
            size = 1;
        }
        else
        {
            tail->next = elem;
            tail = elem;
            size++;
        }
    }
    Type Pop_Front()
    {
        if (!head)
            return 0;
        else
        {
            Type value = head->data;
            Unique_Ptr<MyQueue_Element> elem = std::move(head.get());
            head = head->next;
            elem.reset();
            size--;
            return value ;
        }
    }

    bool Empty()
    {
        return size == 0;
    }

    int Size()
    {
        return size;
    }

    Type& Front() const
    {
        return head->data;
    }

    Type& Back() const
    {
        return tail->data;
    }

    QString Display()
    {
        QString result;
        if (Empty())
        {
            result = "Queue is empty";
            return result;
        }
        else
        {
            Shared_Ptr<MyQueue_Element> current = head;
            while(current)
            {
                result += current->data + " ";
                current = current->next;
            }
            return result;
        }
    }
};
#endif // MYQUEUE_H
