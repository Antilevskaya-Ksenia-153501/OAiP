#include <iostream>//Задание 8
using namespace std;

int main()
{
    double a1, a100,d,S;
    cout << "Enter a1: ";
    cin >> a1;
    cout << "Enter a100: ";
    cin >> a100;
    //a100=a1+99d
    d = (a100 - a1) / 99;
    cout << "Difference of arithmetic progression: " << d<<endl;
    S = ((2 * a1 + d * 12) / 2 )* 13;
    cout << "Sum of arithmetic progression: " << S;
    return 0;
    
}

