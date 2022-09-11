#include <iostream>//Задание 9 

using namespace std;

int main()
{
	double S, b1,q;
	cout << "Enter the first term of geometric progression:";
	cin >> b1;//Первый член прогрессии
	q =1./(3 + 1);//Знаменатель прогрессии
	cout << "The denominator of progression:" << q<<endl;
	S = b1 / (1 - q);//Сумма всех членов
	cout << "Sum of all terms:" << S;
	return 0;






}
