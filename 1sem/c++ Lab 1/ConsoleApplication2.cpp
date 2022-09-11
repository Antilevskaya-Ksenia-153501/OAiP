#include <iostream>//2 задание
//Вариант 3
using namespace std;

int main()

{
    double Q, p, n, x, K, D;
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter K: ";
        cin >> K;
        cout << "Enter D: ";
        cin >> D;
        cout << "Enter p: ";
        cin >> p;
        cout << "Enter n: ";
        cin >> n;
        if (D * K == 0) {
            cout << "MISTAKE!!! K=!0 and D=!0" << endl;
        }
        else {
            Q = (pow(cos(x), 2) / (K * D)) + cos(x) * pow((p - n), 3);
            cout << "Q = (cosx^2/(K*D))+cosx*(p-n)^3 = " << Q;
        }
    
    return 0;
}



