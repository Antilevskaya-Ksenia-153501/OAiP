#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->line_surname->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_name->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_patronymic->setInputMask("AAAAAAAAAAAAAAA");
    ui->line_math_mark->setInputMask("99");
    ui->line_physics_mark->setInputMask("99");
    ui->line_language_mark->setInputMask("99");
    ui->line_search->setInputMask("AAAAAAAAAAAAAAA");
    ui->button_add->setEnabled(false);
    ui->button_search->setEnabled(false);
    ui->button_sort->setEnabled(false);
    ui->button_back->setEnabled(false);
    ui->button_delete->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->button_write_to_file->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countComboBox()
{
    ui->comboBox->clear();
    for (int i = 1; i <= person->count; i++)
    {
        ui->comboBox->addItem(QString::number(i));
    }
}

void MainWindow::on_button_read_file_clicked()
{
    if(model)
    {
        model->clear();
        if(person)
        {
            delete[] person;
        }
        person = 0;
    }
    this->Read_from_file();
}

void MainWindow::Read_from_file()
{
    int invalid_info = 0;
    person = new Matriculant();
    filePath = QFileDialog:: getOpenFileName(this,"Choose file", "C:\\Users\\Notebook\\Desktop\\Study\\c++ Labs 2 sem\\c++ Lab2\\task1.txt", "Text File (*.txt)");
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
        stream >> temp.surname >> temp.name >> temp.patronymic >> temp.math >> temp.physics >> temp.language;
        if (Matriculant::verification(temp.surname, temp.name, temp.patronymic, temp.math, temp.physics, temp.language))
        {
            person->AddTail(temp.surname, temp.name, temp.patronymic, temp.math, temp.physics, temp.language);
        }
        else
        {
           ++invalid_info;
        }
    }
    File.close();
    if (person->head == 0 && person->tail == 0)
    {
        QMessageBox::information(this, "ERROR", "The file is incorrect");
        return;
    }
    model = new QStandardItemModel(person->count, 6, this);
    model->setHeaderData(0, Qt::Horizontal, "Surname");
    model->setHeaderData(1, Qt:: Horizontal, "Name");
    model->setHeaderData(2, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(3, Qt:: Horizontal, "Math mark");
    model->setHeaderData(4, Qt:: Horizontal, "Physics mark");
    model->setHeaderData(5, Qt:: Horizontal, "Language mark");
    ui->tableView->setModel(model);
    QModelIndex index;
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, ptr->surname);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, ptr->name);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, ptr->patronymic);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, ptr->math);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, ptr->physics);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, ptr->language);
        ptr = ptr->next;
    }
    countComboBox();
    if (invalid_info && person->head != 0 && person->tail != 0)
    {
        QMessageBox::information(this, "ERROR", "There is incorrect information in the file");
        return;
    }
    ui->button_add->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_sort->setEnabled(true);
    ui->button_back->setEnabled(false);
    ui->button_delete->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->button_write_to_file->setEnabled(true);
}

void MainWindow::on_button_add_clicked()
{
    if (Matriculant::verification(ui->line_surname->text(), ui->line_name->text(), ui->line_patronymic->text(), ui->line_math_mark->text().toInt(), ui->line_physics_mark->text().toInt(), ui->line_language_mark->text().toInt()))
    {
        person->AddTail(ui->line_surname->text(), ui->line_name->text(), ui->line_patronymic->text(), ui->line_math_mark->text().toInt(), ui->line_physics_mark->text().toInt(), ui->line_language_mark->text().toInt());

        int lastRow = model->rowCount();
        model->insertRow(lastRow);
        QModelIndex index;
        index = model->index(person->count - 1, 0);
        model->setData(index, ui->line_surname->text());
        index = model->index(person->count - 1, 1);
        model->setData(index, ui->line_name->text());
        index = model->index(person->count - 1, 2);
        model->setData(index, ui->line_patronymic->text());
        index = model->index(person->count - 1, 3);
        model->setData(index, ui->line_math_mark->text().toInt());
        index = model->index(person->count - 1, 4);
        model->setData(index, ui->line_physics_mark->text().toInt());
        index = model->index(person->count - 1, 5);
        model->setData(index, ui->line_language_mark->text().toInt());

        countComboBox();
        ui->line_surname->clear();
        ui->line_name->clear();
        ui->line_patronymic->clear();
        ui->line_math_mark->clear();
        ui->line_physics_mark->clear();
        ui->line_language_mark->clear();
    }
    else
    {
        QMessageBox::information(this, "ERROR","The information is incorrect");
        return;
    }
}

void MainWindow::on_button_delete_clicked()
{
    if (person->count != 0)
    {
        person->Delete(ui->comboBox->currentText().toInt());

        delete model;
        model = 0;
        model = new QStandardItemModel(person->count, 6, this);
        model->setHeaderData(0, Qt::Horizontal, "Surname");
        model->setHeaderData(1, Qt:: Horizontal, "Name");
        model->setHeaderData(2, Qt:: Horizontal, "Patronymic");
        model->setHeaderData(3, Qt:: Horizontal, "Math mark");
        model->setHeaderData(4, Qt:: Horizontal, "Physics mark");
        model->setHeaderData(5, Qt:: Horizontal, "Language mark");
        ui->tableView->setModel(model);
        QModelIndex index;
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 0);
            model->setData(index, ptr->surname);
            ptr = ptr->next;
        }
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 1);
            model->setData(index, ptr->name);
            ptr = ptr->next;
        }
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 2);
            model->setData(index, ptr->patronymic);
            ptr = ptr->next;
        }
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 3);
            model->setData(index, ptr->math);
            ptr = ptr->next;
        }
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 4);
            model->setData(index, ptr->physics);
            ptr = ptr->next;
        }
        ptr = person->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 5);
            model->setData(index, ptr->language);
            ptr = ptr->next;
        }
        countComboBox();
    }
}

void MainWindow::on_button_search_clicked()
{
    int check = 0;
    Matriculant* temp = new Matriculant();
    if (ptr == person->head)
    {
        while(ptr != 0)
        {
            if (ui->line_search -> text() == ptr->surname)
            {
                temp->AddTail(ptr->surname, ptr->name, ptr->patronymic, ptr->math, ptr->physics, ptr->language);
                ++check;
            }
            ptr = ptr->next;
        }
    }
    else if (ptr == 0)
    {
        ptr = person->tail;
        while(ptr != 0)
        {
            if (ui->line_search -> text() == ptr->surname)
            {
                temp->AddTail(ptr->surname, ptr->name, ptr->patronymic, ptr->math, ptr->physics, ptr->language);
                ++check;
            }
            ptr = ptr->previous;
        }
    }
    else
    {
        ptr = person->head;
        while(ptr != 0)
        {
            if (ui->line_search -> text() == ptr->surname)
            {
                temp->AddTail(ptr->surname, ptr->name, ptr->patronymic, ptr->math, ptr->physics, ptr->language);
                ++check;
            }
            ptr = ptr->next;
        }
    }
    if (check)
    {
        ui->button_add->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_sort->setEnabled(false);
        ui->button_back->setEnabled(true);
        ui->button_delete->setEnabled(false);
        ui->comboBox->setEnabled(false);
        delete model;
        model = 0;
        model = new QStandardItemModel(temp->count, 6, this);
        model->setHeaderData(0, Qt::Horizontal, "Surname");
        model->setHeaderData(1, Qt:: Horizontal, "Name");
        model->setHeaderData(2, Qt:: Horizontal, "Patronymic");
        model->setHeaderData(3, Qt:: Horizontal, "Math mark");
        model->setHeaderData(4, Qt:: Horizontal, "Physics mark");
        model->setHeaderData(5, Qt:: Horizontal, "Language mark");
        ui->tableView->setModel(model);
        QModelIndex index;
        Human* temp1;
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 0);
            model->setData(index, temp1->surname);
            temp1 = temp1->next;
        }
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 1);
            model->setData(index, temp1->name);
            temp1 = temp1->next;
        }
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 2);
            model->setData(index, temp1->patronymic);
            temp1 = temp1->next;
        }
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 3);
            model->setData(index, temp1->math);
            temp1 = temp1->next;
        }
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 4);
            model->setData(index, temp1->physics);
            temp1 = temp1->next;
        }
        temp1 = temp->head;
        for (int row = 0; row < model->rowCount(); row++)
        {
            index = model->index(row, 5);
            model->setData(index, temp1->language);
            temp1 = temp1->next;
        }
        delete temp;
        ui->line_search ->clear();
        ui->button_add->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_sort->setEnabled(false);
        ui->button_back->setEnabled(true);
        ui->button_delete->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->button_write_to_file->setEnabled(false);
        ui->button_read_file->setEnabled(false);
        QMessageBox::information(this, "Warning", "You can't modify data in this table(only in main table). Unpredictable behavior");
    }
    else
    {
        QMessageBox::information(this, "ERROR","There is no such matriculant");
        delete temp;
        ui->line_search ->clear();
        return;
    }
}

void MainWindow::on_button_back_clicked()
{
    ui->button_add->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_sort->setEnabled(true);
    ui->button_back->setEnabled(false);
    ui->button_delete->setEnabled(true);
    ui->comboBox->setEnabled(true);
    delete model;
    model = 0;
    model = new QStandardItemModel(person->count, 6, this);
    model->setHeaderData(0, Qt::Horizontal, "Surname");
    model->setHeaderData(1, Qt:: Horizontal, "Name");
    model->setHeaderData(2, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(3, Qt:: Horizontal, "Math mark");
    model->setHeaderData(4, Qt:: Horizontal, "Physics mark");
    model->setHeaderData(5, Qt:: Horizontal, "Language mark");
    ui->tableView->setModel(model);
    QModelIndex index;
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, ptr->surname);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, ptr->name);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, ptr->patronymic);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, ptr->math);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, ptr->physics);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, ptr->language);
        ptr = ptr->next;
    }
    countComboBox();
    ui->button_add->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_sort->setEnabled(true);
    ui->button_back->setEnabled(false);
    ui->button_delete->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->button_write_to_file->setEnabled(true);
    ui->button_read_file->setEnabled(true);
}

void MainWindow::on_button_sort_clicked()
{
    ptr = person->head;
    person->Average_score(ptr);
    person->quickSortByAverage_score(person->head, person->tail);
    delete model;
    model = 0;
    model = new QStandardItemModel(person->count, 6, this);
    model->setHeaderData(0, Qt::Horizontal, "Surname");
    model->setHeaderData(1, Qt:: Horizontal, "Name");
    model->setHeaderData(2, Qt:: Horizontal, "Patronymic");
    model->setHeaderData(3, Qt:: Horizontal, "Math mark");
    model->setHeaderData(4, Qt:: Horizontal, "Physics mark");
    model->setHeaderData(5, Qt:: Horizontal, "Language mark");
    ui->tableView->setModel(model);
    QModelIndex index;
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, ptr->surname);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, ptr->name);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, ptr->patronymic);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, ptr->math);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, ptr->physics);
        ptr = ptr->next;
    }
    ptr = person->head;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 5);
        model->setData(index, ptr->language);
        ptr = ptr->next;
    }
    countComboBox();
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString str = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
    int x = index.row();
    int y = index.column();
    int count = 0;
    ptr = person->head;
    if (y == 0 && str.size() <= 15 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->surname = str;
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 0 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The surname can contain only 1 to 15 symbols");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->surname);
        ptr = person->head;
        count = 0;
        return;
    }
    else if (y == 1 && str.size() <= 15 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->name = str;
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 1 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The name can contain only 1 to 15 symbols");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->name);
        ptr = person->head;
        count = 0;
        return;
    }
    else if (y == 2 && str.size() <= 15 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->patronymic = str;
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 2 && (str.size() > 15 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The patronymic can contain only 1 to 15 symbols");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->patronymic);
        ptr = person->head;
        count = 0;
        return;
    }
    else if (y == 3 && str.toInt() <= 10 && str.toInt() > 0 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->math = str.toInt();
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 3 && (str.toInt() > 10 || str.toInt() <= 0 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The mark can contain numbers 1 to 10");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->math);
        ptr = person->head;
        count = 0;
        return;
    }
    else if (y == 4 && str.toInt() <= 10 && str.toInt() > 0 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->physics = str.toInt();
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 4 && (str.toInt() > 10 || str.toInt() <= 0 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The mark can contain numbers 1 to 10");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->physics);
        ptr = person->head;
        count = 0;
        return;
    }
    else if (y == 5 && str.toInt() <= 10 && str.toInt() > 0 && str.size() > 0)
    {
        for (int i = 0; i < person->count; i++)
        {
            if (x == count)
            {
                ptr->language = str.toInt();
                break;
            }
            else
            {
                ptr = ptr->next;
                ++count;
            }
        }
        ptr = person->head;
        count = 0;
    }
    else if (y == 5 && (str.toInt() > 10 || str.toInt() <= 0 || str.size() == 0))
    {
        QMessageBox::information(this, "ERROR","The mark can contain numbers 1 to 10");
        while(x != count)
        {
            ptr = ptr->next;
            ++count;
        }
        model->setData(index, ptr->language);
        ptr = person->head;
        count = 0;
        return;
    }
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
    ptr = person->head;
    while(ptr != 0)
    {
        stream << " " << ptr->surname << " " << ptr->name << " " << ptr->patronymic << " " << ptr->math << " " << ptr->physics << " " << ptr->language;
        ptr = ptr->next;
    }
    File.close();
}

void MainWindow::on_button_write_to_file_clicked()
{
    this->Write_to_file();
}

