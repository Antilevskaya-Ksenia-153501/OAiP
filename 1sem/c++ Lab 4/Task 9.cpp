#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int N;
    cout << "Enter size of arrays:";
    cin >> N;
    if (cin.fail())
    {
        cout << "Error. Enter a number,please!!!" << endl;
        exit(0);
    }
    int** A = new int* [N];
    for (int i = 0; i < N; i++) 
    {
        A[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cout << "Enter a[" << i << "]" << "[" << j << "]: ";
            cin >> A[i][j];
            if (cin.fail())
            {
                cout << "Error. Enter a number,please!!!" << endl;
                exit(0);
            }
        }
    }
    cout << "\nArray A: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    int** B = new int* [N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cout << "Enter b[" << i << "]" << "[" << j << "]: ";
            cin >> B[i][j];
            if (cin.fail())
            {
                cout << "Error. Enter a number,please!!!" << endl;
                exit(0);
            }
        }
    }
    cout << "\nArray B: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    int** C = new int* [N];
    for (int i = 0; i < N; i++)
    {
        C[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int h = 0; h < N; h++) 
            {
                C[i][j] += A[i][h] * B[h][j];
            }
        }
    }
    cout << "C = A * B" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    for (int i = 0; i < N; i++)
    {
        delete[] B[i];
    }
    delete[] B;
    for (int i = 0; i < N; i++)
    {
        delete[] C[i];
    }
    delete[] C;
    system("pause");
    return 0;
}

