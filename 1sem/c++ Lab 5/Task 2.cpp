#include <iostream>
#include <cmath>
#include "DynamicLib.h"
using namespace std;
/*void transformation(double* matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        matrix[i]= pow(matrix[i], 2) + cos(matrix[i]);
    }
}
double sum(double* matrix, int n,int i)
{
    if (i == n - 1) return matrix[i];
    else return matrix[i] + sum(matrix, n, i + 1);
}
*/
int main()
{
    int n;
    cout << "This program will calculate the multiplication of sums of half matrix" << endl;
    cout << endl << "Enter number of elements: ";
    cin >> n;
    if (cin.fail() || n <= 0)
    {
        cout << "Error. Enter a correct number,please!!!!" << endl;
        exit(0);
    }
    double *matrix = new double[n];
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter a[" << i << "]: ";
        cin >> matrix[i];
        if (cin.fail())
        {
            cout << "Error.Enter a number,please!!!!" << endl;
            exit(0);
        }
     }
    transformation(matrix, n);
    cout << endl <<"The sum of the first half: "<< sum(matrix, n / 2, 0);
    cout << endl<< "The sum of the second half: " << sum(matrix, n, n / 2);
    cout << endl <<"The multiplication of sums: "<< sum(matrix, n / 2, 0) * sum(matrix, n, n / 2);
    cout << endl;
    delete[] matrix;
    system("pause");
    return 0;
    
}

