#include <iostream> // Variant 3
#include <string>
using namespace std;
string reverse(string s)
{
    int length = s.size();
    char temp;
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

void summarize(string a, string b) // сложение
{
    int sum1 = 0; string num;
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] >= 48 && a[i] <= 57 && b[i] >= 48 && b[i] <= 57)
        {
            sum1 += (int)a[i] - 48 + (int)b[i] - 48;
        }
        else if (a[i] >= 48 && a[i] <= 57 && b[i] >= 65 && b[i] <= 67)
        {
            sum1 += (int)a[i] - 48 + (int)b[i] - 55;

        }
        else if (a[i] >= 65 && a[i] <= 67 && b[i] >= 48 && b[i] <= 57)
        {
            sum1 += (int)a[i] - 55 + (int)b[i] - 48;

        }
        else if (a[i] >= 65 && a[i] <= 67 && b[i] >= 65 && b[i] <= 67)
        {
            sum1 += (int)a[i] - 55 + (int)b[i] - 55;
        }
        if (sum1 >= 13)
        {
            num += (sum1 + 35);
            if (i == b.size() - 1 && (int)a[b.size() - 1] + (int)b[b.size() - 1] >= 13) num += 49;
            else a[i + 1] += 1;
            sum1 = 0;
        }
        else if (sum1 == 10)
        {
            num += "A";
            sum1 = 0;
        }
        else if (sum1 == 11)
        {
            num += "B";
            sum1 = 0;
        }
        else if (sum1 == 12)
        {
            num += "C";
            sum1 = 0;
        }
        else if (sum1 < 10)
        {
            num += sum1 + 48;
            sum1 = 0;
        }
    }
    num = reverse(num);
    cout << "The sum of numbers:" << num << endl;
}

void substraction(string a, string b) // вычитание 
{
    int subs1 = 0; string num;
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] >= 48 && a[i] <= 57 && b[i] >= 48 && b[i] <= 57)
        {
            subs1 += (int)a[i] - (int)b[i];
            if (subs1 < 0)
            {
                subs1 = 0;
                subs1 += (int)a[i] - (int)b[i] + 13;
                if (a[i + 1] == 'A') b[i + 1] = '9';
                a[i + 1] -= 1;
            }
        }
        else if (a[i] >= 48 && a[i] <= 57 && b[i] >= 65 && b[i] <= 67)
        {
            subs1 += ((int)a[i] - 48) - ((int)b[i] - 55);
            if (subs1 < 0)
            {
                subs1 = 0;
                subs1 += ((int)a[i] - 48) - ((int)b[i] - 55) + 13;
                if (a[i + 1] == 'A') a[i + 1] = '9';
                else a[i + 1] -= 1;
            }
        }
        else if (a[i] >= 65 && a[i] <= 67 && b[i] >= 48 && b[i] <= 57)
        {
            subs1 += (int)a[i] - (int)b[i] - 7;
            if (subs1 < 0)
            {
                subs1 = 0;
                subs1 += (int)a[i] - (int)b[i] + 20;
                if (a[i + 1] == 'A') a[i + 1] = '9';
                a[i + 1] -= 1;
            }
        }
        else if (a[i] >= 65 && a[i] <= 67 && b[i] >= 65 && b[i] <= 67)
        {
            subs1 += (int)a[i] - (int)b[i];

            if (subs1 < 0)
            {
                subs1 = 0;
                subs1 += (int)a[i] - (int)b[i] + 13;
                if (a[i + 1] == 'A') a[i + 1] = '9';
                a[i + 1] -= 1;
            }
        }
        if (subs1 == 10)
        {
            num += "A";
            subs1 = 0;
        }
        else if (subs1 == 11)
        {
            num += "B";
            subs1 = 0;
        }
        else if (subs1 == 12)
        {
            num += "C";
            subs1 = 0;
        }
        else if (subs1 >= 0 && subs1 < 10)
        {
            num += subs1 + 48;
            subs1 = 0;
        }
    }
    num = reverse(num);
    cout << "The substraction of numbers: " << num << endl;
}

int main()
{
    string num1, num2,m;
    int sum = 0,ras = 0;
    cout << "The program will summarize and substract 13 notation numbers" << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    num1 = reverse(num1);
    num2 = reverse(num2);
    summarize(num1, num2);
    substraction(num1, num2);
    system("pause");
    return 0;
}

