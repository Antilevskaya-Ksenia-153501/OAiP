#include<iostream>//Задание 5
#include<cmath>

using namespace std;

int main()
{
	double t, a,v0,S;
	cout << "Enter time in sec: ";//Запрашиваем время на затраченный путь
	cin >> t;
	cout << "Enter acceleration in m/s^2: ";//Запрашиваем ускорение
	cin >> a;
	cout << "Enter initial velocity in m/s: ";//Запрашиваем начальную скорость
    cin >> v0;
	S = v0 * t + a * pow(t, 2)/ 2;//Путь,пройденный телом
	cout << "The distance covered= " << S;
	return 0;


}