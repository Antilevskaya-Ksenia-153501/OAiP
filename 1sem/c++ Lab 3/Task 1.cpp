#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 1;
    double N,sum;
    sum = 0.0;
    while (i <= 30 )
    {
        if (i % 2 == 1)
        {
            N = (double) pow(i -i*i, 2);
            cout << N << endl;
        }
        else if (i % 2 == 0)
        {
            N = (double) pow((i / 2 - i * i * i), 2);
            cout << N << endl;
        }
        sum += N;
        i++;
    }
    cout << "N = (a1 + b1)^2 + (a2 + b2)^2 + ... (a30 + b30)^2 = " << sum << endl;
    system("pause");
    return 0;
}

