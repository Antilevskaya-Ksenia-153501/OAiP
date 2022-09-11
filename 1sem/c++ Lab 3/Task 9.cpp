#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,n1 = 1;
    double a,sum,a1;
    sum = 0.0;
    cout << "Enter the number of computed arguments n:";
    cin >> n;
    if (!cin.fail()) {
         while (n1 <= n)
            {
                cout << "Enter a" << n1 - 1 <<" : ";
                cin >> a;
                a1 = pow(2, n1 - 1) * pow(-1, n1 - 1) * a;
                sum += a1;
                n1++;
            }
            cout << "a0 - 2*a1 + 4*a2 - 8*a3 ... +2^(n-1)*(-1)^(n-1)*a(n-1) = " << sum <<endl;
        }
        else cout << "Enter number"<<endl;
    system("pause");
    return 0;
    
}

