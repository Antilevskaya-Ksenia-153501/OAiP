#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Эта программа,анализируя массив, состоящий из строк, выводит на экран количество слов женского, мужского и среднего рода\nВозможны ошибки!!! Программа не распознаёт слова мужского рода,заканчивающиеся на а!! После каждого слова ставьте пробел\n\n";
    system("chcp 1251");
    int count1 = 0, count2 = 0, count3 = 0;
    string str;
    cout << "Введите строку со словами: ";
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] == 'е' || str[i] == 'о') && str[i + 1] == ' ')
        {
            count1++;
        }
        if ((str[i] == 'а' || str[i] == 'я') && str[i + 1] == ' ')
        {
            count2++;
        }
        if ((str[i] == 'й' || str[i] == 'ь' || str[i] == 'б' || str[i] == 'в' || str[i] == 'г' || str[i] == 'д' || str[i] == 'ж' || str[i] == 'з' || str[i] == 'л' || str[i] == 'к' || str[i] == 'н' || str[i] == 'м' || str[i] == 'п' || str[i] == 'р' || str[i] == 'с' || str[i] == 'т' || str[i] == 'ф' || str[i] == 'ц' || str[i] == 'х' || str[i] == 'ч' || str[i] == 'ш') && str[i + 1] == ' ')
        {
            count3++;
        }
    }
    cout << "Средний род: " << count1<< endl;
    cout << "Женский род: " << count2 << endl;
    cout << "Мужской род: " << count3 << endl;
    system ("pause");
    return 0;
}

