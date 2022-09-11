#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, count = 1,i,j = 1, i_n, j_n;
    cout << "Enter a number: ";
    cin >> n;
    if (cin.fail()) 
    {
        cout << "Error. Enter a number, please!!!!";
        exit(0);
    }
    int const N = 15; 
    int arr[N][N];
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = count;
    count++; i = 0;
    while (count <= pow(N, 2)) 
    {
        if (count == n) 
        {
            i_n = i;
            j_n = j;
        }
        if (j - 1 < 0)
        {
            arr[i][j] = count;
            count++; i = 0;
           
            while (arr[i][j] > 0)
            {
                j++;
            }
        }
        else if (arr[i][j - 1] > 0)
        {
            arr[i][j] = count;
            count++; i++;
        }
        else if (arr[i][j - 1] == 0)
        {
            arr[i][j] = count;
            count++; j--;
        }
    }
     cout << "Array:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Coordinates: " << i_n << " " << j_n << endl;
    system("pause");
    return 0;
}

