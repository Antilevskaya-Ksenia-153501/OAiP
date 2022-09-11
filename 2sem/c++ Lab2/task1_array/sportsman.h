#ifndef SPORTSMAN_H
#define SPORTSMAN_H
#include<QString>

struct Human
{
    QString country;
    QString team;
    QString surname;
    QString name;
    QString patronymic;
    int play_number = 0;
    int age = 0;
    int height = 0;
    int weight = 0;
};

class Sportsman
{
public:
    double average_age = 0;
    int count = 0;
    int next[50];
    Human *person;
    Sportsman();
    static bool verification(QString country, QString team, QString surname, QString name, QString patronymic,int play_number, int age,int height, int weight);
    Human *AddNewItem(Human *person, const int count);
    Human& find_item(int position);
    Human& operator[](int i);
    void Add(QString country, QString team, QString surname, QString name, QString patronymic,int play_number, int age,int height, int weight);
    void Delete(int position);
};
#endif // SPORTSMAN_H
