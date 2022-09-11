#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double PI = 3.141592653589793;
    const double e = 2.718281828459045;
    int n, n1,f = 1;
    double x,y,sum = 0;
    cout << "Enter the number of members n: ";
    cin >> n;
    if (!cin.fail())
    {
        cout << "Enter x: ";
        cin >> x;
        if (!cin.fail())
        {
            if (x < 0.1 || x > 1)
                cout << "0.1 <= x <= 1" << endl;
            else
            {
                cout << "S(x) = ";
                for (n1 = 1; n1 <= n; n1++)
                {
                    f *= n1;
                    y = (double)(cos(n1 * PI / 4) * pow(x, n1)) / f;
                    cout << y << " ; ";
                    sum += y;
                }
                cout << "\ne^(x*cos (PI / 4)) * cos(x * sin(PI / 4)) = " << sum;
                cout << "\ne^(x*cos (PI / 4)) * cos(x * sin(PI / 4)) = " << pow(e, x * cos(PI / 4)) * cos(x * sin(PI / 4)) << endl;
            }
        }
        else cout << "Enter a number for x" << endl;
    }
    else cout << "Enter a number for n" << endl;
    system("pause");
    return 0;
    
}

