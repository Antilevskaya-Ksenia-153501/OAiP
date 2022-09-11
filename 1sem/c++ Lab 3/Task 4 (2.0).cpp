#include <iostream>
using namespace std;

int main()
{
    int n,sum;
    cout << "Enter number: ";
    cin >> n;
    if (!cin.fail())
    {
        if (n % 2 == 0)
        {
            sum = ((2 + n) / 2) * (n / 2);
        }
        if (n % 2 == 1)
        {
            sum = ((2 + n - 1) / 2) * ((n - 1) / 2);
        }
        cout << "The sum of even numbers in the range 1 to " << n << " : " << sum << endl;
    }
    else cout << "Enter number" << endl;
    system("pause");
    return 0;
}
