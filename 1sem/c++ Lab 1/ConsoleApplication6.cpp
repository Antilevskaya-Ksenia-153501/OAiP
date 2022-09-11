#include <iostream>//Задание 6
using namespace std;

int main()
{	int h1, min1, h2, min2,h,min;
	cout << "Enter hour(h1) that the clock was showing when student began to solve programmes: ";
	cin >>h1;
	cout << "Enter minutes(min1) that the clock was showing when student began to solve programmes: ";
	cin >> min1 ;
	cout << "Enter hour(h1) that the clock was showing when student ended to solve programmes: ";
	cin >> h2;
	cout << "Enter minutes(min1) that the clock was showing when student ended to solve programmes: ";
	cin >> min2;
	if (min2 < min1)
	{
		h = h2 - h1 - 1;
		min = 60 + (min2 - min1);
		cout << "Student solved programme " << h << "hours" << min << "minutes";}
	else {
		h = h2 - h1;
		min = min2 - min1;
		cout << "Student solved programme " << h << "hours " << min << "minutes";
	
	}
	return 0;




}

