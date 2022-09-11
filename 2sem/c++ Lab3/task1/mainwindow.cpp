#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->Delete->setEnabled(false);
    ui->Update->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    if (List == nullptr)
    {
        List = new Doubly_Linked_List();
        ui->Delete->setEnabled(true);
        ui->Update->setEnabled(true);
    }
    List->Insert(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_Update_clicked()
{
    if (List)
        ui->Update->setEnabled(true);
    auto Current = List->First;
    QString result;
    while(Current)
    {
        result += Current->Data + " ";
        Current = Current->Next;
    }
    ui->plainTextEdit->setPlainText(result);
}

void MainWindow::on_Delete_clicked()
{
    if (List)
    {
        ui->Delete->setEnabled(true);
    }
    List->Delete(ui->lineEdit_2->text());
    ui->lineEdit_2->clear();
    if (List->Size == 0)
    {
        delete List;
        List = nullptr;
        ui->plainTextEdit->clear();
        ui->Delete->setEnabled(false);
        ui->Update->setEnabled(false);
    }
}

