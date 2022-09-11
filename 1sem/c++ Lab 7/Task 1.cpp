#include <iostream> // Variant 3
#include <string>
#include <cmath>
using namespace std;

string reverse(string s)
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
    int digital = 0, num5 = 0;
    string num13;
    cout << "The program will convert numbers from thirteen to five notation system" << endl;
    cout << "Enter number in thirteen notation system: ";
    cin >> num13;
    num13 = reverse(num13);
    for (int i = 0; i < num13.size(); i++) // перевод в десятичную систему
    {
        if (num13[i] >= 48 && num13[i] <= 57) 
        {
            digital += ((int)num13[i] - 48) * pow(13, i);
        }
        else if (num13[i] == 65) 
        {
            digital += ((int)num13[i] - 55) * pow(13, i);
        }
        else if (num13[i] == 66)
        {
            digital += ((int)num13[i] - 55) * pow(13, i);
        }
        else if (num13[i] == 67)
        {
            digital += ((int)num13[i] - 55) * pow(13, i);
        }
    }
    for (int j = 0; digital > 0; j++)
    {
        num5 += (digital % 5) * pow(10, j); // перевод в пятеричную систему 
        digital /= 5;
    }
    cout << "The number in five notation system: " << num5 << endl;
    system("pause");
    return 0;
}

