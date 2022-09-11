#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H

class List2
{
private:
    double calculation;
    List2 *next_calculation;
public:
    void set(double calculation_temp, List2 *next_calculation_temp)
    {
        calculation = calculation_temp;
        next_calculation = next_calculation_temp;
    }

    double info_calculation()
    {
        return calculation;
    }

    List2 *info_next_calculation()
    {
        return next_calculation;
    }
};

class Stack_Double
{
     List2 *calculation;
public:
    Stack_Double();
    ~Stack_Double();
    bool calculation_empty();
    void push(double calculation_add);
    double peek();
    void pop();
};

#endif // STACK_H


