#include<iostream>//Задание 4
#include<cmath>
using namespace std;
int main() {
	double h,t;
	cout << "Enter height in metres:";
	cin >> h;//Высота
	t = sqrt((2 * h) / 9.81);//Время падения
	cout << "The fall time in seconds:" << t;
	return 0;

}

