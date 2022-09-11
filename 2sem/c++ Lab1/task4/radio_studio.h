#ifndef RADIO_STUDIO_H
#define RADIO_STUDIO_H
#include<QString>
#include<QDate>

class Radio_studio
{
public:
   Radio_studio();
    QString product_group;
    QString product_brand;
    QString status;

    QString date1;
    QString date2;

    QDate date_1;
    QDate date_2;

    int date1_day = 0;
    int date1_month = 0;
    int date1_year = 0;

    int date2_day = 0;
    int date2_month = 0;
    int date2_year = 0;

    ~Radio_studio();

    Radio_studio* AddNewItem(Radio_studio* Studio, const int amount);
    void sort(Radio_studio* Studio, const  int amount);
    void converting_1(Radio_studio *Studio, const int amount);
    void converting_2(Radio_studio *Studio, const int amount);
    void condition(Radio_studio* Studio, const int amount);
    static bool IsInvalidDate(QString date);
    bool verification(Radio_studio Studio);
};

#endif // RADIO_STUDIO_H
