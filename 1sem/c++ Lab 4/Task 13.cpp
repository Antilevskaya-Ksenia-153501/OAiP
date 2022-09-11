#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int  N,sum = 0;
    cout << "Enter number of extension cords: ";
    cin >> N;
    if (cin.fail())
    {
        cout << "Error. Enter a number,please!!!" << endl;
        exit(0);
    }
    int* arr = new int[N];
    cout << "Enter number of sockets in each extension cords"<<endl;
    for (int i = 0; i < N; i++) 
    {
        cout << "Enter a[" << i << "]: ";
        cin >> arr[i];
        if (cin.fail())
        {
            cout << "Error. Enter a number,please!!!" << endl;
            exit(0);
        }
    }
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    cout << "The number of sockets is " << sum - (N - 1) << endl;
    delete[] arr;
    system("pause");
    return 0;

}

