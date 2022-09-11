#ifndef STACK_H
#define STACK_H
#include<QString>
#include<QChar>

class List
{
protected:
    QChar symbol;
public: int x = 0, y = 0;
    List *next;
public:
    void set(QChar symbol_temp, List *n_c, int x1 = 0, int y1 = 0)
    {
        symbol = symbol_temp;
        x = x1;
        y = y1;
        next = n_c;
    }

    QChar info_symbol()
    {
        return symbol;
    }
    int info_x()
    {
        return x;
    }
    int info_y()
    {
        return y;
    }
    List *info_next()
    {
        return next;
    }

};

class Stack
{
private:
    List *current;
public:
    Stack();
    ~Stack();
    bool st_empty();
    void push(QChar symbol, int x1, int y1);
    QChar peek();
    int peek_x();
    int peek_y();
    void pop();
};
#endif // STACK_H


