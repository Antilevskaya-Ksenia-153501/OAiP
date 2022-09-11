#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 600);
    this->setFixedSize(1200, 600);
    ui->lineEdit->setInputMask("00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_push_back_clicked()
{
    queue.Push_Back(ui->lineEdit->text());
    ui->lineEdit->clear();
    qDebug() << queue.Front();
    qDebug() << queue.Back();
    qDebug() << queue.Size();
}

void MainWindow::on_display_clicked()
{
    QString res = queue.Display();
    ui->plainTextEdit->setPlainText(res);
}

void MainWindow::on_pop_front_clicked()
{
    queue.Pop_Front();
}

void MainWindow::on_task_clicked()
{
    queue.Task();
}

