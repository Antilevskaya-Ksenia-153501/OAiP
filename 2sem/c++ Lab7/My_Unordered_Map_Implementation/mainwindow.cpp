#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 600);
    this->setFixedSize(1200, 600);
    ui->line_key->setInputMask("99");
    ui->line_data->setInputMask("99");
    ui->line_keyEdit->setInputMask("99");
    ui->line_dataEdit->setInputMask("99");
    ui->line_keyDelete->setInputMask("99");
    ui->line_keySearch->setInputMask("99");
    /*d.Insert(508,4);
    d.Insert(104,4);
    d.Insert(105,4);
    d.Insert(106,4);
    d.Insert(107,4);
    d.Insert(108,4);
    d.Insert(109,4);
    d.Insert(101,4);
    d.Insert(163,4);
    d.Insert(111,4);
    d.Insert(114,4);
    d.Insert(164,4);
    //d[109] = 7;
    QString* res = d.Print();
        for (int i = 0; i < 16; i++)
        {
           qDebug() << res[i];
        }

    qDebug() << d.Contains(0);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonInsert_clicked()
{
    if (ui->line_key->text().isEmpty() || ui->line_data->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    Map.Insert(ui->line_key->text().toInt(), ui->line_data->text().toInt());
    ui->line_key->clear();
    ui->line_data->clear();
    QString* res = Map.Print();
    for (size_t i = 0; i < Map.MapSize(); i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}

void MainWindow::on_buttonErase_clicked()
{
    if (ui->line_keyDelete->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    Map.Erase(ui->line_keyDelete->text().toInt());
    ui->line_keyDelete->clear();
    QString* res = Map.Print();
    for (size_t i = 0; i < Map.MapSize(); i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}

void MainWindow::on_buttonEdit_clicked()
{
    if (ui->line_keyEdit->text().isEmpty() || ui->line_dataEdit->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    Map[ui->line_keyEdit->text().toInt()];
    Map[ui->line_keyEdit->text().toInt()] = ui->line_dataEdit->text().toInt();
    ui->line_keyEdit->clear();
    ui->line_dataEdit->clear();
    QString* res = Map.Print();
    for (size_t i = 0; i < Map.MapSize(); i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}

void MainWindow::on_buttonSearch_clicked()
{
    if (ui->line_keySearch->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    auto res = Map.Find(ui->line_keySearch->text().toInt());
    if (res._M_node == 0)
    {
        QMessageBox::information(this, "Error", "Your unordered map does not have such key");
        return;
    }
    else
    {
        ui->resSearch->setText("The result: key - " + QString::number(res->first) + "; date - " + QString::number(res->second));
    }
}

