#ifndef MATRICULANT_H
#define MATRICULANT_H
#include<QString>

struct Human
{
    QString surname;
    QString name;
    QString patronymic;
    int math = 0;
    int physics = 0;
    int language = 0;
    double average_mark = 0;
    Human *next, *previous;
};

class Matriculant
{
public:
    Human *head = nullptr, *tail = nullptr;
    int count = 0;
    Matriculant();
    static bool verification(QString surname, QString name, QString patronymic,int math, int physics, int language);
    void AddTail(QString surname, QString name, QString patronymic,int math = 0, int physics = 0,int language = 0);
    Human *partition(Human* head, Human* tail);
    void quickSortByAverage_score(Human* head, Human* tail);
    void Delete(int position);
    void Average_score(Human* temp);
};

#endif // MATRICULANT_H
