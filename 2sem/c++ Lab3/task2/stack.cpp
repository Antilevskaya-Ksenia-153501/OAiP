#include "stack.h"

Stack::Stack()
{
    head = nullptr;
}

Stack::~Stack()
{
    while (head)
        head = std::move(head->next);
}

void Stack::push(QString x)
{
    head = Unique_Ptr<Node>(new Node{x, std::move(head)});
}

bool Stack::stack_is_empty()
{
    if (head)
        return 1;
    else return 0;
}

QString Stack::peek()
{
    if (stack_is_empty())
    {
        return head->info_symbol();
    }
    return 0;
}

void Stack::pop()
{
    if (stack_is_empty())
    {
        head = std::move(head->next);
    }
}

QString Stack::print()
{
    Node* Current = head.get();
    QString result;
        while(Current)
        {
            result += Current->data + " ";
            Current = Current->next.get();
        }
       return result;
}
