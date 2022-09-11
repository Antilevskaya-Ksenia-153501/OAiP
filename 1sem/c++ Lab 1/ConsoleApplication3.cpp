#include<iostream>//Задание 3
#include<cmath>
using namespace std;


int main()

{
	int x1, y1, x2, y2, x3, y3;
	double line1, line2, line3, p, S1, S2, S3, h1, h2, h3, m1, m2, m3, b1, b2, b3, r, R, S_r, S_R, C1, C2, P, angle1rad, angle2rad, angle3rad, angle1, angle2, angle3;
	cout << "Enter x1:";//Вводим координаты
	cin >> x1;
	cout << "Enter y1:";
	cin >> y1;
	cout << "Enter x2:";
	cin >> x2;
	cout << "Enter y2:";
	cin >> y2;
	cout << "Enter x3:";
	cin >> x3;
	cout << "Enter y3:";
	cin >> y3;

	line1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); //Ищем 1 сторону треугольника
	cout << "The first leg of triangle= " << line1 << endl;
	line2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));//Ищем 2 сторону треугольника
	cout << "The second leg of triangle= " << line2 << endl;
	line3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));//Ищем 3 сторону треугольника
	cout << "The third leg of triangle= " << line3 << endl;

	p = (line1 + line2 + line3) / 2;//Полупериметр треугольника
	S1 = sqrt((p * (p - line1) * (p - line2) * (p - line3)));//Площадь треугольника 1


	h1 = (2 * S1) / line1;//Ищем высоты треугольника
	cout << "The height1 of triangle= " << h1 << endl;
	h2 = (2 * S1) / line2;
	cout << "The height2 of triangle= " << h2 << endl;
	h3 = (2 * S1) / line3;
	cout << "The height3 of triangle= " << h3 << endl;

	m1 = 0.5 * sqrt(2 * pow(line2, 2) + 2 * pow(line3, 2) - pow(line1, 2));//Вычисляем медианы треугольника
	cout << "The median1 of triangle=  " << m1 << endl;
	m2 = 0.5 * sqrt(2 * pow(line1, 2) + 2 * pow(line3, 2) - pow(line2, 2));
	cout << "The median1 of triangle=  " << m2 << endl;
	m3 = 0.5 * sqrt(2 * pow(line2, 2) + 2 * pow(line1, 2) - pow(line3, 2));
	cout << "The median1 of triangle=  " << m3 << endl;


	b1 = (2 * sqrt(line2 * line3 * p * (p - line1))) / (line2 + line3);//Вычисляем биссектрисы треугольника
	cout << "The bisector1 of triangle= " << b1 << endl;
	b2 = (2 * sqrt(line1 * line3 * p * (p - line2))) / (line1 + line3);
	cout << "The bisector2 of triangle= " << b2 << endl;
	b3 = (2 * sqrt(line2 * line1 * p * (p - line3))) / (line2 + line1);
	cout << "The bisector3 of triangle= " << b3 << endl;

	S2 = 0.5 * h1 * line1;//Площадь треугольника 2

	r = sqrt(((p - line1) * (p - line2) * (p - line3)) / p);//Радиус вписанной окружности
	cout << "The inradius= " << r << endl;

	R = (line1 * line2 * line3) / (4 * S1);//Радиус описанной окружности
	cout << "The circumradius= " << R << endl;

	S_r = 3.14 * pow(r, 2);//Площадь вписанной окружности
	cout << "The area of incircle= " << S_r << endl;

	S_R = 3.14 * pow(R, 2);//Площадь описанной окружности
	cout << "The area of circumcircle= " << S_R << endl;

	C1 = 2 * 3.14 * r;//Длина вписанной окружности
	cout << "The lenght of incircle= " << C1 << endl;

	C2 = 2 * 3.14 * R;//Длина описанной окружности
	cout << "The lenght of circumcircle= " << C2 << endl;

	P = line1 + line2 + line3;//Периметр треугольника
	cout << "Perimeter of triangle= " << P << endl;

	cout << "The area of triangle= " << S1 << endl;

	angle1rad = acos((pow(line1, 2) - pow(line2, 2) - pow(line3, 2)) / (-2 * line2 * line3));//Расчёт углов в радианах
	cout << "The angle 1 in radian= " << angle1rad << endl;

	angle2rad = acos((pow(line2, 2) - pow(line1, 2) - pow(line3, 2)) / (-2 * line1 * line3));
	cout << "The angle 2 in radian= " << angle2rad << endl;

	angle3rad = acos((pow(line3, 2) - pow(line2, 2) - pow(line1, 2)) / (-2 * line2 * line1));
	cout << "The angle 3 in radian= " << angle3rad << endl;

	angle1 = angle1rad * 180 / 3.14;//Расчёт углов в градусах
	cout << "The angle 1=" << angle1 << endl;

	angle2 = angle2rad * 180 / 3.14;
	cout << "The angle 2=" << angle2 << endl;

	angle3 = angle3rad * 180 / 3.14;
	cout << "The angle 3=" << angle3 << endl;

	S3 = 0.5 * line1 * line2 * sin(angle3rad);//Площадь треугольника 3


	return 0;
}