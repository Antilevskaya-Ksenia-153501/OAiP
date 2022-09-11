#include <iostream>
#include<cmath>;

using namespace std;

int main(){
    double a, b, c,Y;
    int N;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter c:";
    cin >> c;
    cout << "Enter N:";
    cin >> N;
    if (!cin.fail()) {
        switch (N) {
        case 2: {
            cout << "Y = b*c-a^2 = " << b * c - pow(a, 2) << endl;
            break;
        }
        case 56: {
            cout << "Y = b*c = " << b * c << endl;
            break;
        }
        case 7: {
            cout << "Y =a^7+c = " << pow(a, 7) + c << endl;
            break;
        }
        case 3: {
            cout << "Y = a-c*b = " << a - c * b << endl;
            break;
        }
        default:
            cout << "Y = (a+b)^3 = " << pow(a + b, 3) << endl;
        }
    }
    else cout << "ERROR" << endl;
    system("pause");
    return 0;
}

