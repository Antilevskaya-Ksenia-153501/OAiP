#ifndef DATE_H
#define DATE_H
#include<QString>

class Date
{
public:
    Date(int temp_day = 0, int temp_month = 0, int temp_year = 0);
    ~Date();
    Date* AddNewItem(Date* date, const int amount);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    int WeekNumber();
    int Duration(Date date);
    static bool IsInvalidDate(QString date);
    QString add_Date_to_Table();
    int day, month, year;
};
#endif // DATE_H
