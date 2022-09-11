#include <iostream>
using namespace std;

int main()
{
	cout << "The program will replace each letter with its number in the alphabet\n\n";
	char str[100] = {};
	char* str1; 
	cout << "Your string: ";
	cin >> str;
	cout << "New string: ";
	for (str1 = str; *str1 != '\0'; str1++) 
	{
		if ((*str1 > 64 && *str1 < 91) || (*str1 > 96  && *str1 < 123))
		{
			cout <<" "<<(int)*str1 << " ";
		}
		else cout << *str1;
	}
	system("pause");
	return 0;
}

