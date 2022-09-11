#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, k, x1, y1;
    x1 = 0; y1 = 0;
    cout << "Enter k:";
    cin >> k;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    if (x >= 0 && x <= k && y >= 0 && y <= k && k > 0) {
        if (x <= k - x) {
            x1 = x;
        }
        if (x > k - x) {
            x1 = k - x;
        }
        if (y <= k - y) {
            y1 = y;
        }
        if (y >= k - y) {
            y1 = k - y;
        }
        if (x1 < y1) {
            cout <<"The smallest distance from a point lying inside a square to a side:"<< x1<<endl;
        }
        else {
            cout <<"The smallest distance from a point lying inside a square to a side:"<< y1<<endl;
        }
    }
    
    if (y > k && x < k && x > 0 && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << y - k<<endl;
    }
    else if (y<k && y > 0 && x>k && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << x - k<<endl;
    }
    if (y < 0 && x > 0 && x <= k && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << abs(y)<<endl;
    }
    else if (x < 0 && y>0 && y <= k && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << abs(x)<<endl;
    }
    if (x > k && y > k && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x - k, 2) + pow(y - k, 2))<<endl;
    }
    else if (x > k && y < 0  && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x - k, 2) + pow(y, 2))<<endl;
    }
    else if (x < 0 && y < 0 && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x, 2) + pow(y, 2))<<endl;
    }
    else if (x < 0 && y > k && k > 0) {
        cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x, 2) + pow(y - k, 2))<<endl;
    }




    if (x < 0 && x >= k && y < 0 && y >= k && k < 0) {
        if (x <= k - x) {
            x1 = x - k;
        }
        if (x > k - x) {
            x1 = abs(x);
        }
        if (y >= k - y) {
            y1 = abs(y);
        }
        if (y <= k - y) {
            y1 = y - k;
        }
        if (x1 < y1) {
            cout <<"The smallest distance from a point lying inside a square to a side:"<< x1<<endl;
        }
        else {
            cout <<"The smallest distance from a point lying inside a square to a side:"<< y1<<endl;
        }
    }
        if (y < 0 && y > k && x < k && k < 0) {
            cout <<"Point lies outside the square.The closest distance to the side of the square:"<< k - x<<endl;
        }
        else if (x < 0 && x > k && y < k && k < 0) {
            cout <<"Point lies outside the square.The closest distance to the side of the square:" << k - y<<endl;
        }
        if (y > 0 && x < 0 && x > k && k < 0) {
            cout << "Point lies outside the square.The closest distance to the side of the square:" << y << endl;
        }
        else if (y < 0 && x > 0 && y > k && k < 0) {
            cout << "Point lies outside the square.The closest distance to the side of the square:" << x << endl;
        }
        if (y < k && x < k && k < 0) {
           cout<< "Point lies outside the square.The closest distance to the side of the square:" <<sqrt(pow(x - k, 2) + pow(y - k, 2))<<endl;
        }
        else if (y > 0 && x < k && k < 0) {
            cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x - k, 2) + pow(y , 2))<<endl;
        }
        else if (x > 0 && y > 0 && k < 0) {
            cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x, 2) + pow(y, 2))<<endl;
        }
        else if (x < 0 && y < 0 && k < 0) {
            cout << "Point lies outside the square.The closest distance to the side of the square:" << sqrt(pow(x - k, 2) + pow(y , 2))<<endl;
        }
  
    system("pause");
    return 0;
}


