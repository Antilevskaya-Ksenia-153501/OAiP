#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cout << "Enter X: ";
    cin >> X;
    if (!cin.fail()) {
        cout << "Enter Y: ";
        cin >> Y;
        if (!cin.fail()) {
            if (X > Y)
            {
                Y = 0;
                cout << "Y= " << Y << endl << "X= " << X <<endl;
            }
            if (Y > X)
            {
                X = 0;
                cout << "X= " << X << endl << "Y= " << Y <<endl;
            }
            else
            {
                X = 0; Y = 0;
                cout << "X= " << X << endl << "Y= " << Y <<endl;
            }
        }
        else cout << "ERROR" << endl;
    }
    else cout << "ERROR" << endl;
    double A, B, C,K;
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "Enter C: ";
    cin >> C;
    if (A > B && A > C)
    {
        cout << "The largest number A: " << A << endl;
        cout << "Enter K: ";
        cin >> K;
        A = A - K;
        cout << "A-K= " << A<<endl;
    }
     else if (B > A && B > C)
    {
        cout << "The largest number B: " << B << endl;
        cout << "Enter K: ";
        cin >> K;
        B = B - K;
        cout << "B-K= " << B<<endl;
    }
     else if (C > A && C > B)
    {
        cout << "The largest number C: " << C << endl;
        cout << "Enter K: ";
        cin >> K;
        C = C - K;
        cout << "C-K= " << C<<endl;
    }
    else cout << "ERROR"<<endl;
    system("pause");
    return 0;
}




