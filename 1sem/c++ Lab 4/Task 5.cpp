#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int R, C, count = 0;
    cout << "Enter number of rows: ";
    cin >> R;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!" << endl;
        exit(0);
    }
    cout << "Enter number of columns: ";
    cin >> C;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!" << endl;
        exit(0);
    }
    double** arr1 = new double* [R];
    for (int i = 0; i < R; i++)
    {
        arr1[i] = new double[C];
        for (int j = 0; j < C; j++)
        {
            cout << "Enter a[" << i << "][" << j << "] = ";
            cin >> arr1[i][j];
            if (cin.fail())
            {
                cout << "Error. Enter a number, please!!!" << endl;
                exit(0);
            }
        }
    }
    double** arr2 = new double* [R];
    for (int i = 0; i < R; i++)
    {
        arr2[i] = new double[C];
    }
        
    cout << "\nArray: " << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 && j == 0) 
            {
                arr2[i][j] = (arr1[i + 1][j] + arr1[i][j + 1]) / 2;
            }
            else if (i == 0 && j + 1 <= C - 1 && j != 0) 
            {
                arr2[i][j] = (arr1[i + 1][j] + arr1[i][j + 1] + arr1[i][j - 1]) / 3;
            }
            else if (i == 0 && j == C - 1) 
            {
                arr2[i][j] = (arr1[i + 1][j] + arr1[i][j - 1]) / 2;
            }
            else if (j == 0 && i <= R - 2)
            {
                arr2[i][j] = (arr1[i - 1][j] + arr1[i][j + 1] + arr1[i + 1][j]) / 3;
            }
            else if (i <= R - 2 && j <= C - 2)
            {
                arr2[i][j] = (arr1[i][j - 1] + arr1[i][j + 1] + arr1[i + 1][j] + arr1[i - 1][j]) / 4;
            }
            else if (i <= R - 2 && j == C - 1)
            {
                arr2[i][j] = (arr1[i - 1][j] + arr1[i][j - 1] + arr1[i + 1][j]) / 3;
            }
            else if (i == R - 1 && j == 0)
            {
                arr2[i][j] = (arr1[i - 1][j] + arr1[i][j + 1]) / 2;
            }
            else if (i == R - 1 && j + 1 <= C - 1)
            {
                arr2[i][j] = (arr1[i - 1][j] + arr1[i][j + 1] + arr1[i][j - 1]) / 3;
            }
            else if (i == R - 1 && j == C - 1)
            {
                arr2[i][j] = (arr1[i - 1][j] + arr1[i][j - 1]) / 2;
            }
        }
    }
    cout << "\nNew array: " << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < R; i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;
    for (int i = 0; i < R; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;
    system("pause");
    return 0;


}



