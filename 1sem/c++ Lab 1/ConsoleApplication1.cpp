/*Задание 1
(23x^3+69x^2+32x+8=y1
-23x^3+69x^-32x+8=y2
x^2=z 1 операция
x(23x^2+32)=a и (69x^2+8)=b
x(23z+32)=a 3  операции
69z+8=b 2 операции
у1=a+b 1 операция
y2=b-a 1 операция*/


#include <iostream>

using namespace std;

int main()
{
	double x,z,y1,y2,a,b;
		cout << "Enter x:";
		cin >> x;

		if (!cin.fail()) {
		z = x * x;
		a = x * (23 * z + 32);
		b = 69 * z + 8;
		y1 = a + b;
		y2 = b - a;
		cout << "23x^3 + 69x^2 + 32x + 8 = " << y1 << endl;
		cout << "-23x^3+69x^-32x+8= " << y2 << endl;
	}
	else cout << "Error" << endl;
	return 0;

	}

