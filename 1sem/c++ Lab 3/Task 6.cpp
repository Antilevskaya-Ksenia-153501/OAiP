#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, f_x, min, step, root;
    int p;
    cout << "How many parts to divide the search area of the root: ";
    cin >> p;
    if (!cin.fail())
    {
        root = x = 0;
        min = abs(asin(x) - x + pow(x, 2) - 1);
        step = (1. - x) / p;
        cout << "Step of integration : " << step <<endl;
        for (int i = 0; i <= p; i++)
        {
            x += step;
            f_x = abs(asin(x) - x + pow(x, 2) - 1);
            if (f_x < min)
            {
                min = f_x;
                root = x;
            }
        }
        cout << "Min value |arcsin(x) - x + x^2 -1| = " << min << endl;
        cout << "x = " << root << endl;
    }
    else cout << "Enter a number" << endl;
    system("pause");
    return 0;

}

