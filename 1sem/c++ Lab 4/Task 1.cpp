#include <iostream>//variant 3
#include <stdlib.h>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of elements in a one - dimensional static array: ";
	cin >> k;
	if (cin.fail())
	{
		cout << "Error. Enter a number, please!!!" << endl;
		exit(0);
	}
	int* arr = new int[k];
	for (int i = 0; i < k; i++)
	{
		cout << "Enter a[" << i << "] : ";
		cin >> arr[i];
		if (cin.fail()) 
		{
			cout << "Error. Enter a number, please!!!"<<endl; 
			exit(0);
		}
	}
	cout << "Array elements:" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	int minValue = arr[0], idx1 = 0;
	int i;
	for (i = 0; i < k; i++)
	{
		if (arr[i] < minValue)
		{
			minValue = arr[i];
			idx1 = i;
		}
	}
	cout << "\nThe smallest number in an array = " << minValue << " ; " << " index: " << idx1 << endl;;
	int maxValue = arr[0], idx2 = 0;
	for (i = 0; i < k; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
			idx2 = i;
		}
	}
	cout << "The biggest number in an array = " << maxValue << " ; " << " index: " << idx2 << endl;
	swap(arr[idx1], arr[idx2]);
	cout << "\nNew array:" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	delete [] arr;
	system("pause");
	return 0;
}


