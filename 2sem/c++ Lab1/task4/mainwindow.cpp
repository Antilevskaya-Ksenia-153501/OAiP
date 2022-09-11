#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QFileInfo>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->line_group->setInputMask("AAAAAAAAAA");
    ui->line_brand->setInputMask("AAAAAAAAAA");
    ui->line_date1->setInputMask("99.99.9999");
    ui->line_date2->setInputMask("99.99.9999");
    ui->button_add->setEnabled(false);
    ui->button_search->setEnabled(false);
    ui->button_sort->setEnabled(false);
    ui->button_update->setEnabled(false);
    ui->button_write_file->setEnabled(false);
    ui->button_delete->setEnabled(false);
    ui->comboBox->setEnabled(false);
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
        if(Studio)
        {
            delete[] Studio;
        }
        Studio = 0;
        amount = 0;
    }
    this->Read_from_file();
}

void MainWindow::Read_from_file()
{
    filePath = QFileDialog:: getOpenFileName(this, "Choose file", "C:\\Users\\Notebook\\Desktop\\Study\\c++ Labs 2 sem\\radio_studio.txt", "Text File (*.txt)");
    QFile File(filePath);
    if (!File.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "Can not open the file");
        return;
    }
    else if (File.size() == 0)
    {
        QMessageBox::information(this, "ERROR", "The file is empty");
        return;
        ui->button_add->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_sort->setEnabled(false);
        ui->button_update->setEnabled(false);
        ui->button_write_file->setEnabled(false);
        ui->button_delete->setEnabled(false);
        ui->comboBox->setEnabled(false);
    }
    QTextStream stream(&File);
    Radio_studio temp;
    int i = 0;
    int j = 0;
    while(!stream.atEnd())
    {
        stream >> temp.product_group >> temp.product_brand >> temp.date1 >> temp.date2;
        if (temp.verification(temp))
        {
            Studio = Studio->AddNewItem(Studio, amount);
            Studio[i] = temp;
            amount++;
            i++;
        }
        else
        {
            ++j;
        }
    }

    File.close();
    if (Studio == 0)
    {
        QMessageBox::information(this, "ERROR", "There is no correct date in the file or file contains only spaces");
        return;
        ui->button_add->setEnabled(false);
        ui->button_search->setEnabled(false);
        ui->button_sort->setEnabled(false);
        ui->button_update->setEnabled(false);
        ui->button_write_file->setEnabled(false);
        ui->button_delete->setEnabled(false);
        ui->comboBox->setEnabled(false);
    }
    Studio->condition(Studio, amount);
    model = new QStandardItemModel(amount, 5, this);
    model->setHeaderData(0, Qt::Horizontal, "Product's group");
    model->setHeaderData(1, Qt:: Horizontal, "Product's brand");
    model->setHeaderData(2, Qt:: Horizontal, "Day of receipt");
    model->setHeaderData(3, Qt:: Horizontal, "Execution Date");
    model->setHeaderData(4, Qt:: Horizontal, "Status");
    ui->tableView->setModel(model);

    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, Studio[row].product_group);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, Studio[row].product_brand);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, Studio[row].date1);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, Studio[row].date2);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, Studio[row].status);
    }
    ui->button_add->setEnabled(true);
    ui->button_search->setEnabled(true);
    ui->button_sort->setEnabled(true);
    ui->button_update->setEnabled(true);
    ui->button_write_file->setEnabled(true);
    ui->button_delete->setEnabled(true);
    ui->comboBox->setEnabled(true);
    countComboBox();
    if (j)
    {
        Write_to_file();
        QMessageBox::information(this, "ERROR", "There is incorrect data in the file");
        return;
    }
}

void MainWindow::on_button_write_file_clicked()
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
    for (int i = 0; i < amount; i++)
    {
        stream <<" " << Studio[i].product_group << " " << Studio[i].product_brand << " " << Studio[i].date1 << " " << Studio[i].date2;
    }

    File.close();
}

void MainWindow::countComboBox()
{
    ui->comboBox->clear();
    for (int i = 1; i <= amount; i++)
    {
        ui->comboBox->addItem(QString::number(i));
    }
}

void MainWindow::on_button_add_clicked()
{
    Studio = Studio->AddNewItem(Studio, amount);
    Studio[amount].product_group = ui->line_group->text();
    Studio[amount].product_brand = ui->line_brand->text();
    if ( Radio_studio::IsInvalidDate(ui->line_date1 ->text()))
    {
        Studio[amount].date1 = ui->line_date1 ->text();
    }
    else if (!Radio_studio::IsInvalidDate(ui->line_date1 ->text()))
    {
        QMessageBox::information(this, "ERROR","The date isn't correct");
        return;
    }
    if ( Radio_studio::IsInvalidDate(ui->line_date2 ->text()))
    {
        Studio[amount].date2 = ui->line_date2 ->text();
    }
    else if (!Radio_studio::IsInvalidDate(ui->line_date2 ->text()))
    {
        QMessageBox::information(this, "ERROR","The date isn't correct");
        return;
    }
    Studio->condition(Studio, amount + 1);
    int lastRow = model->rowCount();
    model->insertRow(lastRow);
    QModelIndex index;

    index = model->index(amount, 0);
    model->setData(index, Studio[amount].product_group);

    index = model->index(amount, 1);
    model->setData(index, Studio[amount].product_brand);

    index = model->index(amount, 2);
    model->setData(index, Studio[amount].date1);

    index = model->index(amount, 3);
    model->setData(index, Studio[amount].date2);


    index = model->index(amount, 4);
    model->setData(index, Studio[amount].status);
    countComboBox();
    amount++;
    ui->line_group->clear();
    ui->line_brand->clear();
    ui->line_date1->clear();
    ui->line_date2->clear();
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString str = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
    int x = index.row();
    int y = index.column();
    if ( y == 0 && str.size() <= 10)
    {
        Studio[x].product_group = str;
    }
    if ( y == 1 && str.size() <= 10)
    {
        Studio[x].product_brand = str;
    }
    if ( y == 2 && Radio_studio::IsInvalidDate(str))
    {
        Studio[x].date1 = str;
    }
    else if (( y == 2 && !Radio_studio::IsInvalidDate(str)))
    {
        QMessageBox::information(this, "ERROR","The date isn't correct");
        return;
    }

    if ( y == 3 && Radio_studio::IsInvalidDate(str))
    {
        Studio[x].date2 = str;
    }
    else if (( y == 3 && !Radio_studio::IsInvalidDate(str)))
    {
        QMessageBox::information(this, "ERROR","The date isn't correct");
        return;
    }
}


void MainWindow::on_button_sort_clicked()
{

    Studio->sort(Studio, amount);
    delete model;
    model = 0;
    model = new QStandardItemModel(amount, 5, this);
    model->setHeaderData(0, Qt::Horizontal, "Product's group");
    model->setHeaderData(1, Qt:: Horizontal, "Product's brand");
    model->setHeaderData(2, Qt:: Horizontal, "Day of receipt");
    model->setHeaderData(3, Qt:: Horizontal, "Execution Date");
    model->setHeaderData(4, Qt:: Horizontal, "Status");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, Studio[row].product_group);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, Studio[row].product_brand);
    }

    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, Studio[row].date1);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, Studio[row].date2);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 4);
        model->setData(index, Studio[row].status);
    }
    qDebug() << amount;

}


void MainWindow::on_button_delete_clicked()
{
    if(amount != 0)
    {
    for (int i = ui->comboBox->currentText().toInt() - 1; i < amount - 1; i++)
    {
            Studio[i] = Studio[i + 1];
    }
    --amount;
    Studio->condition(Studio, amount);
    delete model;
    model = 0;
    model = new QStandardItemModel(amount, 5, this);
    model->setHeaderData(0, Qt::Horizontal, "Product's group");
    model->setHeaderData(1, Qt:: Horizontal, "Product's brand");
    model->setHeaderData(2, Qt:: Horizontal, "Day of receipt");
    model->setHeaderData(3, Qt:: Horizontal, "Execution Date");
    model->setHeaderData(4, Qt:: Horizontal, "Status");
    ui->tableView->setModel(model);

    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, Studio[row].product_group);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, Studio[row].product_brand);
    }

    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, Studio[row].date1);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, Studio[row].date2);
    }

    for (int row = 0; row < model->rowCount(); row++)
     {
         index = model->index(row, 4);
         model->setData(index, Studio[row].status);
     }
      countComboBox();
    }
}


void MainWindow::on_button_search_clicked()
{
    if (amount != 0)
    {
    delete model;
    model = 0;
    model = new QStandardItemModel(amount, 4, this);
    model->setHeaderData(0, Qt::Horizontal, "Product's group");
    model->setHeaderData(1, Qt:: Horizontal, "Product's brand");
    model->setHeaderData(2, Qt:: Horizontal, "Day of receipt");
    model->setHeaderData(3, Qt:: Horizontal, "Month of receipt");
    ui->tableView->setModel(model);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 0);
        model->setData(index, Studio[row].product_group);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 1);
        model->setData(index, Studio[row].product_brand);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 2);
        model->setData(index, Studio[row].date1);
    }
    for (int row = 0; row < model->rowCount(); row++)
    {
        index = model->index(row, 3);
        model->setData(index, Studio[row].date2);
    }

    for(int i = 0; i <=model->columnCount(); i++)
    {
        for(int j = 0; j <= model->rowCount(); j++)
        {
            QModelIndex ind = model->index(j, i);
            if (ind.data().toString() == ui->lineEdit_search->text())
            {
                 model->item(j,i)->setBackground(Qt::yellow);
            }
            else
            {
                QMessageBox::information(this, "ERROR","There is no such object in the table");
                return;
            }
        }
    }
    ui->lineEdit_search->clear();
}}

void MainWindow::on_button_update_clicked()
{
    Studio->condition(Studio, amount);
    QModelIndex index;
    for (int row = 0; row < model->rowCount(); row++)
     {
         index = model->index(row, 4);
         model->setData(index, Studio[row].status);
    }
}


