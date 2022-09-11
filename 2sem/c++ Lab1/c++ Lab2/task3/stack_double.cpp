#include "stack_double.h"

Stack_Double::Stack_Double()
{
    calculation = 0;
}

Stack_Double::~Stack_Double()
{
    while(calculation)
    {
        pop();
    }
}

bool Stack_Double::calculation_empty()
{
    return calculation == 0;
}

void Stack_Double::push(double calculation_add)
{
    List2* next_calculation = new List2;
    next_calculation->set(calculation_add, calculation);
    calculation = next_calculation;
}

double Stack_Double::peek()
{
    if (!calculation_empty())
    {
        return calculation->info_calculation();
    }
    return 0;
}

void Stack_Double::pop()
{
    if (!calculation_empty())
    {
        List2 *previous_calculation = calculation->info_next_calculation();
        delete calculation;
        calculation = previous_calculation;
    }
}
