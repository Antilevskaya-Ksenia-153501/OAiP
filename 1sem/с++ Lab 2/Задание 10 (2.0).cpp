#include <iostream>
using namespace std;

int main()
{
	double x, a, b, c;
	cout << "Enter x: ";
	cin >> x;
	a = x - ((x * x * x) / 6) + ((x * x * x * x * x) / 120) - ((x * x * x * x * x * x * x) / 5040) + ((x * x * x * x * x * x * x * x * x) / 362880); //sinx
	cout << "sinx = " << a<<endl;
	b = 1 - ((x * x) / 2) + ((x * x * x * x) / 24) - ((x * x * x * x * x * x) / 720) + ((x * x * x * x * x * x * x * x) / 40320); //cosx
	cout << "cosx = " << b<<endl;
	if (x >= 0)
	{
		c = (x - 1) - (((x - 1) * (x - 1)) / 2) + (((x - 1) * (x - 1) * (x - 1)) / 3) - (((x - 1) * (x - 1) * (x - 1) * (x - 1)) / 4) + (((x - 1) * (x - 1) * (x - 1) * (x - 1) * (x - 1)) / 5);
	cout << "ln|x| = " << c<<endl;
	}
	else if (x < 0)
	{
		c = (-x - 1) - (((-x - 1) * (-x - 1)) / 2) + (((-x - 1) * (-x - 1) * (-x - 1)) / 3) - (((-x - 1) * (-x - 1) * (-x - 1) * (-x - 1)) / 4) + (((-x - 1) * (-x - 1) * (-x - 1) * (-x - 1) * (-x - 1)) / 5);
		cout << "ln|x| = " << c<<endl;
	}
	if (a < b && a < c)
		cout << "min = " << a << endl;
	else if (b < a && b < c)
		cout << "min = " << b << endl;
	else if (c < a && c < b)
		cout << "min = " << c << endl;
	system("pause");
	return 0;
}


