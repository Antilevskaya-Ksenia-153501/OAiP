#include <iostream>
using namespace std;

int main()
{
    double n;
    int i =1, sum = 0;
    cout << "Enter number: ";
    cin >> n;
    if (!cin.fail())
    {
        while (i <= n)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
            i++;
        }
        cout << "The sum of even numbers in the range 1 to " << n << " : " << sum << endl;
    }
    else cout << "Error. Enter number"<<endl;
    system("pause");
    return 0;
}

