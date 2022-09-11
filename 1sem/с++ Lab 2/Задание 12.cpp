#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2, r, R,a;
    setlocale(LC_ALL, "Russian");
    cout << "Введите координаты центра первой окружности.\nВведите x1:";
    cin >> x1;
    cout << "Введите y1:";
    cin >> y1;
    cout << "Введите координаты центра второй окружности.\nВведите x2:";
    cin >> x2;
    cout << "Введите y2:";
    cin >> y2;
    cout << "Введите радиус первой окружности: ";
    cin >> r;
    cout << "Введите радиус второй окружности: ";
    cin >> R;
    a = sqrt((pow((x2 - x1), 2)) + pow((y2 - y1), 2));
    if (a + r <= R)
    {
        cout << "Первая окружность попадает во второю окружность" << endl;
    }
    else if (a + R <= r)
    {
        cout << "Вторая окружность попадает в первую окружность" << endl;
    }
    else if (a <= r + R) 
    {
        cout << "Окружности пересекаются" << endl;
    }
    else cout << "Ни одно условие не выполнено";
    system("pause");
    return 0;
}
