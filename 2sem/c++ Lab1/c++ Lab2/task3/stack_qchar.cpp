#include "stack_qchar.h"

Stack_QChar::Stack_QChar()
{
    formula = 0;
}

Stack_QChar::~Stack_QChar()
{
    while(formula)
    {
        pop();
    }
}

bool Stack_QChar::formula_empty()
{
    return formula == 0;
}

void Stack_QChar::push(QChar formula_add)
{
    List* next_formula = new List;
    next_formula->set(formula_add, formula);
    formula = next_formula;
}

QChar Stack_QChar::peek()
{
    if (!formula_empty())
    {
        return formula->info_formula();
    }
    return '\0';
}

void Stack_QChar::pop()
{
    if (!formula_empty())
    {
        List *previous_formula = formula->info_next_formula();
        delete formula;
        formula = previous_formula;
    }
}
