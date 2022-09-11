#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 100, n1, n2, n3, i = 1, p = 1000, p1, p2, p3, p4, k = 10000, k1, k2, k3, k4, k5, t = 100000, t1, t2, t3, t4, t5, t6;
	cout << "Pluperfect digital invariants less than 10^6 : ";
	while (i <= 9)
	{
		cout << i << " ";
		i++;
	}
	while (n <= 999)
	{
		n1 = n / 100;
		n2 = n / 10 % 10;
		n3 = n % 10;
		if (pow(n1, 3) + pow(n2, 3) + pow(n3, 3) == n)
			cout << n<<" ";
		n++;
	}
	while (p <= 9999)
	{
		p1 = p / 1000;
		p2 = p / 100 % 10;
		p3 = p % 100 / 10;
		p4 = p % 100 % 10;
		if (pow(p1, 4) + pow(p2, 4) + pow(p3, 4) + pow(p4, 4) == p)
			cout << p << " ";
		p++;
	}
	while (k <= 99999)
	{
		k1 = k / 10000;
		k2 = k / 1000 % 10;
		k3 = k / 100 % 10;
		k4 = k % 100 / 10;
		k5 = k % 10;
		if (pow(k1, 5) + pow(k2, 5) + pow(k3, 5) + pow(k4, 5) + pow(k5, 5) == k)
			cout << k << " ";
		k++;
	}
	while (t <= 999999)  
	{
		t1 = t / 100000;
		t2 = t / 10000 % 10;
		t3 = t / 1000 % 10;
		t4 = t % 1000 / 100;
		t5 = t % 100 / 10;
		t6 = t % 10;
		if (pow(t1, 6) + pow(t2, 6) + pow(t3, 6) + pow(t4, 6) + pow(t5, 6) + pow(t6, 6) == t)
			cout << t << " ";
		t++;
}
	system("pause");
	return 0;
}


