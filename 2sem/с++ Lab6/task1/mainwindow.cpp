#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    ui->lineEditType->setInputMask("99");
    ui->lineEditTypeKey->setInputMask("99");
    ui->lineEditSearch->setInputMask("99");
    ui->lineEditTypeKeyDel->setInputMask("99");
    ui->lineEditTask->setInputMask("99");
    ui->Search->setEnabled(false);
    ui->Task->setEnabled(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::PrintTree(MyTreeNode<int, int> *root, int space)
{
    QString result_prob;
    if (root == NULL)
        return;
    space += 10;
    PrintTree(root->right, space);
    for (int j = 10; j < space; j++)
        result_prob += " ";
    if (10 < space)
        ui->plainTextEdit->appendPlainText(result_prob + QString::number(root->key) + "\n");
    else
        ui->plainTextEdit->appendPlainText(QString::number(root->key) + "\n");
    PrintTree(root->left, space);
}
void MainWindow::on_Add_clicked()
{
    if (ui->lineEditType->text().isEmpty()|| ui->lineEditTypeKey->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    AVL.AddTreeNode(ui->lineEditType->text().toInt(), ui->lineEditTypeKey->text().toInt());
    ui->lineEditType->clear();
    ui->lineEditTypeKey->clear();
    ui->plainTextEdit->clear();
    PrintTree(AVL.GetRoot(), 0);
    if (AVL.GetRoot() != nullptr)
    {
        ui->Search->setEnabled(true);
        ui->Task->setEnabled(true);
    }
}
void MainWindow::on_Delete_clicked()
{
    if (ui->lineEditTypeKeyDel->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    AVL.Remove(ui->lineEditTypeKeyDel->text().toInt());
    ui->lineEditTypeKeyDel->clear();
    ui->plainTextEdit->clear();
    PrintTree(AVL.GetRoot(), 0);
    if (AVL.GetRoot() == nullptr)
    {
        ui->Search->setEnabled(false);
         ui->Task->setEnabled(false);
    }
}
void MainWindow::on_DirectOrder_clicked()
{
    ui->labelDirectOrder->setText(AVL.PrintInDirectOrder());
}
void MainWindow::on_ReverseOrder_clicked()
{
    ui->labelReverseOrder->setText(AVL.PrintInReverseOrder());
}
void MainWindow::on_AscendingOrder_clicked()
{
    ui->labelAscendingOrder->setText(AVL.PrintInAscendingOrder());
}
void MainWindow::on_Task_clicked()
{
    if (ui->lineEditTask->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    AVL.Task(ui->lineEditTask->text().toInt());
    ui->lineEditTask->clear();
    ui->plainTextEdit->clear();
    PrintTree(AVL.GetRoot(), 0);
}
void MainWindow::on_Search_clicked()
{
    if (ui->lineEditSearch->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    int i = ui->lineEditSearch->text().toInt();
    ui->lineEditSearch->clear();
    ui->labelSearchResult->setText(QString::number(AVL.Search(i)));
}

