#include <iostream>
#include<cmath>
using namespace std;

int main() {

	double a, b, c, x1, x2, x3, x4, D,D1,D2, t1, t2,p,q,Q,a1,b1,a2,b2,angle;
	int choice;
	cout << "Choose type of equation for solving: 1) ax^4+bx^2+c=0, 2)ax^4+bx^3+cx^2+a=0 or 3)x^3+px+q=0\nEnter number of equation: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Solution for ax^4+bx^2+c=0\nEnter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter c: ";
		cin >> c;
		if (a == 0 && c > 0 && b > 0) cout << "Equation has no roots" << endl;
		else if (a == 0 && c < 0 && b < 0) cout << "Equation has no roots" << endl;
		else if (a == 0 && c < 0 && b > 0) {
			x1 = sqrt(-c / b);
			x2 = -sqrt(-c / b);
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		else if (a == 0 && c > 0 && b < 0) {
			x1 = sqrt(c / -b);
			x2 = -sqrt(c / -b);
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}

		else if (b == 0 && c > 0 && a > 0) cout << "Equation has no roots" << endl;
		else if (b == 0 && c < 0 && a < 0) cout << "Equation has no roots" << endl;
		else if (b == 0 && c < 0 && a > 0) {
			x1 = sqrt(sqrt(-c / a));
			x2 = -sqrt(sqrt(-c / a));
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		else if (b == 0 && c > 0 && a < 0) {
			x1 = sqrt(sqrt(c / -a));
			x2 = -sqrt(sqrt(c / -a));
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		else if (a == 0 && b == 0 && c == 0) cout << "All numbers";
		else if (a == 0 && b == 0) cout << "Equation has no roots";
		else if (a == 0 && c == 0) cout << "x1 = 0";
		else if (c == 0 && b == 0) cout << "x1 = 0";
		else {
			D = b * b - 4 * a * c;
			if (D < 0) cout << "Equation has no roots" << endl;
			else {
				t1 = (-b + sqrt(D)) / (2 * a);
				t2 = (-b - sqrt(D)) / (2 * a);
				if (t1 > 0)
				{
					x1 = sqrt(t1);
					x2 = -1 * sqrt(t1);
					cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
				}
				if (t2 > 0)
				{
					x3 = sqrt(t2);
					x4 = -1 * sqrt(t2);
					cout << "x3 = " << x3 << endl << "x4 = " << x4 << endl;
				}
				if (t2 < 0 && t1 < 0) cout << "Equation has no roots" << endl;
			}
		}
		break; 
	}

	case 2: {
		cout << "Solution for ax^4+bx^3+cx^2+a=0\nEnter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter c: ";
		cin >> c;
		if (a == 0) cout << "x1 = 0\n" << "x2 = " << -c / b;
		else if (a == 0 && b == 0 && c == 0) cout << "Equation has no roots";
		else if (a == 0 && b == 0) cout << "x1 = 0";
		else if (a == 0 && c == 0) cout << "x1 = 0";
		else if (c == 0 && b == 0) cout << "Equation has no roots";
		else if (b == 0)
		{
			D = c * c - 4 * a * a;
			if (D < 0) cout << "Equation has no roots" << endl;
			else {
				t1 = (-c + sqrt(D)) / (2 * a);
				t2 = (-c - sqrt(D)) / (2 * a);
				if (t1 > 0)
				{
					x1 = sqrt(t1);
					x2 = -1 * sqrt(t1);
					cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
				}
				if (t2 > 0)
				{
					x3 = sqrt(t2);
					x4 = -1 * sqrt(t2);
					cout << "x3 = " << x3 << endl << "x4 = " << x4 << endl;
				}
				if (t2 < 0 && t1 < 0) cout << "Equation has no roots" << endl;
			}
		}
		if (c == 0) cout << "Sorry,can not solve" << endl;
		else 
		{
		D = b * b - 4 * a * (c-2*a);//at2 + bt + c-2a = 0
		if (D >= 0)
		{
			t1 = (-b + sqrt(D)) / (2 * a);
			t2 = (-b - sqrt(D)) / (2 * a);
			D1 = t1 * t1 - 4;//x2+1-tx=0
			if (D1 >= 0)
			{
				x1 = (t1 + sqrt(D1)) / 2;
				x2 = (t1 - sqrt(D1)) / 2;
				cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
			}
			D2 = t2 * t2 - 4;
			if (D2 >= 0)
			{
				x3 = (t2 + sqrt(D2)) / 2;
				x4 = (t2 - sqrt(D2)) / 2;
				cout << "x3 = " << x3 << endl << "x4 = " << x4 << endl;
			}
		}
		}
			break;
	}
	case 3: {
		cout << "Solution for x^3+px+q=0\nEnter p: ";
		cin >> p;
		cout << "Enter q: ";
		cin >> q;
		if (p == 0) 
		{
			if (q > 0)
			cout << "x1 = " << -1*pow(q, 1.0 / 3.0)<<endl;
			else if (q < 0)
			cout << "x1 = " << pow(abs(q), 1.0 / 3.0)<<endl;
		}
		else if (q == 0) 
		{
			if (p >= 0) cout << "x1 = 0"<<endl;
			else if (p < 0)  cout << "x1 = 0\n"<<"x2 = "<<sqrt(abs(p))<<endl<<"x3 = " << -sqrt(abs(p))<<endl;
		}
		else if (q == 0 && p == 0) cout << "x1 = 0"<<endl;
		else
		{
			Q = pow(p / 3, 3) + pow(q / 2, 2);
			if (Q > 0)
			{
				a2 = (double)(-q / 2) + pow(Q, 0.5);
				a1 = pow(a2, 1.0 / 3.0);
				b2 = (double)(-q / 2) - pow(Q, 0.5);
				if (b2 < 0)
					b1 = -pow(abs(b2), 1.0 / 3.0);
				else if (b2 > 0)
					b1 = pow(b2, 1.0 / 3.0);
				x1 = a1 + b1;
				cout << "x1 = " << x1 << endl;
			}

			else if (Q == 0)
			{
				x1 = 2 * pow(-q / 2, 1.0 / 3.0);
				x2 = -2 * pow(-q / 2, 1.0 / 3.0);
				cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
			}
			else if (Q < 0)
			{
				if (q < 0)
				{
					angle = atan(sqrt(-Q) / (-0.5 * q));
				}
				else if (q > 0)
				{
					angle = atan(sqrt(-Q) / (-0.5 * q)) + 3.1415926;
				}
				x1 = 2 * sqrt(-p / 3) * cos(angle / 3);
				x2 = 2 * sqrt(-p / 3) * cos((angle + 6.2821852) / 3);
				x3 = 2 * sqrt(-p / 3) * cos((angle + 12.5663704) / 3);
				cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl << "x3 = " << x3 << endl;
			}
		}
		break;
	}
	default: cout << "Error" << endl;
		break;
	}
	 system("pause>0");
	return 0;
}


		

	





	



	











