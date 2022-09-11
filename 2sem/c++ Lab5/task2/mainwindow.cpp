#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 600);
    this->setFixedSize(1200, 600);
    ui->lineEdit->setInputMask("000");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pop_front_clicked()
{
    if(deque.Size()== 0)
    {
        QMessageBox::information(this,"Error","The deque is empty");
        return;
    }
    deque.Pop_Front();
    ui->listWidget->takeItem(0);
}


void MainWindow::on_pop_back_clicked()
{
    if(deque.Size()== 0)
    {
        QMessageBox::information(this,"Error","The deque is empty");
        return;
    }
    deque.Pop_Back();
    ui->listWidget->takeItem(deque.Size());
}

void MainWindow::on_push_back_clicked()
{
    int num = ui->lineEdit->text().toInt();
    deque.Push_Back(num);
    ui->listWidget->addItem(QString::number(num));
    ui->lineEdit->clear();
}

void MainWindow::on_push_front_clicked()
{
    int num = ui->lineEdit->text().toInt();
    deque.Push_Front(num);
    ui->listWidget->insertItem(0, QString::number(deque.Front()));
    ui->lineEdit->clear();
}

