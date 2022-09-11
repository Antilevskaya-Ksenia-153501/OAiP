#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Human
{
    string name;
    string surname;
    string patronymic;
    double math = 0;
    double physics = 0;
    double language = 0;
};

Human* AddStruct(Human* Student, const int amount)
{
    if (amount == 0)
    {
        Student = new Human[amount + 1];
    }
    else
    {
        Human* tempStudent = new Human[amount + 1];
        for (int i = 0; i < amount; i++)
        {
            tempStudent[i] = Student[i];
        }
        delete[] Student;
        Student = tempStudent;
    }
    return Student;
}

void initialization (Human* Student, const int amount)
{
    cout << "Surname: ";
    cin >> Student[amount].surname;
    cout << "Name: ";
    cin >> Student[amount].name;
    cout << "Patronymic: ";
    cin >> Student[amount].patronymic;
    cout << "Math's score: ";
    cin >> Student[amount].math;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    cout << "Physics's score: ";
    cin >> Student[amount].physics;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    cout << "Language's score: ";
    cin >> Student[amount].language;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
}

void output(const Human* Student, const int amount)
{
    ofstream file1;
    file1.open("Input.txt");
    if (!file1.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < amount; i++)
        {
            cout << "Surname: " << Student[i].surname << endl;
            file1 << "Surname: " << Student[i].surname ;
            cout << "Name: " << Student[i].name << endl;
            file1 << "Name: " << Student[i].name << endl;
            cout << "Patronymic: " << Student[i].patronymic << endl;
            file1 << "Patronymic: " << Student[i].patronymic << endl;
            cout << "Math: " << Student[i].math << endl;
            file1 << "Math: " << Student[i].math << endl;
            cout << "Physics: " << Student[i].physics << endl;
            file1 << "Physics: " << Student[i].physics << endl;
            cout << "Language: " << Student[i].language << endl;
            file1 << "Language: " << Student[i].language << endl;
            cout << "________________________________________________" << endl;
            file1 << "________________________________________________" << endl;
        }
    }
    file1.close();
}

double average_score(Human* Student, const int amount)
{
    double sum = 0;
    for (int i = 0; i < amount; i++)
    {
       
        sum += Student[i].math + Student[i].physics + Student[i].language;
    }
    sum = sum / 3;
    return sum / amount;
}

void sort(Human* Student, int amount, double average_score_uni)
{
    int min;
    string temp_name;
    string temp_surname;
    string temp_patronymic;
    double temp_math = 0;
    double temp_physics = 0;
    double temp_language = 0;
    for (int i = 0; i < amount - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < amount; j++)
        {
            if ((Student[j].math + Student[j].language + Student[j].physics) / 3 > (Student[min].math + Student[min].language + Student[min].physics) / 3)
                        min = j;
        }
        temp_name = Student[i].name; Student[i].name = Student[min].name; Student[min].name = temp_name;
        temp_surname = Student[i].surname; Student[i].surname = Student[min].surname; Student[min].surname = temp_surname;
        temp_patronymic = Student[i].patronymic; Student[i].patronymic = Student[min].patronymic; Student[min].patronymic = temp_patronymic;
        temp_math = Student[i].math; Student[i].math = Student[min].math; Student[min].math = temp_math;
        temp_physics = Student[i].physics; Student[i].physics = Student[min].physics; Student[min].physics = temp_physics;
        temp_language = Student[i].language; Student[i].language = Student[min].language; Student[min].language = temp_language;
    } 
    ofstream file2;
    file2.open("Output.txt");
    if (!file2.is_open())
    {
        cout << "Error. Plese,try again\n";
       
    }
    else
    {
        cout << "The list of enrollees, the average score of which above the university average:\n";
        file2 << "The list of enrollees, the average score of which above the university average:\n";
        for (int i = 0; i < amount; i++)
        {
            if ((Student[i].math + Student[i].language + Student[i].physics) / 3 > average_score_uni)
            {
                cout << Student[i].surname << endl;
                file2 << "Surname: " << Student[i].surname << endl;
            }
        }
    }
    file2.close();
}

void search(Human* Student, int amount, double average_score_uni)
{
    for (int i = 0; i < amount; i++)
    {
        if ((Student[i].math + Student[i].language + Student[i].physics) / 3 > average_score_uni)
        {
            cout << Student[i].surname << endl;
        }
    }
}

void edit(Human* Student, int amount)
{
    int change, num;
    cout << "What do you want to change?(1 - surname, 2 - name, 3 -patronymic, 4 - number of group, 5 - average score, 6 - income, 7 - all, 8 - nothing)";
    cin >> change;
    cout << "Enter a number of structure that you want to change: ";
    cin >> num;
    if (cin.fail() || num >= amount || num <= 0)
    {
        cout << "Error" << endl;
        exit(0);
    }
    switch (change)
    {
    case 1:
    {
        cout << "Enter new surname: ";
        cin >> Student[num - 1].surname;
        break;
    }
    case 2:
    {
        cout << "Enter new name: ";
        cin >> Student[num - 1].name;
        break;
    }
    case 3:
    {
        cout << "Enter new patronymic: ";
        cin >> Student[num - 1].patronymic;
        break;
    }
    case 4:
    {
        cout << "Enter new math mark: ";
        cin >> Student[num - 1].math;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    case 5:
    {
        cout << "Enter new physics mark: ";
        cin >> Student[num - 1].physics;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    case 6:
    {
        cout << "Enter new language mark: ";
        cin >> Student[num - 1].language;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    case 7:
    {
        cout << "Enter new surname: ";
        cin >> Student[num - 1].surname;
        cout << "Enter new name: ";
        cin >> Student[num - 1].name;
        cout << "Enter new patronymic: ";
        cin >> Student[num - 1].patronymic;
        cout << "Enter new math mark: ";
        cin >> Student[num - 1].math;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        cout << "Enter new physics mark: ";
        cin >> Student[num - 1].physics;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        cout << "Enter new language mark: ";
        cin >> Student[num - 1].language;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    default:
        cout << "Error. Plese,try again\n";    
        break;
    }
}

void remove (Human* Student, int& amount)
{
    int d;
    cout << "Enter index of structure that you want to delete: ";
    cin >> d;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    for (int i = d - 1; i < amount - 1; i++)
    {
        Student[i] = Student[i + 1];
    }
    amount--;
}

int main()
{
    double average_score_uni = 0;
    Human* Student = 0;
    int amount = 0;
    int yes_no = 0;
    do
    {
        Student = AddStruct(Student, amount);
        initialization (Student, amount);
        amount++;
        cout << "Countinue(1 - yes, 0 - no): ";
        cin >> yes_no;
        cout << endl;
    }
    while (yes_no);
    system("cls");
    cout << "Do you want to change anything?\n1) add;\n2) delete;\n3) edit;\n4) exit;\n";
    int c;
    cout << "Enter your choice: ";
    cin >> c;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    switch (c)
    {
    case 1: 
    {
        system("cls");
        do
        {
            Student = AddStruct(Student, amount);
            initialization(Student, amount);
            amount++;
            cout << "Countinue(1 - yes, 0 - no): ";
            cin >> yes_no;
            cout << endl;
        } 
        while (yes_no);
        average_score_uni = average_score(Student, amount);
        cout << "Average score in uni: " << average_score_uni << endl;
        output(Student, amount);
        sort(Student, amount, average_score_uni);
        break;
    }
    case 2:
    {
        remove(Student, amount);
        average_score_uni = average_score(Student, amount);
        cout << "Average score in uni: " << average_score_uni << endl;
        output(Student, amount);
        sort(Student, amount, average_score_uni);
        break;
    }
    case 3: 
    {
        edit(Student, amount);
        average_score_uni = average_score(Student, amount);
        cout << "Average score in uni: " << average_score_uni << endl;
        output(Student, amount);
        sort(Student, amount, average_score_uni);
        break;
    }
    case 4:
    {
        average_score_uni = average_score(Student, amount);
        cout << "Average score in uni: " << average_score_uni << endl;
        output(Student, amount);
        sort(Student, amount, average_score_uni);
        break;
    }
    default:
        cout << "Error. Plese,try again\n";
        break;
    }
    delete[] Student;
    system("pause");
	return 0;
}

