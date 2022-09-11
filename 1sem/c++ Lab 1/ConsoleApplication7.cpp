#include <iostream>//Задание 7
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    b = a + b;
    cout << b <<endl;
    a = b - a;
    cout <<"a = " << a << endl;
    b = b - a;
    cout << "b = " << b;
    return 0;





    
}

