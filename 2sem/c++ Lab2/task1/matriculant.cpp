#include "matriculant.h"

Matriculant::Matriculant()
{
    head = tail = NULL;
    count = 0;
}

bool Matriculant::verification(QString surname, QString name, QString patronymic, int math, int physics, int language)
{
    if(surname.size() <= 15 &&  name.size() <= 15 &&  patronymic.size() <= 15 && 0 < math && math <= 10 && 0 < physics && physics <= 10 && 0 < language  && language <= 10)
    {
        return true;
    }
    return false;
}

void Matriculant::AddTail(QString surname, QString name, QString patronymic,int math, int physics,int language)
{
    Human* temp = new Human;
    temp->next = 0;
    temp->name = name;
    temp->surname = surname;
    temp->patronymic = patronymic;
    temp->math = math;
    temp->physics = physics;
    temp->language = language;
    temp->previous = tail;
    if(tail != 0)
    {
        tail->next = temp;
    }
    if(count == 0)
    {
        head = tail = temp;
    }
    else
        tail = temp;
    ++count;
}

void Matriculant::Average_score(Human *temp)
{
    double sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += temp->math + temp->physics + temp->language;
        temp->average_mark = sum / 3;
        sum = 0;
        temp = temp->next;
    }
}

Human *Matriculant::partition(Human *first, Human *last)
{
    Human *current = first;
    Human *location = first->previous;
    QString surname_temp;
    QString name_temp;
    QString patronymic_temp;
    int math_temp;
    int physics_temp;
    int language_temp;
    double average_mark_temp;
    while (current != nullptr && current != last)
    {
        if (current->average_mark >= last->average_mark)
        {
            if (location == nullptr)
            {
                location = first;
            }
            else
            {
                location = location->next;
            }
            surname_temp = current->surname;
            current->surname = location->surname;
            location->surname = surname_temp;

            name_temp = current->name;
            current->name = location->name;
            location->name = name_temp;

            patronymic_temp = current->patronymic;
            current->patronymic = location->patronymic;
            location->patronymic = patronymic_temp;

            math_temp = current->math;
            current->math = location->math;
            location->math = math_temp;

            physics_temp = current->physics;
            current->physics = location->physics;
            location->physics = physics_temp;

            language_temp = current->language;
            current->language = location->language;
            location->language = language_temp;

            average_mark_temp = current->average_mark;
            current->average_mark = location->average_mark;
            location->average_mark = average_mark_temp;
        }
        current = current->next;
    }
    if (location == nullptr)
    {
        location = first;
    }
    else
    {
        location = location->next;
    }
    surname_temp = last->surname;
    last->surname = location->surname;
    location->surname = surname_temp;

    name_temp = last->name;
    last->name = location->name;
    location->name = name_temp;

    patronymic_temp = last->patronymic;
    last->patronymic = location->patronymic;
    location->patronymic = patronymic_temp;

    math_temp = last->math;
    last->math = location->math;
    location->math = math_temp;

    physics_temp = last->physics;
    last->physics = location->physics;
    location->physics = physics_temp;

    language_temp = last->language;
    last->language = location->language;
    location->language = language_temp;

    average_mark_temp = last->average_mark;
    last->average_mark = location->average_mark;
    location->average_mark = average_mark_temp;
    return location;
}

void Matriculant:: quickSortByAverage_score(Human *first, Human *last)
{
    if (first != last && first != nullptr && last != nullptr && last->next != first)
    {
        Human* element = this->partition(first, last);
        if (element != nullptr)
        {
            this-> quickSortByAverage_score(element->next, last);
            this-> quickSortByAverage_score(first, element->previous);
        }
    }
}

void Matriculant::Delete(int position)
{
    int i = 1;
    Human* Del = head;
    while(i < position)
    {
        Del = Del->next;
        i++;
    }
    Human* PrevDel = Del->previous;
    Human* AfterDel = Del->next;
    if(PrevDel != 0 && count != 1)
    {
        PrevDel->next = AfterDel;
    }
    if(AfterDel != 0 && count != 1)
    {
        AfterDel->previous = PrevDel;
    }
    if(position == 1)
    {
        head = AfterDel;
    }
    if(position == count)
    {
        tail = PrevDel;
    }
    delete Del;
    --count;
}
