#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 10, n1, n2;
	while (n <= 99) 
	{
		n1 = n / 10;
		n2 = n % 10;
		if (pow((n1 + n2), 3) == pow(n, 2))
		cout <<"A two-digit number with the property that the cube of sum of its digits is equal to the square of the number itself : "<< n<<endl;
		n++;
	}
	system("pause");
	return 0;
}

