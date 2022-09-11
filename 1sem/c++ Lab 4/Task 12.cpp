#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int len;
	cout << "Enter lenght of array: ";
	cin >> len;
	if (cin.fail())
	{
		cout << "Error. Enter a number, please!!!" << endl;
		exit(0);
	}
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Enter a[" << i << "]: ";
		cin >> arr[i];
		if (cin.fail())
		{
			cout << "Error. Enter a number, please!!!" << endl;
			exit(0);
		}
	}
	cout << "Array:"<<endl;
	for (int i = 0; i < len; i++)
	{
		cout << "a["<<i<<"]:"<<arr[i]<<";\t";
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++) 
		{
			if (arr[i] == arr[j])
			{
				for (int k = j; k < len - 1; k++) 
				{
					arr[k] = arr[k + 1];
				}
				len--;
			}

		}
	}
	cout << "\nNew array:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "a[" << i << "]:" << arr[i] << ";\t";
	}
	delete [] arr;
	system("pause");
	return 0;
}

