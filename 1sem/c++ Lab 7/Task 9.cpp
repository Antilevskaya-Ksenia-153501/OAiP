#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, n3 = 0;
    cout << "The program will convert number to the three notation with 1,2,3" << endl;
    cout << "Enter number: ";
    cin >> n;
    if (cin.fail()) 
    {
        cout << "Error. Incorrect input. Try again, please";
        exit(0);
    }
    for (int j = 0; n > 0; j++)
    {
        n3 += (n % 3) * pow(10, j); // перевод в трoичную систему 
        n /= 3;
    }
    string num3 = to_string(n3); // перевод в строку
    int pos = num3.find("10");
    while (pos + 1) // перевод в троичную систему с 1,2,3
    {
        num3.replace(pos, 2, "03");
        pos = num3.find("10");
    }
    int pos1 = num3.find("20");
    while (pos1 + 1) 
    {
        num3.replace(pos1, 2, "13");
        pos1 = num3.find("20");
    }
    int pos2 = num3.find("30");
    while (pos2 + 1) 
    {
        num3.replace(pos2, 2, "23");
        pos2 = num3.find("30");
    }
    while (num3[0] == '0') 
    {
        num3.erase(0, 1);
    }
    cout << "Converted number: " << num3;
    system("pause");
    return 0;
}

