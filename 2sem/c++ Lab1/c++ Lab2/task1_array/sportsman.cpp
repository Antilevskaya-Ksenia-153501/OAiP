#include "sportsman.h"

Sportsman::Sportsman()
{

}
bool Sportsman::verification(QString country, QString team, QString surname, QString name, QString patronymic,int play_number, int age,int height, int weight)
{
    if(country.size() <= 15 &&  team.size() <= 15 &&  surname.size() <= 15 && name.size() <= 15 && patronymic.size() <= 15 && 0 < play_number && play_number <= 1000 && 0 < age && age <= 100 && 0 < height  && height <= 200 && weight > 0 && weight <= 120)
    {
        return true;
    }
    return false;
}
Human *Sportsman::AddNewItem(Human *person, const int count)
{
    if (count == 0)
    {
        person = new Human[count + 1];
    }
    else
    {
        Human* tempPerson = new Human[count + 1];
        for (int i = 0; i < count; i++)
        {
            tempPerson[i] = person[i];
        }
        delete[] person;
        person = tempPerson;
    }
    return person;
}

Human &Sportsman::find_item(int position)
{
    int current = next[0];
    for (int i = 0; i < position; i++)
    {
        current = next[current];
    }
    return person[current - 1];
}

Human &Sportsman::operator[](int i)
{
    return find_item(i);
}

void Sportsman::Add(QString country, QString team, QString surname, QString name, QString patronymic, int play_number, int age, int height, int weight)
{
    person = AddNewItem(person,count);
    next[count] = count + 1;
    ++count;
    person[count - 1].country = country;
    person[count - 1].team = team;
    person[count - 1].surname = surname;
    person[count - 1].name = name;
    person[count - 1].patronymic = patronymic;
    person[count - 1].play_number = play_number;
    person[count - 1].age = age;
    person[count - 1].height = height;
    person[count - 1].weight = weight;
}

void Sportsman::Delete(int position)
{
    int current = next[0];
    for (int i = 0; i < position; i++)
    {
      current = next[current];
    }
    for (int i = position - 1; i < count - 1; i++)
    {
        person[i] = person[i + 1];
    }
    --count;
}
