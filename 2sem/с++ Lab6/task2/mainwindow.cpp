#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 600);
    this->setFixedSize(1200, 600);
    ui->lineEditAddData->setInputMask("999");
    ui->lineEditAddKey->setInputMask("999");
    ui->lineEditDelete->setInputMask("999");
    ui->lineEditSearch->setInputMask("999");
    table.Add(6, -900);
    table.Add(9, 910);
    table.Add(8, 904);
    table.Add(50, 805);
    table.Add(64, -905);
    table.Add(12, -602);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_clicked()
{
    if (ui->lineEditAddData->text().isEmpty() || ui->lineEditAddKey->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    table.Add(ui->lineEditAddData->text().toInt(), ui->lineEditAddKey->text().toInt());
    ui->lineEditAddData->clear();
    ui->lineEditAddKey->clear();
    QString* res = table.Print();
    for (int i = 0; i < 10; i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}
void MainWindow::on_Delete_clicked()
{
    if (ui->lineEditDelete->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    table.Remove(ui->lineEditDelete->text().toInt());
    ui->lineEditDelete->clear();
    QString* res = table.Print();
    for (int i = 0; i < 10; i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}
void MainWindow::on_Search_clicked()
{
    if (ui->lineEditSearch->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    int i;
    if (table.Get(i,ui->lineEditSearch->text().toInt()))
    {
        ui->labelSearch->setText(QString::number(i));
    }
    else{
        ui->labelSearch->setText("there is no such key");
    }
    ui->lineEditSearch->clear();
}


void MainWindow::on_Task_clicked()
{
    ui->plainTextEdit->clear();
    table.Task();
    QString* res = table.Print();
    for (int i = 0; i < 10; i++)
    {
        ui->plainTextEdit->appendPlainText(res[i]);
    }
}


