#include <iostream>
using namespace std;

int main()
{
	double Z, a, b, c, d;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;

		if (c >= d && a < d)
			cout << "Z = a + b/c = " << a + b / c << endl;
		else if (c < d && a >= d)
			cout << "Z = a - b/c =" << a - b / c << endl;
		else
			cout << "Z = 0"<<endl;
	system("pause");
	return 0;
}

