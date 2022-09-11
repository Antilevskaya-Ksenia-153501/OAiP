#include <iostream> // Variant 3
using namespace std;

int substraction(int a, int b) //вычитание через побитовые операторы
{
    while (b)
    {
        int c = (~a) & b;
        a ^= b;
        b = c << 1;

    }
    return a;
}



int division (int a, int b) //деление через побитовые операторы
{
    int c = 1, result = 0;
    if (b == 0) return -1 ;
    while (b > 0 && b < a) 
    { 
        b <<= 1; c <<= 1; 
    }
    do
    {
    if (a >= b) 
    {   
        a = substraction(a, b);
        result += c; 
    }
        b >>= 1; c >>= 1;
    } 
    while (c);
    return a;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin>> n;
    if (cin.fail()) 
    {
        cout << "Error. Incorrect input. Try again, please";
        exit(0);
    }
    if (division(n, 7) == 0) 
    {
        cout << n << " divides by 7" << endl;
    }
    else cout << n << " does not divide by 7" << endl;
    if (division(n, 29) == 0)
    {
        cout << n << " divides by 29" << endl;
    }
    else cout << n << " does not divide by 29" << endl;
    if (division(n, 149) == 0)
    {
        cout << n << " divides by 149" << endl;
    }
    else cout << n << " does not divide by 149" << endl;
    system("pause");
    return 0;
}