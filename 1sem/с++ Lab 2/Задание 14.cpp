#include <iostream>
using namespace std;

int main()
{
	double x, y, a, b, c;
	cout << "Enter the length of brick:";
	cin >> c;
	cout << "Enter the width of brick:";
	cin >> b;
	cout << "Enter the height of brick:";
	cin >> a;
	cout << "Enter the width of opening:";
	cin >> x;
	cout << "Enter the length of opening:";
	cin >> y;
	if ((a <= x && b <= y) || (a <= y && b <= x) || (b <= x && c <= y) || (b <= y && c <= x) || (a <= x && c <= y) || (a <= y && c <= x))
		cout << "The brick will go through opening"<<endl;
	else cout << "The brick will not go through opening"<<endl;
	system("pause");
	return 0;
}

