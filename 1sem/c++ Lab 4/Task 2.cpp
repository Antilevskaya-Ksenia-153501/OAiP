#include <iostream>//variant 3
#include <stdlib.h>
using namespace std;

int main()
{
    int M, N, sum = 0;
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
    int** arr = new int* [N];
    for (int i = 0; i < N; i++)
    { arr[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
        cout << "Enter a[" << i << "]"<<"["<<j<<"]: ";
        cin >> arr[i][j];
        if (cin.fail())
        {
            cout << "Error. Enter a number, please!!!" << endl;
            exit(0);
        }
        }
    }
    cout << "\nArray: " << endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (N - j + 1 > i && arr[i][j] < 0)
                sum = sum + arr[i][j];
        }

    }
    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
    cout << "The sum of negative elements located above the secondary diagonal of the matrix: " << sum<< endl;
    system("pause");
    return 0;
}

    

