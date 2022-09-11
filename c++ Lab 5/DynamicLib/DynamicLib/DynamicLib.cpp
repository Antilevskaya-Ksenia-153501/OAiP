#include "pch.h"
#include <cmath>
#include"DynamicLib.h"

void transformation(double* matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        matrix[i] = pow(matrix[i], 2) + cos(matrix[i]);
    }

}


double sum(double* matrix, int n, int i)
{
    if (i == n - 1) return matrix[i];
    else return matrix[i] + sum(matrix, n, i + 1);
}
