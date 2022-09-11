#include <iostream>
using namespace std;
// 1 ячейка - 1; 2 ячейка - 1,2,3; 3 ячейка - 5,6,7,8,9 и т.д.
// нумерается начинается с 0 строка, 0 столбец
int main()
{
    int n, i,a,x_min;
    cout << "Enter a number: ";
    cin >> n;
    if (cin.fail())
    {
        cout << "Error. Enter a number, please!!!!";
        exit(0);
    }
    a = 1;// количество ячеек в слое
    x_min = 1;//значение минимального элемента в слое
    i = 1;// слой
    while (n >= x_min + a) 
    {
        x_min += a;
        a += 2;
        i += 1;
    }
    //Пусть число n принадлежит i слою.Рассмотрим значение j = k−x_min + 1. На i слое заполняутся ровно i ячеек до того,начнутся заполнять клетки справа налево.Значит, если m≤i, то число n находится на j строке и i столбце.В противном случае число находится на i строке и(i−(j−i)) столбце.
    cout << "Cordinates: " << endl;
    int j = n - x_min + 1;
    if (j <= i)
        cout <<"Row: " << j - 1 << " " <<"Column: "<< i - 1 << endl;
    else cout <<"Row:"<< i - 1 << " " <<"Column: "<< (i - (j - i) - 1) << endl;
    system("pause");
    return 0;

}

