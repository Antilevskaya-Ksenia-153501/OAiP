#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "The program will calculate the amount of interesting numbers (S(x+1) < S(x))" << endl;
    cout << "Enter number: ";
    cin >> n;
    if (cin.fail()) 
    {
        cout << "Error. Incorrect input. Try again, please";
        exit(0);
    }
    cout << "The amout of interesting numbers: " << (n + 1) / 10 << endl;
    system("pause");
    return 0;
}

