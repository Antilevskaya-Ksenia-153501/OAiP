#include <iostream>//variant 3
#include <stdlib.h>

using namespace std;

int main()
{
    int N, M, i, j, indx1 = 0, indx2 = 0;
    cout << "Enter number of rows: ";
    cin >> N;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!" << endl;
        exit(0);
    }
    cout << "Enter number of columns: ";
    cin >> M;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!" << endl;
        exit(0);
    }
    double** arr = new double* [N];
    for (i = 0; i < N; i++)
    {
        arr[i] = new double[M];
        for (j = 0; j < M; j++)
        {
            cout << "Enter a[" << i << "]" << "[" << j << "]: ";
            cin >> arr[i][j];
            if (cin.fail())
            {
                cout << "Error. Enter a number, please!!!" << endl;
                exit(0);
            }
        }
    }
    cout << "\nArray: " << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    double maxValue = arr[0][0];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (arr[i][j] > maxValue)
            {
                maxValue = arr[i][j];
                indx1 = i;
                indx2 = j;
            }
        }
    }
    if (arr[indx1][indx2] != arr[0][0])
    {
    swap(arr[indx1][indx2], arr[0][0]);
    cout << endl << "New array: " << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    }
    else if (arr[indx1][indx2] == arr[0][0])
    {
        cout << endl << "New array: " << endl;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    system("pause");
    return 0;
}

