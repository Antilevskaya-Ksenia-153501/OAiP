#ifndef STACK_H
#define STACK_H
#include "unique_ptr.h"
#include<QString>

class Node
{
public:
    QString data;
    Unique_Ptr<Node> next;
    QString info_symbol()
    {
        return data;
    }
};

class Stack
{
public:
    Unique_Ptr<Node> head;
    Stack();
    ~Stack();

    void push(QString x);
    bool stack_is_empty();
    QString peek();
    void pop();
    QString print();
};

#endif // STACK_H
