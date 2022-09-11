#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0,n,i,j,k;
	cout << "Enter n:";
	cin >> n;
	if (cin.fail())
	{
		cout << "Error. Enter a number, please!!!" << endl;
		exit(0);
	}
	int*** arr = new int** [n];
	for (i = 0; i < n; i++)
	{
		arr[i] = new int* [n];
		for (j = 0; j < n; j++)
		{
			arr[i][j] = new int[n];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				cout << "arr[" << i << "]" << "[" << j << "]" << "[" << k << "] = ";
				cin >> arr[i][j][k];
				if (cin.fail())
				{
					cout << "Error. Enter a number, please!!!" << endl;
					exit(0);
				}
			}
		} 
	}
	cout << endl;
	i = 0; j = 0; k = 0;
	while (i < n && j < n && k < n)
	{
		sum1 += arr[i][j][k];
		i++; j++; k++;
	}
	i = 0; j = n - 1; k = 0;
	while (i < n && j >= 0 && k < n)
	{
		sum2 += arr[i][j][k];
		i++; j--; k++;
	}
	i = 0; j = 0; k = n - 1;
	while (i < n && j < n && k >= 0)
	{
		sum3 += arr[i][j][k];
		i++; j++; k--;
	}
	i = 0; j = n - 1; k = n - 1;
	while (i < n && j >= 0 && k >= 0)
	{
		sum4 += arr[i][j][k];
		i++; j--; k--;
	}
	cout <<"The sum1 = " << sum1 << endl;
	cout <<"The sum2 = " << sum2 << endl;
	cout << "The sum3 = " << sum3 << endl;
	cout << "The sum4 = " << sum4 << endl;
	if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4)
	{
		cout << "The max sum is " << sum1 << endl;
	}
	else if (sum2 > sum1 && sum2 > sum3 && sum1 > sum4)
	{
		cout << "The max sum is " << sum2 << endl;
	}
	else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4)
	{
		cout << "The max sum is " << sum3 << endl;
	}
	else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3)
	{
		cout << "The max sum is " << sum4 << endl;
	}
	system("pause");
	return 0;
}

