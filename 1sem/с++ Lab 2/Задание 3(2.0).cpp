#include <iostream>
using namespace std;

	bool comparison(double X, double Y)
	{
		return(X > Y);
	}
	int main()
	{
		double X, Y;
		cout << "Enter X: ";
		cin >> X;
		cout << "Enter Y: ";
		cin >> Y;
		if (comparison(X, Y))
			cout << "MAX X= " << X<<endl;
		else
			cout << "MAX Y= " << Y<<endl;
		system("pause");
		return 0;
	}
		
   

