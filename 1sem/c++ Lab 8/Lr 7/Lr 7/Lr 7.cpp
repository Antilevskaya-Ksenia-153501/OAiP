#include <iostream> // вариант 7
#include <string>
#include <fstream>
using namespace std;

struct Human
{
    string surname;
    int number_group = 0;
    int math = 0;
    int physics = 0;
    int informatics = 0;
    double average = 0;
};

Human* AddStruct(Human* Student, const int amount)// выделение памяти под структуры
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

void initialization(Human* Student, const int amount) // инициализация структур
{
    cout << "Surname: ";
    cin >> Student[amount].surname;
    cout << "Number of group: ";
    cin >> Student[amount].number_group;
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
    cout << "Informatic's score: ";
    cin >> Student[amount].informatics;
    if (cin.fail())
    {
        cout << "Error. Plese,try again\n";
        exit(0);
    }
}

void output(Human* Student, const int amount) // просмотр
{
    for (int i = 0; i < amount; i++)
    {
        cout << "Surname: " << Student[i].surname << endl;
        cout << "Number of group: " << Student[i].number_group << endl;
        cout << "Math: " << Student[i].math << endl;
        cout << "Physics: " << Student[i].physics << endl;
        cout << "Informatics: " << Student[i].informatics << endl;
        Student[i].average = (double)(Student[i].math + Student[i].informatics + Student[i].physics) / 3;
        cout << "Average score: " << Student[i].average << endl;
        cout << "________________________________________________" << endl;
    }
}


void sort_score(Human* Student, int amount) // сортировка студентов по среднему балу(по убыванию), сортировка выбором
{
    int min;
    Human tempStudent;
    for (int i = 0; i < amount - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < amount; j++)
        {
            if (Student[j].average > Student[min].average)
                min = j;
        }
        tempStudent = Student[i]; Student[i] = Student[min]; Student[min] = tempStudent;
    }
}
void sort_alphabet(Human* Student, int amount) // сортировка студентов алфавиту, сортировка выбором
{
    int min;
    Human tempStudent;
    for (int i = 0; i < amount - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < amount; j++)
        {
            if (Student[j].surname[0] < Student[min].surname[0])
                min = j;
        }
        tempStudent = Student[i]; Student[i] = Student[min]; Student[min] = tempStudent;
    }
}
void search(Human* Student, int amount) // решение индивидуального задания
{
    for (int i = 0; i < amount; i++)
    {
        if (Student[i].math >= 4 && Student[i].informatics >= 4)
        {
            cout << "Surname: " << Student[i].surname << endl;
            cout << "Number of group: " << Student[i].number_group << endl;
            cout << "Math: " << Student[i].math << endl;
            cout << "Physics: " << Student[i].physics << endl;
            cout << "Informatics: " << Student[i].informatics << endl;
            cout << "Average score: " << Student[i].average << endl;
            cout << "________________________________________________" << endl;
        }
    }
}

void edit(Human* Student, int amount) // редактирование
{
    int change, num;
    cout << "What do you want to change?(1 - surname, 2 - number of group, 3 - math score; 4 - physics score; 5 - informatics score)\nEnter your choice: ";
    cin >> change;
    cout << "Enter a number of structure that you want to change: ";
    cin >> num;
    if (cin.fail() || num > amount || num <= 0)
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
        cout << "Enter new number of group: ";
        cin >> Student[num - 1].number_group;
        break;
    }
    case 3:
    {
        cout << "Enter new math score: ";
        cin >> Student[num - 1].math;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    case 4:
    {
        cout << "Enter new physics score: ";
        cin >> Student[num - 1].physics;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        break;
    }
    case 5:
    {
        cout << "Enter new informatics score: ";
        cin >> Student[num - 1].informatics;
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

void remove(Human* Student, int& amount) // удаление 
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
    int amount = 0;
    ifstream file1;
    file1.open("Input.txt");
    if (!file1.is_open())
    {
        cout << "Error. Can not open the file" << endl;
    }
    else
    {
        cout << "The file is successfully opened and you can use the data from the file\n"; //Ivanov 124402 6 5 7 Sidorov 124404 6 8 9 Lapenko 1224403 7 4 9 Litvenko 1224401 8 7 8 — это информация, которая находится в файле
        int i = 0;
        while (!file1.eof())
        {
            Student = AddStruct(Student, amount);
            file1 >> Student[i].surname >> Student[i].number_group >> Student[i].math >> Student[i].physics >> Student[i].informatics;  
            amount++;
            i++;
        }
    }
    file1.close();
    int choice = 0;
    do 
    {
        cout << "What do you want  to do next?\n1) creation;\n2) review;\n3) addition;\n4) solving an individual task;\n5) editing;\n6) remove;\n7) sorting by grades\n8) sorting by surnames\n9) exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cout << "Error. Plese,try again\n";
            exit(0);
        }
        switch (choice)
        {
        case 1: 
        {
            system("cls");
            ofstream file2;
            file2.open("Output.txt");
            if (!file2.is_open())
            {
                cout << "Error. Can not open the file" << endl;
            }
            else
            {
                cout << "The file has been successfully created and data has been written to it\n";
                for (int i = 0; i < amount; i++)
                {
                    file2 << "Surname: " << Student[i].surname << endl;
                    file2 << "Number of group: " << Student[i].number_group << endl;    
                    file2 << "Math: " << Student[i].math << endl;
                    file2 << "Physics: " << Student[i].physics << endl;
                    file2 << "Informatics: " << Student[i].informatics << endl;
                    Student[i].average = (double)(Student[i].math + Student[i].informatics + Student[i].physics) / 3;
                    file2 << "Average score: " << Student[i].average << endl;
                    file2 << "________________________________________________" << endl;
                }
            }
            file2.close();
            break;
        }
        case 2:
        {
            system("cls");
            output(Student, amount);
            break;
        }
        case 3:
        {
            int yes_no = 0;
            system("cls");
            do
            {
                Student = AddStruct(Student, amount);
                initialization(Student, amount);
                amount++;
                cout << "Countinue(1 - yes, 0 - no): ";
                cin >> yes_no;
                cout << endl;
            } while (yes_no);
            cout << "If you want to see the result of the work, select the review function\n";
            break;
        }
        case 4:
        {
            system("cls");
            search(Student, amount);
            break;
        }
        case 5:
        {
            system("cls");
            edit(Student, amount);
            cout << "If you want to see the result of the work, select the review function\n";
            break;
        }
        case 6:
        {
            system("cls");
            remove(Student, amount);
            cout << "If you want to see the result of the work, select the review function\n";
            break;
        }
        case 7: 
        {
            system("cls");
            sort_score(Student, amount);
            cout << "If you want to see the result of the work, select the review function\n";
            break;
        }
        case 8:
        {
            system("cls");
            sort_alphabet(Student, amount);
            cout << "If you want to see the result of the work, select the review function\n";
            break;
        }
        case 9:
        {
            system("cls");
            cout << "Exit" << endl;
            exit(0);
        }
        default:
            cout << "Error. Plese,try again\n";
            break;
        }
    } while (choice != 9);
    delete[] Student;
    system("pause");
    return 0;
}
