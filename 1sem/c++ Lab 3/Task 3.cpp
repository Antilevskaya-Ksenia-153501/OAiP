#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.141592653589793;
	double x, y, B, H;
	int A, M, i;
	A = 0;
	M = 20;
	B = (double) PI / 2;
	H = (double) (B - A) / 20;
	cout << "The value of the function y = sin(x) - cos(x) on the segment [A;B] in points Xi = A + i * H, where H = (B - A) / M, M = 20, A = 0, B = PI/2, equals "<< endl;
	for (i = 0; i <= 20; i++)
	{
		x = (double) i * H;
		y = sin(x) - cos(x);
		cout << y << endl;
	}
	system("pause");
	return 0;
   
}

