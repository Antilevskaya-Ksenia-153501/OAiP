#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int R, C;
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
	int** arr1 = new int* [R];
	for (int i = 0; i < R; i++)
	{
		arr1[i] = new int[C];
	}
	int** arr2 = new int* [R];
	for (int i = 0; i < R; i++)
	{
		arr2[i] = new int[C];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << "a[" << i << j << "]: ";
			cin >> arr1[i][j];
			if (cin.fail())
			{
				cout << "Error. Enter a number, please!!!" << endl;
				exit(0);
			}
		}
	}
	cout << "Array: " << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << arr1[i][j]<<"\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i - 1 < 0 && j - 1 < 0)
			{
				arr2[i][j] = arr1[i][j];
			}
			else if (i == 0 && j + 1 > C - 1)
			{
				if (arr1[i][j - 1] > arr1[i][j])
				{
					arr2[i][j] = arr1[i][j - 1];
				}
				else
				{
					arr2[i][j] = arr1[i][j];
				}
			}
			else if (i == 0)
			{
				if (arr1[i][j - 1] > arr1[i][j])
				{
					arr2[i][j] = arr1[i][j - 1];
				}
				else
				{
					arr2[i][j] = arr1[i][j];
				}
			}
			else if (j == 0 && i + 1 > R - 1)
			{
				if (arr1[i - 1][j] > arr1[i][j])
				{
					arr2[i][j] = arr1[i - 1][j];
				}
				else
				{
					arr2[i][j] = arr1[i][j];
				}
			}
			else if (j - 1 == 0)
			{
				if (arr1[i - 1][j] > arr1[i][j])
				{
					arr2[i][j] = arr1[i - 1][j];
				}
				else
				{
					arr2[i][j] = arr1[i][j];
				}
			}
			else if (arr1[i][j - 1] > arr1[i][j] && arr1[i][j - 1] > arr1[i - 1][j])
				{
					arr2[i][j] = arr1[i][j - 1];
				}
			else
				{
					if (arr1[i - 1][j] > arr1[i][j]  && arr1[i - 1][j] > arr1[i][j - 1])
					{
						arr2[i][j] = arr1[i - 1][j];
					}
					else
					{
						arr2[i][j] = arr1[i][j];
						
					}
				}
			
		}
	}
	cout << "New array:" << endl;
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
