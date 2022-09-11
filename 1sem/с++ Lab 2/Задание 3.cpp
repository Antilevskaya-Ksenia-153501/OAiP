#include <iostream>
using namespace std;

int main() {
    double X, Y;
    cout << "Enter X: ";
    cin >> X;
    if (!cin.fail()) {
        cout << "Enter Y: ";
        cin >> Y;
        if (!cin.fail()) {

            X<Y ? cout << "MAX = " << Y << endl : X>Y ? cout << "MAX = " << X << endl : cout << "X and Y are equal" << endl;

        }
        else cout << "ERROR" << endl;
    }
    else cout << "ERROR" << endl;
    system("pause");
    return 0;
}


