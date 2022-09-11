#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    unsigned long long binary = 0, digital = 1 ;
    cout << "The program will calculate n-th smallest two decimal number in decimal submission"<< endl;
    cout << "Enter n: ";
    cin >> n;
    if (cin.fail()) 
    {
        cout << "Error. Incorrect input. Try again, please" << endl;
        exit(0);
    }
    while (digital <= 10000)
    {
        unsigned long long j = digital; // числа в десятичной системе
       for (int i = 0; j > 0; i++)
       {
           binary += (j % 2) * pow(10, i); // перевод чисел в двоичную систему
           j /= 2;
       }
       string b = to_string(binary); //  перевод чисел в строку
       string d = to_string(digital);
       if (b.find(d, 0) != -1)
       {
           n--;
       }
       b.clear();
       d.clear();
       if (n == 0) 
       {
           cout << "The n-th smallest two decimal number in decimal submission: " << digital << endl;
           break;
       }
       binary = 0;
       digital++;
    }
    system("pause");
    return 0;
}

