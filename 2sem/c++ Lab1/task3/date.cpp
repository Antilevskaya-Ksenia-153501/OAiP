#include "date.h"
#include <cmath>

Date::Date(int temp_day, int temp_month, int temp_year)
{
    day = temp_day;
    month = temp_month;
    year = temp_year;
}

Date::~Date()
{

}

Date *Date::AddNewItem(Date *date, const int amount)
{
    if (amount == 0)
    {
        date = new Date[amount + 1];
    }
    else
    {
        Date* tempDate = new Date[amount + 1];
        for (int i = 0; i < amount; i++)
        {
            tempDate[i] = date[i];
        }
        delete[] date;
        date = tempDate;
    }
    return date;
}

Date Date::NextDay()
{
    if (day == 31 && month == 12)
    {
        Date next_day(1, 1, year + 1);
        return next_day;
    }
    else if ((day == 28 && !IsLeap()) || (day == 29 && IsLeap()))
    {
        Date next_day(1, month + 1, year);
        return next_day;
    }
    else if (((day == 30 && month == 4) || (day == 30 && month == 6) || (day == 30 && month == 9) || (day == 30 && month == 11)) || ((day == 31 && month == 1)  || (day == 31 && month == 3)  || (day == 31 && month == 5)  || (day == 31 && month == 7)  || (day == 31 && month == 8) || (day == 31 && month == 10) || (day == 31 && month == 12))) // checking for the count of days in month
    {
        Date next_day(1, month + 1, year);
        return next_day;
    }
    else
    {
        Date next_day(day + 1, month, year);
        return next_day;
    }
}

Date Date::PreviousDay()
{
    if (day == 1 && month == 1)
    {
        Date previous_day(31, 12, year - 1);
        return previous_day;
    }
    else if (day == 1 && month == 3 && !IsLeap())
    {
        Date previous_day(28, month - 1, year);
        return previous_day;
    }
    else if (day == 1 && month == 3 && IsLeap())
    {
        Date previous_day(29, month - 1, year);
        return previous_day;
    }
    else if ((day == 1 && month == 5) || (day == 1 && month == 7) || (day == 1 && month == 10) || (day == 1 && month == 12))
    {
        Date previous_day(30, month - 1, year);
        return previous_day;
    }
    else if ((day == 1 && month == 1) || (day == 1 && month == 2) || (day == 1 && month == 4) || (day == 1 && month == 6) || (day == 1 && month == 8) || (day == 1 && month == 9) || (day == 1 && month == 11))
    {
        Date previous_day(31, month - 1, year);
        return previous_day;
    }
    else
    {
        Date previous_day(day - 1, month, year);
        return previous_day;
    }
}

bool Date::IsLeap()
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else return 0;
}

int Date::WeekNumber()
{
    int a = (14 - month)/12;
    int y =year + 4800 - a;
    int m = month + 12*a - 3;
    int JD = day + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    int d4 = (JD + 31741 - (JD % 7)) % 146097 % 36524 % 1461;
    int L = d4/1460;
    int d1 = ((d4 - L) % 365) + L;
    int WN = (d1/7) + 1;
    return WN;
}

int Date::Duration(Date date)
{
    int a1 = (14 - this->month)/12;
    int y1 = this->year + 4800 - a1;
    int m1 = this->month + 12 * a1 - 3;
    int  JDN1 = this->day + (int)((153 * m1 + 2)/5) + 365 * y1 + (int)(y1/4) - (int)(y1/100) + (int)(y1/400) - 32045;

    int a2 = (14 - date.month)/12;
    int y2 = date.year + 4800 - a2;
    int m2 = date.month + 12 * a2 - 3;
    int JDN2 = date.day + (int)((153 * m2 + 2)/5) + 365 * y2 + (int)(y2/4) - (int)(y2/100) + (int)(y2/400) - 32045;
    return abs(JDN2 - JDN1);
}

 bool Date::IsInvalidDate(QString date)
{
    if (date.size() == 10 && date[2] == '.' && date[5] == '.')
    {
        int day = date[0].digitValue() * 10 + date[1].digitValue();
        int month = date[3].digitValue() * 10 + date[4].digitValue();
        int year = date[6].digitValue() * 1000 + date[7].digitValue() * 100 + date[8].digitValue() * 10 + date[9].digitValue();
        int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int day1 = days[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            day1 += 1;
        }
        if ((year < 1) || (month < 0 || month >12) || (day < 0 || day > day1))
        {
            return false;
        }
        return true;
    }
    else return false;
}
QString Date::add_Date_to_Table()
{
    QString day1 = QString::number(day);
    QString month1 = QString::number(month);
    QString year1 = QString::number(year);
    if (day < 10)
    {
        day1 = '0' + QString::number(day);
    }
    if (month < 10)
    {
        month1 = '0' + QString::number(month);
    }
    if (year < 1000 && year >= 100)
    {
        year1 = '0' + QString::number(year);
    }
    else if (year < 100 && year >= 10)
    {
        year1 = "00" + QString::number(year);
    }
    else if (year < 10)
    {
        year1 = "000" + QString::number(year);
    }
    QString date1 = day1 + "." + month1 + "." + year1;
    return date1;
}







