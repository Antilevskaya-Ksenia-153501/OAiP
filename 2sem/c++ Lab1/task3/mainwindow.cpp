#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDate>
#include "date.h"
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->line_birthday->setInputMask("99.99.9999");
    ui->line_add->setInputMask("99.99.9999");
    ui->button_add->setEnabled(false);
    ui->button_week_number->setEnabled(false);
    ui->button_duration->setEnabled(false);
    ui->button_is_leap->setEnabled(false);
    ui->button_previousday->setEnabled(false);
    ui->button_nextday->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_read_file_clicked()
{
    if(model)
    {
        model->clear();
        if (date)
        {
            delete[] date;
        }
        date = 0;
        amount = 0;
    }
    Read_from_file();
}

void MainWindow::Read_from_file()
{
    filePath = QFileDialog:: getOpenFileName(this, "Choose file", "C:\\Users\\Notebook\\Desktop\\Study\\c++ Labs 2 sem\\dates.txt", "Text File (*.txt)");

    QFile File(filePath);

    if (!File.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "Can not open the file. Try again");
        return;
        ui->button_add->setEnabled(true);
        ui->button_week_number->setEnabled(true);
        ui->button_duration->setEnabled(true);
        ui->button_is_leap->setEnabled(true);
        ui->button_previousday->setEnabled(true);
        ui->button_nextday->setEnabled(true);
    }
    else if (File.size() == 0)
    {
        QMessageBox::information(this, "ERROR", "The file is empty");
        return;
        ui->button_add->setEnabled(false);
        ui->button_week_number->setEnabled(false);
        ui->button_duration->setEnabled(false);
        ui->button_is_leap->setEnabled(false);
        ui->button_previousday->setEnabled(false);
        ui->button_nextday->setEnabled(false);
    }
    QTextStream stream(&File);
    QString string_date = stream.readLine();
    QStringList string_list = string_date.split(" ");
    QStringListIterator iterator(string_list);
    int i = 0;
    int j = 0;
    while(iterator.hasNext())
    { if(Date::IsInvalidDate(iterator.next()))
        {
            QString str = string_list.at(i);
            date = date->AddNewItem(date, amount);
            date[amount].day = str[0].digitValue() * 10 + str[1].digitValue();
            date[amount].month = str[3].digitValue() * 10 + str[4].digitValue();
            date[amount].year = str[6].digitValue() * 1000 + str[7].digitValue() * 100 + str[8].digitValue() * 10 + str[9].digitValue();
            amount++;
        }
        else
        {
            ++j;
        }
        i++;
    }
    File.close();
    if (date == 0)
    {
        QMessageBox::information(this, "ERROR", "There is no correct date in the file or file contains only spaces");
        return;
        ui->button_add->setEnabled(false);
        ui->button_week_number->setEnabled(false);
        ui->button_duration->setEnabled(false);
        ui->button_is_leap->setEnabled(false);
        ui->button_previousday->setEnabled(false);
        ui->button_nextday->setEnabled(false);
    }
    model = new QStandardItemModel(amount, 6, this);
    model->setHeaderData(0, Qt::Horizontal, "Date");
    model->setHeaderData(1, Qt::Horizontal, "Next day");
    model->setHeaderData(2, Qt::Horizontal, "Previous day");
    model->setHeaderData(3, Qt::Horizontal, "Leap year");
    model->setHeaderData(4, Qt::Horizontal, "Duration");
    model->setHeaderData(5, Qt::Horizontal, "Week number");
    ui->tableView->setModel(model);

    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, date[row].add_Date_to_Table());
    }
    ui->button_add->setEnabled(true);
    ui->button_week_number->setEnabled(true);
    ui->button_duration->setEnabled(true);
    ui->button_is_leap->setEnabled(true);
    ui->button_previousday->setEnabled(true);
    ui->button_nextday->setEnabled(true);
    if (j)
    {
        Write_to_file();
        QMessageBox::information(this, "ERROR", "There is incorrect data in the file. The file will be overwritten with the correct dates");
        return;
    }
}

void MainWindow::on_button_nextday_clicked()
{
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        Date next_day = date[row].NextDay();
        model->setData(index, next_day.add_Date_to_Table());
    }
}

void MainWindow::on_button_previousday_clicked()
{
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        Date previous_day = date[row].PreviousDay();
        if (previous_day.year == 0)
        {
            model->setData(index, "1 year BC");
            continue;
        }
    model->setData(index, previous_day.add_Date_to_Table());
    }
}

void MainWindow::on_button_is_leap_clicked()
{
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        bool is_leap = date[row].IsLeap();
        if (is_leap)
        {
            model->setData(index, "Year is leap");
        }
        else
        {
            model->setData(index,"Year isnt't leap");
        }
    }
}

void MainWindow::on_button_duration_clicked()
{
    QModelIndex index;
    for (int row = 0; row < model->rowCount() - 1; row++)
    {
        index = model->index(row, 4);
        int duration = date[row].Duration(date[row + 1]);
        model->setData(index, duration);
    }
    int lastRow = model->rowCount();
    index = model->index(lastRow - 1,4);
    model->setData(index, "There is no next date");
}

void MainWindow::on_button_ok_clicked()
{
    QString birthday = ui->line_birthday->text();
    if(Date::IsInvalidDate(birthday))
    {
        Date b_day;
        b_day.day = birthday[0].digitValue() * 10 +  birthday[1].digitValue();
        b_day.month = birthday[3].digitValue() * 10 +  birthday[4].digitValue();
        b_day.year = birthday[6].digitValue() * 1000 +  birthday[7].digitValue() * 100 +  birthday[8].digitValue() * 10 +  birthday[9].digitValue();

        Date cd;
        QDate current_day = QDate::currentDate();
        QString today = current_day.toString("dd.MM.yyyy");
        cd.day = today[0].digitValue() * 10 +  today[1].digitValue();
        cd.month = today[3].digitValue() * 10 +  today[4].digitValue();
        cd.year = today[6].digitValue() * 1000 +  today[7].digitValue() * 100 + today[8].digitValue() * 10 +  today[9].digitValue();

        if (cd.year > b_day.year && cd.month < b_day.month)
        {
            b_day.year = cd.year;
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year > b_day.year && cd.month > b_day.month)
        {
            b_day.year = cd.year + 1;
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year > b_day.year && cd.month == b_day.month && cd.day < b_day.day)
        {
            b_day.year = cd.year;
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year > b_day.year && cd.month == b_day.month && cd.day > b_day.day)
        {
            b_day.year = cd.year + 1;
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year < b_day.year)
        {
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year == b_day.year && cd.month == b_day.month && cd.day > b_day.day)
        {
            b_day.year = cd.year + 1;
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year == b_day.year && cd.month == b_day.month && cd.day < b_day.day)
        {
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
        else if (cd.year == b_day.year && cd.month == b_day.month && cd.day == b_day.day)
        {
            ui->label->setText(QString::number(cd.Duration(b_day)));
        }
    }
    else
    {
        QMessageBox::information(this, "ERROR", "The birthday date is incorrect");
        return;
    }
}

void MainWindow::on_button_week_number_clicked()
{
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        int w_n = date[row].WeekNumber();
        model->setData(index, w_n);
    }
}

void MainWindow::on_button_add_clicked()
{
     QString add_day = ui->line_add->text();
    if(Date::IsInvalidDate(add_day))
    {
        date = date->AddNewItem(date, amount);
        date[amount].day = add_day[0].digitValue() * 10 + add_day[1].digitValue();
        date[amount].month = add_day[3].digitValue() * 10 + add_day[4].digitValue();
        date[amount].year = add_day[6].digitValue() * 1000 + add_day[7].digitValue() * 100 + add_day[8].digitValue() * 10 + add_day[9].digitValue();
        int lastRow = model->rowCount();
        model->insertRow(lastRow);
        QModelIndex index;

        index = model->index(amount, 0);
        model->setData(index, date[amount].add_Date_to_Table());
        amount++;

        QFile File(filePath);
        if (File.open(QFile::WriteOnly | QFile:: Append))
        {
            QTextStream out(&File);
            out << " " << ui->line_add->text();
        }
        File.close();
    }
    else
    {
        QMessageBox::information(this, "ERROR","The date is incorrect");
        return;
    }
    ui->line_add->clear();
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString str = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
    int x = index.row();
    int y = index.column();
    if(Date::IsInvalidDate(str))
    {
        model->removeRow(x);
        int row = x;
        model->insertRow(row);
        if (y == 0)
        {
            date[x].day = str[0].digitValue() * 10 + str[1].digitValue();
            date[x].month = str[3].digitValue() * 10 + str[4].digitValue();
            date[x].year = str[6].digitValue() * 1000 + str[7].digitValue() * 100 + str[8].digitValue() * 10 + str[9].digitValue();
            model->setData(index, date[x].add_Date_to_Table());
        }
        QFile File(filePath);
        if (File.open(QFile::ReadWrite))
        {
            File.seek(x * 11);
            QTextStream out(&File);
            out << date[x].add_Date_to_Table();
        }
        File.close();
    }
    else
    {
        QMessageBox::information(this, "ERROR","The date is incorrect");
        model->setData(index, date[x].add_Date_to_Table());
        return;
    }
}

void MainWindow::Write_to_file()
{
    QFile File(filePath);
    if (!File.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "Can not open the file. Try again");
        return;
    }

    QTextStream stream(&File);
    for (int i = 0; i < amount; i++)
    {
        if (i == amount - 1)
        {
            stream << date[i].add_Date_to_Table();
        }
        else
        {
        stream << date[i].add_Date_to_Table() << " ";
        }
    }

    File.close();
}





