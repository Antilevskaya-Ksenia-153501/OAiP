#include <iostream>
using namespace std;

int main()
{
	double a, r;
	const double PI = 3.14159265;
	cout << "Enter the side of square: ";
	cin >> a;
	cout << "Enter the radius of circle: ";
	cin >> r;
	if (a * a  > PI * r * r)
		cout << "The area of square is bigger than area of circle" << endl;
	else if (a * a  < PI * r * r)
		cout << "The area of circle is bigger than area of square" << endl;
	else cout << "The area of square is equal to area of circle";
	system("pause");
	return 0;
	}
