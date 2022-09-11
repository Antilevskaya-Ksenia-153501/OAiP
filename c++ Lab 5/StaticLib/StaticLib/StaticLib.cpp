// StaticLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "StaticLib.h"
#include <iostream>


int function(int n)
{
    if (n % 10 > 0) return n % 10;
    if (n == 0) return 0;
    else  return function(n / 10);
}
int sum(int p, int q)
{
    int sum = 0;
    for (int i = p; i <= q; i++)
    {
        sum += function(i);
    }
    return sum;
}

