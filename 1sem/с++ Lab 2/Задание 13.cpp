#include <iostream>
using namespace std;
int main()
{
    double R, P, Q, d1, d2, a;
    cout << "Enter the radius of sphere:";
    cin >> R;
    cout << "Enter the side of rhombus: ";
    cin >> P;
    cout << "Enter acute angle in radians: ";
    cin >> Q;
    d1 = 2 * sin(Q / 2) * P;
    d2 = 2 * cos(Q / 2) * P;
    a = (d1 * d2) / (4 * P);
    if (R <= a)
        cout << "The sphere will pass through the rhomboos hole" << endl;
    else cout << "The sphere will not pass through the rhomboos hole" << endl;
    system("pause");
    return 0;
}