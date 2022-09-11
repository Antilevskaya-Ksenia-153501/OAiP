#include <iostream>
#include <string>
using namespace std;


struct Human
{
    string name;
    string surname;
    string patronymic;
    int number_group = 0;
    double average_score = 0;
    double income = 0;
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

void input(Human* Student, const int amount)
{
    cout << "Surname: ";
    cin >> (Student[amount].surname);
    cout << "Name: ";
    cin >> (Student[amount].name);
    cout << "Patronymic: ";
    cin >> Student[amount].patronymic;
    cout << "Number of group: ";
    cin >> Student[amount].number_group; 
    if (cin.fail()) 
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    cout << "Average score: ";
    cin >> Student[amount].average_score;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    cout << "Income: ";
    cin >> Student[amount].income;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    cout << "________________________________________________" << endl;
}

void output( Human* Student,  int amount) 
{
    for (int i = 0; i < amount; i++)
    {
        cout << "Surname: " << Student[i].surname << endl;
        cout << "Name: " <<  Student[i].name << endl;
        cout << "Patronymic: " << Student[i].patronymic << endl;
        cout << "Number of group: " << Student[i].number_group << endl;
        cout << "Average score: " << Student[i].average_score << endl;
        cout << "Income: " << Student[i].income << endl;
        cout << "________________________________________________" << endl;
    }
}
 
void sort(Human* Student, int amount) 
{
    int min;
    string temp_name;
    string temp_surname;
    string temp_patronymic;
    int temp_number_group = 0;
    double temp_average_score = 0;
    double temp_income = 0;
    for (int i = 0; i < amount - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < amount; j++)
        {
            if (Student[j].average_score < Student[min].average_score)
                min = j;
        }
        temp_name = Student[i].name; Student[i].name = Student[min].name; Student[min].name = temp_name;
        temp_surname = Student[i].surname; Student[i].surname = Student[min].surname; Student[min].surname = temp_surname;
        temp_patronymic = Student[i].patronymic; Student[i].patronymic = Student[min].patronymic; Student[min].patronymic = temp_patronymic;
        temp_number_group = Student[i].number_group; Student[i].number_group = Student[min].number_group; Student[min].number_group = temp_number_group;
        temp_average_score = Student[i].average_score; Student[i].average_score = Student[min].average_score; Student[min].average_score = temp_average_score;
        temp_income = Student[i].income; Student[i].income = Student[min].income; Student[min].income = temp_income;
    }
}
 
void search(Human* Student, int amount, double min_salary)
{
    cout << "The names of students with income per member families less than two min salaries: ";
    for (int i = 0; i < amount; i++)
    {
        if (2 * min_salary > Student[i].income)
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
        cout << "Enter new number of group: ";
        cin >> Student[num - 1].number_group;
        break;
    }
    case 5:
    {
        cout << "Enter new average score: ";
        cin >> Student[num - 1].average_score;
        break;
    }
    case 6:
    {
        cout << "Enter new income: ";
        cin >> Student[num - 1].income;
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
        cout << "Enter new number of group: ";
        cin >> Student[num - 1].number_group;
        cout << "Enter new average score: ";
        cin >> Student[num - 1].average_score;
        cout << "Enter new income: ";
        cin >> Student[num - 1].income;
        break;
    }
    default: 
        cout << "Error" << endl;
        break;
    }
}

void remove(Human* Student, int& amount)
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
    Human* Student = 0;
    int choice, num = 0;
    double min_salary = 0;
    cout << "Enter min salary: ";
    cin >> min_salary;
    cout << "How do you want to implement structure input? ( 1 - input of a predetermined number of structure, 2 - dialogue with the user about the need to continue, 3 - input to a specific element)" << endl;
    cin >> choice;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
    if (choice == 1)
    {
        cout << "Enter a number of structures: ";
        cin >> num;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        Human* Student = new Human[num];
        for (int i = 0; i < num; i++)
        {
            cout << "Surname: ";
            cin >> Student[i].surname;
            cout << "Name: ";
            cin >> Student[i].name;
            cout << "Patronymic: ";
            cin >> Student[i].patronymic;
            cout << "Number of group: ";
            cin >> Student[i].number_group;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            cout << "Average score: ";
            cin >> Student[i].average_score;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            cout << "Income: ";
            cin >> Student[i].income;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            cout << "________________________________________________" << endl;
        }
        system("cls");
        cout << "Functions for further work:\n1) content view function;\n2) function of deleting an element;\n3) function of editing an element;\n4) ordering of elements;\n5) function of adding an element\n6) exit;\n";
        int ch;
        cout << "Choice: ";
        cin >> ch;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);

            switch (ch)
            {
            case 1:
            {
                system("cls");
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 2:
            {
                system("cls");
                remove(Student, num);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 3:
            {
                system("cls");
                edit(Student, num);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 4:
            {
                system("cls");
                sort(Student, num);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 5:
            {
                system("cls");
                int yes_no = 0;
                do
                {
                    Student = AddStruct(Student, num);
                    input(Student, num);
                    num++;
                    cout << "Countinue(1 - yes, 0 - no): ";
                    cin >> yes_no;
                    cout << endl;
                } while (yes_no);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 6:
            {
                system("cls");
                exit(0);
                break;
            }

            default:
                cout << "Error. Plese, try again\n";
                break;
            }
        }
    }
         if (choice == 2)
        {
            int yes_no = 0;
            do
            {
                Student = AddStruct(Student, num);
                input(Student, num);
                num++;
                cout << "Countinue(1 - yes, 0 - no): ";
                cin >> yes_no;
                cout << endl;
            } while (yes_no);
            system("cls");
            cout << "Functions for further work:\n1) content view function;\n2) function of deleting an element;\n3) function of editing an element;\n4) ordering of elements;\n5) function of adding an element;\n6) exit;\n";
            int ch;
            cout << "Choice: ";
            cin >> ch;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            switch (ch)
            {
            case 1:
            {
                system("cls");
                output(Student, num);
                break;
            }
            case 2:
            {
                system("cls");
                remove(Student, num);
                output(Student, num);
                break;
            }
            case 3:
            {
                system("cls");
                edit(Student, num);
                output(Student, num);
                break;
            }
            case 4:
            {
                system("cls");
                sort(Student, num);
                output(Student, num);
                break;
            }
            case 5:
            {
                system("cls");
                int yes_no = 0;
                do
                {
                    Student = AddStruct(Student, num);
                    input(Student, num);
                    num++;
                    cout << "Countinue(1 - yes, 0 - no): ";
                    cin >> yes_no;
                    cout << endl;
                } while (yes_no);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 6:
            {
                system("cls");
                exit(0);
                break;

            }
            default:
                cout << "Error.Plese, try again\n";
                break;
            }
        }
         if (choice == 3)
        {
            int stop = 0;
            int number;
            cout << "Enter the ending group number: ";
            cin >> number;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            do
            {
                Student = AddStruct(Student, num);
                input(Student, num);
                if (Student[num].number_group == number)
                {
                    stop = 1;
                }
                num++;
            } while (stop != 1);
            system("cls");
            cout << "Functions for further work:\n1) content view function;\n2) function of deleting an element;\n3) function of editing an element;\n4) ordering of elements;\n5) function of adding an element;\n6) exit;\n";
            int ch;
            cout << "Choice: ";
            cin >> ch;
            if (cin.fail())
            {
                cout << "Error. Plese,try again\n";
                exit(0);
            }
            switch (ch)
            {
            case 1:
            {
                system("cls");
                output(Student, num);
                break;
            }
            case 2:
            {
                system("cls");
                remove(Student, num);
                output(Student, num);
                break;
            }
            case 3:
            {
                system("cls");
                edit(Student, num);
                output(Student, num);
                break;
            }
            case 4:
            {
                system("cls");
                sort(Student, num);
                output(Student, num);
                break;
            }
            case 5:
            {
                system("cls");
                int yes_no = 0;
                do
                {
                    Student = AddStruct(Student, num);
                    input(Student, num);
                    num++;
                    cout << "Countinue(1 - yes, 0 - no): ";
                    cin >> yes_no;
                    cout << endl;
                } while (yes_no);
                output(Student, num);
                search(Student, num, min_salary);
                break;
            }
            case 6:
            {
                system("cls");
                exit(0);

            }
            default:
                cout << "Error.Plese, try again\n";
                break;
            }
        }
        else
        {
            cout << "Error.Plese, try again\n";
            exit(0);
        }
        delete[] Student;
        system("pause");
        return 0;
}

