#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    string m;
    cout << "Какое количество грибов Вы нашли:1)целое или 2)дробное?\nВведите номер варианта:";
    cin >> n;
    switch (n) {
    case 1: {
        int K;
        cout << "Введите количество найденных грибов:";
        cin >> K;
        if (K >= 0) {
            if (K % 100 == 11 || K % 100 == 12 || K % 100 == 13 || K % 100 == 14)
                m = "ов";
            else if (K % 10 == 1)
                m = " ";
            else if (K % 10 == 2 || K % 10 == 3 || K % 10 == 4)
                m = "a";
            else m = "ов";
        cout << "Вы нашли " << K << " гриб" << m << endl;
    }
  
       if (K < 0)
           cout << "Вы съели слишком много грибов ..." << endl;
        break;
    }
    case 2: {
          double K1;
          cout << "Введите найденных количество грибов:";
          cin >> K1;
          if (K1 > 0)
            cout << "Вы нашли " << K1 << " грибa" << endl;
          if (K1 < 0)
            cout << "Вы съели слишком много грибов ..." << endl;
          break;
    }
    default : 
        cout << "Ошибка" << endl;
        break;
}
    system("pause");
    return 0;
}

