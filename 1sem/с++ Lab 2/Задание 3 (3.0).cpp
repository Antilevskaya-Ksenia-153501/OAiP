#include <iostream>
using namespace std;

int main()
{
    double X, Y;
    bool A;
    cout << "Enter X: ";
    cin >> X;
    cout << "Enter Y: ";
    cin >> Y;
    if (X != Y)
    {
        A = X > Y;
        if (A)
            cout << "MAX = " << X << endl;
        else
            cout << "MAX = " << Y << endl;
    }
    else cout << "X and Y are equal"<<endl;
    system("pause");
    return 0;
}

