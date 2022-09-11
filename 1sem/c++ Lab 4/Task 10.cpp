#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 4;
	int arr1[SIZE][SIZE];
	int arr2[SIZE][SIZE];
	int arr3[SIZE][SIZE];
	int n = 0;
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr1[i][j] = 1 + n;
			n++;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j || (i + j == SIZE - 1)) 
			{
				arr1[i][j] = 0;
			}
		}
	}
	n = SIZE*SIZE;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr2[i][j] = n;
			n--;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i != j && (i + j != SIZE - 1))
			{
				arr2[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
		arr3[i][j] = arr2[i][j] + arr1[i][j];
		}
	}
	cout << "Magical square of 4 order:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout<<arr3[i][j]<<"\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

