#ifndef STACK_QCHAR_H
#define STACK_QCHAR_H
#include<QChar>

class List
{
private:
    QChar formula;
    List *next_formula;
public:
    void set(QChar formula_temp, List *next_formula_temp)
    {
        formula = formula_temp;
        next_formula = next_formula_temp;
    }

    QChar info_formula()
    {
        return formula;
    }

    List *info_next_formula()
    {
        return next_formula;
    }
};

class Stack_QChar
{
    List *formula;
public:
    Stack_QChar();
    ~Stack_QChar();
    bool formula_empty();
    void push(QChar formula_add);
    QChar peek();
    void pop();
};

#endif // STACK_QCHAR_H

