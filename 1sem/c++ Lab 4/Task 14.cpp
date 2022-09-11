#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, m, count = 0;
    cout << "Enter number of rows: ";
    cin >> n;
    if (cin.fail())
    {
        cout << "Error. Enter a number,please!!!" << endl;
        exit(0);
    }
    cout << "Enter number of columns: ";
    cin >> m;
    if (cin.fail())
    {
        cout << "Error. Enter a number,please!!!" << endl;
        exit(0);
    }
    char** arr1 = new char* [n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = new char[m];
    }
    char** arr2 = new char* [n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = new char[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cout << "Enter a[" << i << j << "]: ";
            cin >> arr1[i][j];
            if (arr1[i][j] != '.' && arr1[i][j] != '*')
            {
                cout << "Error. Enter a * or . ,please!!!" << endl;
                exit(0);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i][j] == '*') 
            {
                arr2[i][j] = arr1[i][j];
                continue;
            }
            else if (i == 0 && j == 0) 
            {
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i + 1][j + 1] == '*') count++;
            }
            else if (i == 0 && j == m - 1)
            {
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i + 1][j - 1] == '*') count++;
            }
            else if (i == 0) 
            {
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i + 1][j + 1] == '*') count++;
                if (arr1[i + 1][j - 1] == '*') count++;
            }
            else if (i == n - 1 && j == 0)
            {
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i - 1][j + 1] == '*') count++;
            }
            else if (i == n - 1 && j == m - 1)
            {
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i - 1][j - 1] == '*') count++;
            }
            else if (i == n - 1)
            {
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i - 1][j - 1] == '*') count++;
                if (arr1[i - 1][j + 1] == '*') count++;
            }
            else if (j == 0)
            {
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i - 1][j + 1] == '*') count++;
                if (arr1[i + 1][j + 1] == '*') count++;

            }
            else if (j == m - 1) 
            {
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i - 1][j - 1] == '*') count++;
                if (arr1[i + 1][j - 1] == '*') count++;

            }
            else 
            {
                if (arr1[i - 1][j] == '*') count++;
                if (arr1[i][j - 1] == '*') count++;
                if (arr1[i][j + 1] == '*') count++;
                if (arr1[i + 1][j] == '*') count++;
                if (arr1[i - 1][j - 1] == '*') count++;
                if (arr1[i - 1][j + 1] == '*') count++;
                if (arr1[i + 1][j + 1] == '*') count++;
                if (arr1[i + 1][j - 1] == '*') count++;
            }
            if (count == 0) arr2[i][j] = '.';
            else 
            {
                char count1 = count + '0';
                arr2[i][j] = count1;
                count = 0;
            }

        }
    }
    cout << "Unblocking field of game: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;
    for (int i = 0; i < n; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;
    system("pause");
    return 0;
}

