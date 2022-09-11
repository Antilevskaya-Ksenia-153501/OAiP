#include "radio_studio.h"
#include <QMessageBox>

Radio_studio::Radio_studio()
{

}
Radio_studio::~Radio_studio()
{

}

void Radio_studio::condition(Radio_studio *Studio, const int amount)
{
    converting_1(Studio, amount);
    converting_2(Studio, amount);
    QDate cd = QDate::currentDate();
    for(int i = 0; i < amount; i++)
    {
        if (Studio[i].date_2.isValid() && Studio[i].date_1.isValid())
        {
        if(cd < Studio[i].date_2)
            Studio[i].status = " not completed";
        else if (cd > Studio[i].date_2)
            Studio[i].status = "completed";
        }
    }
}

bool Radio_studio::IsInvalidDate(QString date)
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

bool Radio_studio::verification(Radio_studio Studio)
{
    if(Studio.IsInvalidDate(Studio.date1) && Studio.IsInvalidDate(Studio.date2) && Studio.product_group.size() <= 10 && Studio.product_brand.size() <= 10)
    {
        return true;
    }
    return false;
}

Radio_studio *Radio_studio::AddNewItem(Radio_studio *Studio, const int amount)
{
    if (amount == 0)
    {
        Studio = new Radio_studio[amount + 1];
    }
    else
    {
        Radio_studio* tempStudio = new Radio_studio[amount + 1];
        for (int i = 0; i < amount; i++)
        {
            tempStudio[i] = Studio[i];
        }
        delete[] Studio;
        Studio = tempStudio;
    }

    return Studio;
}

void Radio_studio::sort(Radio_studio *Studio, int amount)
{
    converting_2(Studio, amount);
    int min;
    Radio_studio tempStudio;
    for (int i = 0; i < amount - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < amount; j++)
        {
            if (Studio[j].product_group[0] < Studio[min].product_group[0])
            min = j;
            else if (Studio[j].product_group[0] == Studio[min].product_group[0])
            {
                if (Studio[j].date_2 > Studio[min].date_2 )
                min = j;
            }

        }
    tempStudio = Studio[i]; Studio[i] = Studio[min]; Studio[min] = tempStudio;
    }
}

void Radio_studio::converting_2(Radio_studio *Studio, const int amount)
{
    for (int i = 0; i < amount; i++ )
    {
        Studio[i].date2_day = Studio[i].date2[0].digitValue() * 10 + Studio[i].date2[1].digitValue();
        Studio[i].date2_month = Studio[i].date2[3].digitValue() * 10 + Studio[i].date2[4].digitValue();
        Studio[i].date2_year = Studio[i].date2[6].digitValue() * 1000 + Studio[i].date2[7].digitValue() * 100 + Studio[i].date2[8].digitValue() * 10 + Studio[i].date2[9].digitValue();
    }
    for (int i = 0; i < amount; i++ )
    {
        Studio[i].date_2.setDate(Studio[i].date2_year,  Studio[i].date2_month, Studio[i].date2_day);
    }
}

void Radio_studio::converting_1(Radio_studio *Studio, int amount)
{
    for (int i = 0; i < amount; i++ )
    {
        Studio[i].date1_day = Studio[i].date1[0].digitValue() * 10 + Studio[i].date1[1].digitValue();
        Studio[i].date1_month = Studio[i].date1[3].digitValue() * 10 + Studio[i].date1[4].digitValue();
        Studio[i].date1_year = Studio[i].date1[6].digitValue() * 1000 + Studio[i].date1[7].digitValue() * 100 + Studio[i].date1[8].digitValue() * 10 + Studio[i].date1[9].digitValue();
    }
    for (int i = 0; i < amount; i++ )
    {
        Studio[i].date_1.setDate(Studio[i].date1_year,  Studio[i].date1_month, Studio[i].date1_day);
    }
}

