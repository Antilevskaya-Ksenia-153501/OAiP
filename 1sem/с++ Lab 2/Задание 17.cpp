#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2, W, H, w, h, w1, h1;
    cout << "Enter height of room: ";
    cin >> H;
    cout << "Enter width of room: ";
    cin >> W;
    cout << "Enter the coordinates of the lower left corner of table 1\nx1 =  ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "Enter the coordinates of the upper right corner of table 1\nx2 =  ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;
    cout << "Enter the height of table 2: ";
    cin >> h;
    cout << "Enter the width of table 2: ";
    cin >> w;
    if (x1 >= 0 && x1 < x2 && x2 <= W && y1 >= 0 && y1 < y2 && y2 <= H && w >= 1 && w <= W && h >= 1 && h <= H)
        {
        h1 = y2 - y1;
        w1 = x2 - x1;
        if (w1 + w > W && h1 + h > H)
            cout << "Two tables will not fit into the room" << endl;
        else if (H - y2 >= h || y1 >= h)
            cout << "The second table fits without shifting" << endl;
        else if (H - y2 + y1 == h && H - y2 < y1)
            cout << "Min distance to move the first table: " << H - y2 << endl;
        else if (H - y2 + y1 == h && H - y2 >= y1)
            cout << "Min distance to move the first table: " << y1 << endl;
    }
    else cout << "ERROR" << endl;
    system("pause");
    return 0;
}

