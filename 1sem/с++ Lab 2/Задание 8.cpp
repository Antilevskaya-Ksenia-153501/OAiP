#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	double a, b, z, x, y,f_x;
	const double PI = 3.14159265;
	int choice;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter z: ";
	cin >> z;

	if (z < 1)
	{
		x = z * z;
		cout << "x = z ^ 2" << endl;
	}
	else if (z >= 1) 
	{
		x = z + 1;
		cout << "x=z+1" << endl;
	}
	cout << "x= " << x << endl;
	cout << "Choose f(x): 1)2x, 2)x^3 or 3)x/3: ";
	cin >> choice;
	switch (choice) {
	case 1:
	{ 
		f_x = 2 * x;
		cout << "f(x)=2x= " <<f_x<< endl;
		y = (-1) * PI * f_x + a * (pow(cos(x * x * x), 2)) + b * (pow(sin(x * x), 3));
		cout << "y= " << y << endl;
		break;
	}
	case 2: 
	{
		f_x = pow(x, 3);
		cout<< "f(x)=x^3= " <<f_x<< endl;
		y = (-1) * PI * f_x + a * (pow(cos(x * x * x), 2)) + b * (pow(sin(x * x), 3));
		cout << "y= " << y << endl;
		break;
	}
	case 3: 
	{
		f_x = x / 3;
		cout << "f(x)=x/3= "<<f_x << endl;
		y = (-1)* PI* f_x + a * (pow(cos(x * x * x), 2)) + b * (pow(sin(x * x), 3));
		cout << "y= " << y << endl;
		break;
	}
	default: 
	{
		cout << "ERROR" << endl;
	}
	
	system("pause");
	return 0;
	}
   











}

