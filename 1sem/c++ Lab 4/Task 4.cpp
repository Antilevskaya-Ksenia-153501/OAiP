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
    double** arr = new double* [R];
    for (int i = 0; i < R; i++)
    {
        arr[i] = new double[C];
        for (int j = 0; j < C; j++)
        {
            cout << "Enter a[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
            if (cin.fail())
            {
                cout << "Error. Enter a number, please!!!" << endl;
                exit(0);
            }
        }
    }
    cout << "\nArray: " << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (arr[i - 1][j] > arr[i][j] && arr[i][j - 1] > arr[i][j] && arr[i + 1][j] > arr[i][j] && arr[i][j + 1] > arr[i][j])
            {
                cout << "Local minimum = " << arr[i][j] << endl;
                count++;
            }
        }
    }
    for (int i = 0; i < R; i++) 
    {
        delete[] arr[i];
    }
    delete [] arr;
    cout << "There are " << count << " local minimums in the arrray" << endl;
    system("pause");
    return 0;

    
}

