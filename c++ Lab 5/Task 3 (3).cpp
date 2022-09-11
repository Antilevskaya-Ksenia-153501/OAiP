#include <iostream>
using namespace std;
int** creation(int n, int m) 
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		matrix[i] = new int[m];
	}
	return matrix;
}
void initialization(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Enter a[" << i << j << "]: ";
			cin >> matrix[i][j];
			if (cin.fail())
			{
				cout << "Error.Enter a correct number,please!!!" << endl;
				exit(0);
			}
		}
	}
	return;
}
void output(int** matrix, int n, int m)
{
	cout << endl << "Matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	return;
}
void mean(int** matrix, int n, int m) 
{
	int sum = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			sum += matrix[i][j];
		}
	}
	cout << endl << "Arithmetic mean of elements: " << sum / (n * m) << endl;
	return;
}
void mean1(int* matrix, int n)
{
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += matrix[i];
	}
	cout << endl << "Arithmetic mean of elements of new matrix: " << sum1 / n  << endl;
	return;
}

int main()
{
	int n, m, count = 0;
	cout << "The program will create a new matrix from elements located in even columns of matrix and having an odd value, calculate the arithmetic mean of elements " << endl;
	cout << endl << "Enter number of rows: ";
	cin >> n;
	if (cin.fail() || n <= 0)
	{
		cout << "Error.Enter a correct number,please!!!" << endl;
		exit(0);
	}
	cout << "Enter number of columns: ";
	cin >> m;
	if (cin.fail() || m <= 0)
	{
		cout << "Error.Enter a correct number,please!!!" << endl;
		exit(0);
	}
	int** matrix1 = creation(n, m);
	initialization(matrix1, n, m);
	output(matrix1, n, m);
	mean(matrix1, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 0 && matrix1[i][j] % 2 == 1) 
			{
				count++;
			}
		}
	}
	int* matrix2 = new int[count];
	int count1 = 0;
	cout << endl << "New matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 0 && j != 0 && matrix1[i][j] % 2 == 1)
			{
				matrix2[count1] = matrix1[i][j];
				cout << matrix2[count1]<<"\t";
				count1++;
			}
		}
	}
	mean1(matrix2, count1);
	for (int i = 0; i < n; i++) 
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;
	delete[] matrix2;
	system("pause");
	return 0;
	
}

