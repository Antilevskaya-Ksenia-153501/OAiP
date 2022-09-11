#include "stack.h"

Stack::Stack()
{
    current = 0;
}

Stack::~Stack()
{
    while(current)
    {
        pop();
    }
}

bool Stack::st_empty()
{
    return current == 0;
}

void Stack::push(QChar symbol, int x1, int y1)
{
    List* next_symbol = new List;
    next_symbol->set(symbol, current, x1, y1);
    current = next_symbol;
}

QChar Stack::peek()
{
    if (!st_empty())
    {
        return current->info_symbol();
    }
    return '\0';
}

int Stack::peek_x()
{
    if (!st_empty())
    {
        return current->info_x();
    }
    return 0;
}

int Stack::peek_y()
{
    if (!st_empty())
    {
        return current->info_y();
    }
    return 0;
}

void Stack::pop()
{
    if (!st_empty())
    {
        List *past = current->info_next();
        delete current;
        current = past;
    }
}

