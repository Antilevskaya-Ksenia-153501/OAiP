#include <iostream> // Variant 3
#include <string>
using namespace std;

string convert(string s) // Перевод в обратный код
{
	if (s[0] == '1')
	{
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '0') s[i] = '1';
			else if (s[i] == '1') s[i] = '0';
		}
	}
	return s;
}

string sum(string s1, string s2) // Сложение в обратном коде
{ 
    int len1 = s1.size();
    int len2 = s2.size();
    string ls1 = len1 < len2 ? s1 : s2; // Выравнивание длины строк
    string ls2 = len1 < len2 ? s2 : s1;
    for (int i = ls1.size(); i < ls2.size(); ++i) ls1 = '0' + ls1;
    string result;
    int carry = 0;
    for (int i = ls2.size() - 1; i >= 0; --i) {
        int bit1 = ls1[i] - '0'; 
        int bit2 = ls2[i] - '0';
        char sum = (bit1 ^ bit2 ^ carry) + '0';
        result = sum + result;
        carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
    }
    if (carry) result = sum("1", result);
    return result;
}

int main()
{
    string num1, num2, result;
    cout << "The program will find the sum of binary numbers given in natural form. Perform the addition in reverse code." << endl <<"Answer express in additional code" << endl;
    cout << "Enter the first binary number: ";
    cin >> num1;
    for (int i = 0; i < num1.size(); i++)
    {
        if (cin.fail() || (num1[i] < 48 && num1[i] > 49))
        {
            cout << "Error. Incorrect input. Try again, please" << endl;
            exit(0);
        }
    }
    cout << "Enter the second binary number: ";
    cin >> num2;
    for (int i = 0; i < num2.size(); i++)
    {
        if (cin.fail() || (num2[i] < 48 && num2[i] > 49))
        {
            cout << "Error. Incorrect input. Try again, please" << endl;
            exit(0);
        }
    }
    num1 = convert(num1);
    num2 = convert(num2);
    result = sum(num1, num2);
    if (result[0] == '0') cout << "The number in additional code: " << result <<endl; // Вывод в дополнительном коде
    if (result[0] == '1') cout << "The number in additional code: " << sum(result, "1") << endl;
    system("pause");
	return 0;
}

