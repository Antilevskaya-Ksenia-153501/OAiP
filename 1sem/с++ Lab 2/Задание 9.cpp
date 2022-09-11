#include <iostream>
using namespace std;

int main()
{
	double x, y, z;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter z: ";
	cin >> z;
	(x < z + y && z < x + y && y < x + z) ? cout << "The triangle exists" << endl : cout << "The triangle does not exist" << endl;
	system("pause");
	return 0;
}

