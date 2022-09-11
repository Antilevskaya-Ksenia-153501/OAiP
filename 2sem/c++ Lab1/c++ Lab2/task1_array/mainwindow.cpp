#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->line_country->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_team->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_surname->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_name->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_patronymic->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_play_number->setInputMask("9999");
    ui->line_age->setInputMask("D99");
    ui->line_height->setInputMask("D99");
    ui->line_weight->setInputMask("D99");
    ui->line_search_surname->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_search_height->setInputMask("D99");
    ui->line_search_weight->setInputMask("D99");

    ui->button_delete->setEnabled(false);
    ui->button_back->setEnabled(false);
    ui->button_add->setEnabled(false);
    ui->button_find_youngest->setEnabled(false);
    ui->button_search->setEnabled(false);
    ui->button_search1->setEnabled(false);
    ui->button_search2->setEnabled(false);
    ui->button_write_to_file->setEnabled(false);
    ui->comboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countComboBox()
{
    ui->comboBox->clear();
    for (int i = 1; i <= sportsman->count; i++)
    {
        ui->comboBox->addItem(QString::number(i));
    }
}

void MainWindow::Read_from_file()
{
    sportsman = new Sportsman();
    filePath = QFileDialog:: getOpenFileName(this,"Choose file", "C:\\Users\\Notebook\\Desktop\\Study\\c++ Labs 2 sem\\c++ Lab2\\task1_array.txt", "Text File (*.txt)");
    QFile File(filePath);
    if (!File.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "Can't open the file");
        return;
    }
    else if (File.size() == 0)
    {
        QMessageBox::information(this, "ERROR", "The file is empty");
        return;
    }
    QTextStream stream(&File);
    Human temp;
    while(!stream.atEnd())
    {
        stream >> temp.country >> temp.team >> temp.surname >> temp.name >> temp.patronymic >> temp.play_number >> temp.age >> temp.height >> temp.weight ;
        sportsman->Add(temp.country, temp.team, temp.surname, temp.name, temp.patronymic, temp.play_number, temp.age, temp.height, temp.weight);
    }
    File.close();
    model = new QStandardItemModel(sportsman->count, 9, this);
    model->setHeaderData(0, Qt::Horizontal, "Country");
    model->setHeaderData(1, Qt:: Horizontal, "Team");
    model->setHeaderData(2, Qt:: Horizontal, "Surname");
    model->setHeaderData(3, Qt:: Horizontal, "Name");
    model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(5, Qt:: Horizontal, "Play-number");
    model->setHeaderData(6, Qt:: Horizontal, "Age");
    model->setHeaderData(7, Qt:: Horizontal, "Height");
    model->setHeaderData(8, Qt:: Horizontal, "Weight");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, sportsman->person[row].country);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, sportsman->person[row].team);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, sportsman->person[row].surname);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, sportsman->person[row].name);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, sportsman->person[row].patronymic);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, sportsman->person[row].play_number);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 6);
        model->setData(index, sportsman->person[row].age);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 7);
        model->setData(index, sportsman->person[row].height);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 8);
        model->setData(index, sportsman->person[row].weight);
    }
    ui->button_back->setEnabled(false);
    ui->button_delete->setEnabled(true);
    ui->button_add->setEnabled(true);
    ui->button_find_youngest->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_search1->setEnabled(true);
    ui->button_search2->setEnabled(true);
    ui->button_write_to_file->setEnabled(true);
    ui->comboBox->setEnabled(true);
    countComboBox();
}

void MainWindow::on_button_read_from_file_clicked()
{
     if(model)
    {
        model->clear();
        if(sportsman)
        {
            delete sportsman;
        }
        sportsman = 0;
    }
    this->Read_from_file();
}


void MainWindow::on_button_add_clicked()
{
    if (Sportsman::verification(ui->line_country->text(), ui->line_team->text(), ui->line_surname->text(), ui->line_name->text(), ui->line_patronymic->text(), ui->line_play_number->text().toInt(),  ui->line_age->text().toInt(),  ui->line_height->text().toInt(),  ui->line_weight->text().toInt()))
    {
        sportsman->Add(ui->line_country->text(), ui->line_team->text(), ui->line_surname->text(), ui->line_name->text(), ui->line_patronymic->text(), ui->line_play_number->text().toInt(),  ui->line_age->text().toInt(),  ui->line_height->text().toInt(),  ui->line_weight->text().toInt());
        int lastRow = model->rowCount();
        model->insertRow(lastRow);
        QModelIndex index;
        index = model->index(sportsman->count-1, 0);
        model->setData(index, ui->line_country->text());
        index = model->index(sportsman->count-1, 1);
        model->setData(index, ui->line_team->text());
        index = model->index(sportsman->count-1, 2);
        model->setData(index, ui->line_surname->text());
        index = model->index(sportsman->count-1, 3);
        model->setData(index, ui->line_name->text());
        index = model->index(sportsman->count-1, 4);
        model->setData(index, ui->line_patronymic->text());
        index = model->index(sportsman->count-1, 5);
        model->setData(index, ui->line_play_number->text().toInt());
        index = model->index(sportsman->count-1, 6);
        model->setData(index, ui->line_age->text().toInt());
        index = model->index(sportsman->count-1, 7);
        model->setData(index, ui->line_height->text().toInt());
        index = model->index(sportsman->count-1, 8);
        model->setData(index, ui->line_weight->text().toInt());

        countComboBox();
        ui->line_country->clear();
        ui->line_team->clear();
        ui->line_surname->clear();
        ui->line_name->clear();
        ui->line_patronymic->clear();
        ui->line_play_number->clear();
        ui->line_age->clear();
        ui->line_height->clear();
        ui->line_weight->clear();
    }
    else
    {
        QMessageBox::information(this, "ERROR","The information is incorrect");
        return;
    }
}

void MainWindow::on_button_delete_clicked()
{
    if (sportsman->count != 0)
    {
        sportsman->Delete(ui->comboBox->currentText().toInt());
        delete model;
        model = 0;
        model = new QStandardItemModel(sportsman->count, 9, this);
        model->setHeaderData(0, Qt::Horizontal, "Country");
        model->setHeaderData(1, Qt:: Horizontal, "Team");
        model->setHeaderData(2, Qt:: Horizontal, "Surname");
        model->setHeaderData(3, Qt:: Horizontal, "Name");
        model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
        model->setHeaderData(5, Qt:: Horizontal, "Play-number");
        model->setHeaderData(6, Qt:: Horizontal, "Age");
        model->setHeaderData(7, Qt:: Horizontal, "Height");
        model->setHeaderData(8, Qt:: Horizontal, "Weight");
        ui->tableView->setModel(model);
        QModelIndex index;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 0);
            model->setData(index, sportsman->person[row].country);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 1);
            model->setData(index, sportsman->person[row].team);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 2);
            model->setData(index, sportsman->person[row].surname);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 3);
            model->setData(index, sportsman->person[row].name);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 4);
            model->setData(index, sportsman->person[row].patronymic);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 5);
            model->setData(index, sportsman->person[row].play_number);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 6);
            model->setData(index, sportsman->person[row].age);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 7);
            model->setData(index, sportsman->person[row].height);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 8);
            model->setData(index, sportsman->person[row].weight);
        }
        countComboBox();
    }
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString str = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
    int x = index.row();
    int y = index.column();
    if (y == 0 && str.size() <= 15 && str.size() > 0)
    {
        sportsman->person[x].country = str;
    }
    else if (y == 0 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The name of country can contain only 1 to 15 symbols");
        model->setData(index, sportsman->person[x].country);
        return;
    }
    else if (y == 1 && str.size() <= 15 && str.size() > 0)
    {
        sportsman->person[x].team = str;
    }
    else if (y == 1 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The name of team can contain only 1 to 15 symbols");
        model->setData(index, sportsman->person[x].team);
        return;
    }
    else if (y == 2 && str.size() <= 15 && str.size() > 0)
    {
        sportsman->person[x].surname = str;
    }
    else if (y == 2 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The surname can contain only 1 to 15 symbols");
        model->setData(index, sportsman->person[x].surname);
        return;
    }
    else if (y == 3 && str.size() <= 15 && str.size() > 0)
    {
        sportsman->person[x].name = str;
    }
    else if (y == 3 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The name can contain only 1 to 15 symbols");
        model->setData(index, sportsman->person[x].name);
        return;
    }
    else if (y == 4 && str.size() <= 15 && str.size() > 0)
    {
        sportsman->person[x].patronymic = str;
    }
    else if (y == 4 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The patronymic can contain only 1 to 15 symbols");
        model->setData(index, sportsman->person[x].patronymic);
        return;
    }
    else if (y == 5 && str.toInt() >= 0 && str.toInt() <= 1000)
    {
        sportsman->person[x].play_number = str.toInt();
    }
    else if (y == 5 && (str.toInt() < 0 || str.toInt() > 1000 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The play-number can contain only 0 to 1000 numbers");
        model->setData(index, sportsman->person[x].play_number);
        return;
    }
    else if (y == 6 && str.toInt() > 0 && str.toInt() <= 100)
    {
        sportsman->person[x].age = str.toInt();
    }
    else if (y == 6 && (str.toInt() <= 0 || str.toInt() > 100 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The age can contain only 1 to 100 numbers");
        model->setData(index, sportsman->person[x].age);
        return;
    }
    else if (y == 7 && str.toInt() > 0 && str.toInt() <= 200)
    {
        sportsman->person[x].height = str.toInt();
    }
    else if (y == 7 && (str.toInt() <= 0 || str.toInt() > 200 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The height can contain only 1 to 200 cm");
        model->setData(index, sportsman->person[x].height);
        return;
    }
    else if (y == 8 && str.toInt() > 0 && str.toInt() <= 120)
    {
        sportsman->person[x].weight = str.toInt();
    }
    else if (y == 8 && (str.toInt() <= 0 || str.toInt() > 120 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The weight can contain only 1 to 120 kg");
        model->setData(index, sportsman->person[x].weight);
        return;
    }
}

void MainWindow::on_button_search_clicked()
{
    int check = 0;
    Sportsman *temp = new Sportsman();
    for (int i = 0; i < sportsman->count; i++)
    {
        if (ui->line_search_surname -> text() == sportsman->person[i].surname)
        {
            temp->Add(sportsman->person[i].country, sportsman->person[i].team, sportsman->person[i].surname, sportsman->person[i].name, sportsman->person[i].patronymic, sportsman->person[i].play_number, sportsman->person[i].age, sportsman->person[i].height, sportsman->person[i].weight);
            ++check;
        }
    }
    if (check)
    {
        delete model;
        model = 0;
        model = new QStandardItemModel(temp->count, 9, this);
        model->setHeaderData(0, Qt::Horizontal, "Country");
        model->setHeaderData(1, Qt:: Horizontal, "Team");
        model->setHeaderData(2, Qt:: Horizontal, "Surname");
        model->setHeaderData(3, Qt:: Horizontal, "Name");
        model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
        model->setHeaderData(5, Qt:: Horizontal, "Play-number");
        model->setHeaderData(6, Qt:: Horizontal, "Age");
        model->setHeaderData(7, Qt:: Horizontal, "Height");
        model->setHeaderData(8, Qt:: Horizontal, "Weight");
        ui->tableView->setModel(model);
        QModelIndex index;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 0);
            model->setData(index, temp->person[row].country);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 1);
            model->setData(index, temp->person[row].team);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 2);
            model->setData(index, temp->person[row].surname);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 3);
            model->setData(index, temp->person[row].name);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 4);
            model->setData(index, temp->person[row].patronymic);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 5);
            model->setData(index, temp->person[row].play_number);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 6);
            model->setData(index, temp->person[row].age);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 7);
            model->setData(index, temp->person[row].height);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 8);
            model->setData(index, temp->person[row].weight);
        }
        ui->button_delete->setEnabled(false);
        ui->button_read_from_file->setEnabled(false);
        ui->button_back->setEnabled(true);
        ui->button_add->setEnabled(false);
        ui->button_find_youngest->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_search1->setEnabled(false);
        ui->button_search2->setEnabled(false);
        ui->button_write_to_file->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->line_search_surname ->clear();
        delete temp;
        QMessageBox::information(this, "Warning", "You can't modify data in this table(only in main table). Unpredictable behavior");
    }
    else
    {
        QMessageBox::information(this, "ERROR","There is no such sportsman");
        delete temp;
        ui->line_search_surname ->clear();
        return;
    }
}

void MainWindow::on_button_back_clicked()
{
    ui->button_delete->setEnabled(true);
    ui->button_read_from_file->setEnabled(true);
    ui->button_back->setEnabled(false);
    ui->button_add->setEnabled(true);
    ui->button_find_youngest->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_search1->setEnabled(true);
    ui->button_search2->setEnabled(true);
    ui->button_write_to_file->setEnabled(true);
    ui->comboBox->setEnabled(true);
    delete model;
    model = 0;
    model = new QStandardItemModel(sportsman->count, 9, this);
    model->setHeaderData(0, Qt::Horizontal, "Country");
    model->setHeaderData(1, Qt:: Horizontal, "Team");
    model->setHeaderData(2, Qt:: Horizontal, "Surname");
    model->setHeaderData(3, Qt:: Horizontal, "Name");
    model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(5, Qt:: Horizontal, "Play-number");
    model->setHeaderData(6, Qt:: Horizontal, "Age");
    model->setHeaderData(7, Qt:: Horizontal, "Height");
    model->setHeaderData(8, Qt:: Horizontal, "Weight");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, sportsman->person[row].country);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, sportsman->person[row].team);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, sportsman->person[row].surname);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, sportsman->person[row].name);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, sportsman->person[row].patronymic);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, sportsman->person[row].play_number);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 6);
        model->setData(index, sportsman->person[row].age);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 7);
        model->setData(index, sportsman->person[row].height);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 8);
        model->setData(index, sportsman->person[row].weight);
    }
}


void MainWindow::on_button_search1_clicked()
{
    int check = 0;
    Sportsman *temp = new Sportsman();
    for (int i = 0; i < sportsman->count; i++)
    {
        if (ui->line_search_weight->text().toInt() <= sportsman->person[i].weight)
        {
            temp->Add(sportsman->person[i].country, sportsman->person[i].team, sportsman->person[i].surname, sportsman->person[i].name, sportsman->person[i].patronymic, sportsman->person[i].play_number, sportsman->person[i].age, sportsman->person[i].height, sportsman->person[i].weight);
            ++check;
        }
    }
    if (check)
    {
        delete model;
        model = 0;
        model = new QStandardItemModel(temp->count, 9, this);
        model->setHeaderData(0, Qt::Horizontal, "Country");
        model->setHeaderData(1, Qt:: Horizontal, "Team");
        model->setHeaderData(2, Qt:: Horizontal, "Surname");
        model->setHeaderData(3, Qt:: Horizontal, "Name");
        model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
        model->setHeaderData(5, Qt:: Horizontal, "Play-number");
        model->setHeaderData(6, Qt:: Horizontal, "Age");
        model->setHeaderData(7, Qt:: Horizontal, "Height");
        model->setHeaderData(8, Qt:: Horizontal, "Weight");
        ui->tableView->setModel(model);
        QModelIndex index;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 0);
            model->setData(index, temp->person[row].country);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 1);
            model->setData(index, temp->person[row].team);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 2);
            model->setData(index, temp->person[row].surname);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 3);
            model->setData(index, temp->person[row].name);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 4);
            model->setData(index, temp->person[row].patronymic);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 5);
            model->setData(index, temp->person[row].play_number);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 6);
            model->setData(index, temp->person[row].age);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 7);
            model->setData(index, temp->person[row].height);
        }
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 8);
            model->setData(index, temp->person[row].weight);
        }
        ui->button_delete->setEnabled(false);
        ui->button_read_from_file->setEnabled(false);
        ui->button_back->setEnabled(true);
        ui->button_add->setEnabled(false);
        ui->button_find_youngest->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_search1->setEnabled(false);
        ui->button_search2->setEnabled(false);
        ui->button_write_to_file->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->line_search_weight ->clear();
        delete temp;
        QMessageBox::information(this, "Warning", "You can't modify data in this table(only in main table). Unpredictable behavior");
    }
    else
    {
        QMessageBox::information(this, "ERROR","There is no such sportsmen");
        delete temp;
        ui->line_search_surname ->clear();
        return;
    }
}

void MainWindow::on_button_search2_clicked()
{
    int size = sportsman->count;
    QString *teams = new QString[size];
    for (int i = 0; i < sportsman->count;i++)
    {
        teams[i] = sportsman->person[i].team;
    }

    for (int counter1 = 0; counter1 < size; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < size ; counter2++)
        {
            if ( teams[counter1] == teams[counter2] )
            {
                for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
                {
                    teams[counter_shift] = teams[counter_shift + 1];
                }
                size -= 1;
                if (teams[counter1] == teams[counter2])
                {
                    counter2--;
                }
            }
        }
    }
    Sportsman sportsman_teams[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sportsman->count; j++)
        {
            if (sportsman->person[j].team == teams[i])
            {
                sportsman_teams[i].Add(sportsman->person[j].country, sportsman->person[j].team, sportsman->person[j].surname, sportsman->person[j].name, sportsman->person[j].patronymic, sportsman->person[j].play_number, sportsman->person[j].age, sportsman->person[j].height, sportsman->person[j].weight);
            }
        }
    }

    Sportsman *temp = new Sportsman();
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sportsman_teams[i].count; j++)
        {
            if (ui->line_search_height->text().toInt() <= sportsman_teams[i].person[j].height)
            {
                ++check;
            }
        }
        if (check == sportsman_teams[i].count)
        {
            for (int k = 0; k < sportsman_teams[i].count; k++)
            {
                temp->Add(sportsman_teams[i].person[k].country, sportsman_teams[i].person[k].team, sportsman_teams[i].person[k].surname, sportsman_teams[i].person[k].name, sportsman_teams[i].person[k].patronymic, sportsman_teams[i].person[k].play_number, sportsman_teams[i].person[k].age, sportsman_teams[i].person[k].height, sportsman_teams[i].person[k].weight);
            }
        }
        check = 0;
    }
    if (temp->count == 0)
    {
        QMessageBox::information(this, "ERROR","There is no such teams");
        delete temp;
        return;
    }
    delete model;
    model = 0;
    model = new QStandardItemModel(temp->count, 9, this);
    model->setHeaderData(0, Qt::Horizontal, "Country");
    model->setHeaderData(1, Qt:: Horizontal, "Team");
    model->setHeaderData(2, Qt:: Horizontal, "Surname");
    model->setHeaderData(3, Qt:: Horizontal, "Name");
    model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(5, Qt:: Horizontal, "Play-number");
    model->setHeaderData(6, Qt:: Horizontal, "Age");
    model->setHeaderData(7, Qt:: Horizontal, "Height");
    model->setHeaderData(8, Qt:: Horizontal, "Weight");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, temp->person[row].country);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, temp->person[row].team);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, temp->person[row].surname);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, temp->person[row].name);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, temp->person[row].patronymic);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, temp->person[row].play_number);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 6);
        model->setData(index, temp->person[row].age);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 7);
        model->setData(index, temp->person[row].height);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 8);
        model->setData(index, temp->person[row].weight);
    }

    ui->button_delete->setEnabled(false);
    ui->button_read_from_file->setEnabled(false);
    ui->button_back->setEnabled(true);
    ui->button_add->setEnabled(false);
    ui->button_find_youngest->setEnabled(false);
    ui->button_search->setEnabled(false);
    ui->button_search1->setEnabled(false);
    ui->button_search2->setEnabled(false);
    ui->button_write_to_file->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->line_search_height ->clear();
    delete temp;
    QMessageBox::information(this, "Warning", "You can't modify data in this table(only in main table). Unpredictable behavior");
}

void MainWindow::on_button_find_youngest_clicked()
{
    int size = sportsman->count;
    QString *teams = new QString[size];
    for (int i = 0; i < sportsman->count;i++)
    {
        teams[i] = sportsman->person[i].team;
    }

    for (int counter1 = 0; counter1 < size; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < size ; counter2++)
        {
            if ( teams[counter1] == teams[counter2] )
            {
                for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
                {
                    teams[counter_shift] = teams[counter_shift + 1];
                }
                size -= 1;
                if (teams[counter1] == teams[counter2])
                {
                    counter2--;
                }
            }
        }
    }
    Sportsman sportsman_teams[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sportsman->count; j++)
        {
            if (sportsman->person[j].team == teams[i])
            {
                sportsman_teams[i].Add(sportsman->person[j].country, sportsman->person[j].team, sportsman->person[j].surname, sportsman->person[j].name, sportsman->person[j].patronymic, sportsman->person[j].play_number, sportsman->person[j].age, sportsman->person[j].height, sportsman->person[j].weight);
            }
        }
    }

    Sportsman *temp = new Sportsman();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sportsman_teams[i].count; j++)
        {
            sportsman_teams[i].average_age += sportsman_teams[i].person[j].age;
        }
        sportsman_teams[i].average_age = sportsman_teams[i].average_age / sportsman_teams[i].count;
    }
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (sportsman_teams[i].average_age < sportsman_teams[j].average_age)
            {
                ++check;
            }
        }
        if (check == size - 1)
        {
            for (int k = 0; k < sportsman_teams[i].count; k++)
            {
                temp->Add(sportsman_teams[i].person[k].country, sportsman_teams[i].person[k].team, sportsman_teams[i].person[k].surname, sportsman_teams[i].person[k].name, sportsman_teams[i].person[k].patronymic, sportsman_teams[i].person[k].play_number, sportsman_teams[i].person[k].age, sportsman_teams[i].person[k].height, sportsman_teams[i].person[k].weight);
            }
        }
         check = 0;
    }
    if (temp->count == 0)
    {
        QMessageBox::information(this, "ERROR","There is no such teams");
        delete temp;
        return;
    }
    delete model;
    model = 0;
    model = new QStandardItemModel(temp->count, 9, this);
    model->setHeaderData(0, Qt::Horizontal, "Country");
    model->setHeaderData(1, Qt:: Horizontal, "Team");
    model->setHeaderData(2, Qt:: Horizontal, "Surname");
    model->setHeaderData(3, Qt:: Horizontal, "Name");
    model->setHeaderData(4, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(5, Qt:: Horizontal, "Play-number");
    model->setHeaderData(6, Qt:: Horizontal, "Age");
    model->setHeaderData(7, Qt:: Horizontal, "Height");
    model->setHeaderData(8, Qt:: Horizontal, "Weight");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, temp->person[row].country);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, temp->person[row].team);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, temp->person[row].surname);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, temp->person[row].name);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, temp->person[row].patronymic);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, temp->person[row].play_number);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 6);
        model->setData(index, temp->person[row].age);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 7);
        model->setData(index, temp->person[row].height);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 8);
        model->setData(index, temp->person[row].weight);
    }
    ui->button_delete->setEnabled(false);
    ui->button_read_from_file->setEnabled(false);
    ui->button_back->setEnabled(true);
    ui->button_add->setEnabled(false);
    ui->button_find_youngest->setEnabled(false);
    ui->button_search->setEnabled(false);
    ui->button_search1->setEnabled(false);
    ui->button_search2->setEnabled(false);
    ui->button_write_to_file->setEnabled(false);
    ui->comboBox->setEnabled(false);
    delete temp;
    QMessageBox::information(this, "Warning", "You can't modify data in this table(only in main table). Unpredictable behavior");
}



void MainWindow::on_button_write_to_file_clicked()
{
    this->Write_to_file();
}

void MainWindow::Write_to_file()
{
    QFile File(filePath);
    if (!File.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "The path isn't correct");
        return;
    }

    QTextStream stream(&File);
    for (int i = 0; i < sportsman->count; i++)
    {
        stream <<" " << sportsman->person[i].country << " " << sportsman->person[i].team << " " << sportsman->person[i].surname << " " << sportsman->person[i].name << " " << sportsman->person[i].patronymic << " " << sportsman->person[i].play_number << " " << sportsman->person[i].age << " " << sportsman->person[i].height << " " << sportsman->person[i].weight;
    }

    File.close();
}

