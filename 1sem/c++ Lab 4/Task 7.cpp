#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k, i;
	cout << "Enter number: ";
	cin >> n;
	if (!cin.fail() && n > 0)
	{
		string str_n = to_string(n);
		k = str_n.size();
		cout << "Number of digits: " << k << endl;
		cout << "Enter i: ";
		cin >> i;
		if (!cin.fail() && i >= 0 && i <= k - 1)
		{
			cout << str_n[k - i - 1] << endl;
		}
		else cout << "Error!!! Enter i >= 0 and i < number of digits"<<endl;

	}
	else cout << "Error!!! Enter a number, that is gteater than 0"<<endl;
	system("pause");
	return 0;
}

