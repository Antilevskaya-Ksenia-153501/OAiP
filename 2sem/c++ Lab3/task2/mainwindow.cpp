#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    rect_stack.push(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_peek_clicked()
{
    QString j = rect_stack.peek();
    ui->lineEdit_2->setText(j);
}

void MainWindow::on_pop_clicked()
{
     rect_stack.pop();
     ui->lineEdit_2->clear();
}

void MainWindow::on_update_clicked()
{
    ui->plainTextEdit->setPlainText(rect_stack.print());
}

