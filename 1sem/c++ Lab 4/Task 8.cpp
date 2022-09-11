#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int R,n = 0;// n - number of 0
    cout << "Enter number of elements of array: ";
    cin >> R;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!" << endl;
        exit(0);
    }
    int* arr = new int[R];
    for (int i = 0; i < R; i++)
    {
        cout << "a[" << i<< "]: ";
        cin >> arr[i];
        if (cin.fail())
        {
            cout << "Error. Enter a number, please!!!" << endl;
            exit(0);
        }

    }
    cout << endl;
    cout << "Array: " << endl;
    for (int i = 0; i < R; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    int min_value = arr[0], idx1 = 0;
    for (int i = 0; i < R; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
            idx1 = i; 
        }
    }
    cout << "Min value = " << min_value << endl << "index: [" << idx1 << "]" << endl;
    int max_value = arr[0], idx2 = 0;
    for (int i = 0; i < R; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
            idx2 = i;
        }
    }
    cout << "Max value = " << max_value << endl << "index: [" << idx2 << "]" << endl;
    cout << endl;
    cout << "New array: " << endl;
    for (int i = 0; i < R; i++)
    {
        if ((i > idx1 && i < idx2) || (i < idx1 && i > idx2))
        {
            arr[i] = 0;
            n++;
        }
        cout << arr[i] << "\t";
    }
    cout << endl;
    if (n >= R/2) 
    {
        cout << "New array without a[i] = 0: "<<endl;
        for (int i = 0; i < R; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
         cout << arr[i] << "\t";
        }

    }
    delete[] arr;
    system("pause");
    return 0;
}


