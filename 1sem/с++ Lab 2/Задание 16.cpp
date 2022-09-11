#include <iostream>
using namespace std; 

int main()
{   
    double a, b,nok;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    nok = a * b;
    while (a != b)
    {
        if (a > b){
            a -= b;}
        else {
            b -= a;}
    }
   
   cout <<"The greatest common factor:"<< a <<endl;
   cout << "The greatest common multiple:" << nok / a;
   system("pause");
   return 0;
}

