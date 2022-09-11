#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cout << "Enter x: ";
	cin >> x;
	if (!cin.fail()) {
		cout << "Enter y: ";
		cin >> y;
		if (!cin.fail()) {
			if (x >= y)
			{
				x % y == 0 ? cout << "x divisible on y without remainder" << endl : cout << "x divisible on y with remainder" << endl;
			}
			else if (x < y)
			{
				if (y % x == 0)
					cout << "y divisible on x without remainder" << endl; //у делиться на х без остатка
				else
					cout << "y divisible on x with remainder" << endl; //у делиться на х с остатком
			}

		}
		else cout << "ERROR"<<endl;
	}
	else cout << "ERROR"<<endl;

	system("pause");
	return 0;
}
	




