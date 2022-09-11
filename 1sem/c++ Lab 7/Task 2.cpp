#include <iostream> // Variant 3
#include <string>
using namespace std;
string reverse(string s) // переворачивание строки в обратный порядок
{
	int length = s.size();
	int i, j;
	char temp;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

int main()
{
	string number;
	int decimalNumber = 0;
	cout << "The program will convert the number from reverse code to natural form(decimal)" << endl;
	cout << "Enter the reverse code of the number: ";
	cin >> number;
	for (int i = 0; i < number.size(); i++)
	{
		if (cin.fail() || (number[i] < 48 && number[i] > 49))
		{
			cout << "Error. Incorrect input. Try again, please" << endl;
			exit(0);
		}
	}
	if (number[0] == '1') // перевод в прямой код
	{
		for (int i = 1; i < number.size(); i++)
		{
			if (number[i] == '0') number[i] = '1';
			else if (number[i] == '1') number[i] = '0';
		}
	}
	number = reverse(number);
	for (int i = 0; i < number.size() - 1; i++) // перевод в естественную форму
	{
		if (number[i] >= 48 && number[i] <= 49)
		{
			decimalNumber += ((int)number[i] - 48) * pow(2, i);
		}
	}
	if (number[number.size() - 1] == '1')
	{
		cout << endl << "-" << decimalNumber;
	}
	else if (number[number.size() - 1] == '0')
	{
		cout << "The number in natural(decimal) form: " << decimalNumber << endl;
	}
	system("pause");
	return 0;

}

