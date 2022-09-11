#include <iostream>
using namespace std;

int main()
{
	double x, a, b, c;
	cout << "Enter x:";
	cin >> x;
	a = sin(x); 
	cout << "sin(x) = " << a<<endl;
	b = cos(x); 
	cout << "cos(x) = " << b<<endl;
	c = log(abs(x));
	cout << "ln(x) = " << c << endl;
	if (a < b && a < c)
		cout << "min = " << a<<endl;
	else if (b < a && b < c)
		cout << "min = " << b<<endl;
	else if (c < a && c < b)
		cout << "min = " << c<<endl;
	system("pause");
	return 0;

	
	

   
}

