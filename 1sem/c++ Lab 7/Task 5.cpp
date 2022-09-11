#include <iostream>
using namespace std;

int main()
{
    int decimalValue[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romanValue[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    int n;
    cout << "The program will convert decimal numbers to roman" << endl;
    cout << "Enter a decimal number: ";
    cin >> n;
    if (cin.fail()) 
    {
        cout << "Error. Incorrect input. Try again, please" << endl;
        exit(0);
    }
    for (int i = 0; i < 13; i++) 
    {
        while (n >= decimalValue[i])
        {
            result += romanValue[i];
            n = n - decimalValue[i];
        }
    }
    cout << "Roman number: " << result << endl;
    system("pause");
    return 0;
}


      


    

