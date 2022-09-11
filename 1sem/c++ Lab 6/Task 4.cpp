#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "The program will change the string due to new rules in English\n\n";
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if ((tolower(str[i + 1]) == 'e' || tolower(str[i + 1] == 'i') || tolower(str[i + 1]) == 'y') && tolower(str[i]) == 'c')
        {
            str[i] = 's';
        }
        else if ((tolower(str[i + 1]) != 'e' || tolower(str[i + 1]) != 'i' || tolower(str[i + 1]) != 'y') && tolower(str[i]) == 'c')
        {
            str[i] = 'k';
        }
        else if (tolower(str[i]) == 'q' && tolower(str[i + 1]) != 'u')
        {
            str[i] = 'k';
        }
        else if (tolower(str[i]) == 'q' && tolower(str[i + 1]) == 'u')
        {
            str[i] = 'k'; str[i + 1] = 'v';
        }
        else if (tolower(str[i]) == 'x') 
        {
            str[i] = 'k';
            str.insert(i + 1, 1, 's');

        }
        else if (tolower(str[i]) == 'w')
        {
            str[i] = 'v';
        }
        else if (tolower(str[i]) == 'p' && tolower(str[i + 1]) == 'h')
        {
            str[i] = 'f'; str.erase(i + 1, 1);
        }
        else if (tolower(str[i]) == 'e' && tolower(str[i + 1]) == 'e')
        {
            str[i] = 'i'; str.erase(i + 1, 1);
        }
        else if (tolower(str[i]) == 't' && tolower(str[i + 1]) == 'h')
        {
            str[i] = 'z'; str.erase(i + 1, 1);
        }
        else if (tolower(str[i]) == 'o' && tolower(str[i + 1]) == 'o')
        {
            str[i] = 'u'; str.erase(i + 1, 1);
        }
        else if (tolower(str[i]) == 'y' && tolower(str[i + 1]) == 'o' && tolower(str[i + 2]) == 'u')
        {
            str[i] = 'u'; str.erase(i + 1, 2);
        }
    }
    for (int i = 0; i < str.size(); i++) 
    {
        if (str[i] == str[i + 1]) str.erase(i, 1);
    }
    cout << "New string: " << str << endl;
    system("pause");
    return 0;
    
}

