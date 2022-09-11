#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200, 600);
    ui->line_key->setInputMask("99");
    ui->line_keyDelete->setInputMask("99");
    ui->line_keySearch->setInputMask("99");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonInsert_clicked()
{
    if (ui->line_key->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    QString res_key = "Key: ";
    auto result = Set.Insert(std::pair<int, int>(ui->line_key->text().toInt(),ui->line_key->text().toInt()));
    for(MySet<int, int>::MySetIterator_List it = Set.Begin_List(); it != Set.End_List(); it++)
    {
        res_key += QString::number(it->first) + " ";
    }
    ui->plainTextEdit->appendPlainText(res_key + "\n");
    if (!result.second)
    {
        QMessageBox::information(this, "Error", "Your map already has this key");
        return;
    }
       ui->line_key->clear();
}

void MainWindow::on_buttonDelete_clicked()
{
    if (ui->line_keyDelete->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    QString res_key = "Key: ";
    Set.Erase(ui->line_keyDelete->text().toInt());
    for(MySet<int, int>::MySetIterator it = Set.Begin(); it != Set.End(); it++)
    {
        res_key += QString::number(it->first) + " ";
    }
    ui->plainTextEdit->appendPlainText(res_key + "\n");
    ui->line_keyDelete->clear();
}

void MainWindow::on_buttonSearch_clicked()
{
    if (ui->line_keySearch->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    auto res = Set.Find(ui->line_keySearch->text().toInt());
    if (res.first == 0 && res.second == 0)
    {
        QMessageBox::information(this, "Error", "Your map does not have such key");
        return;
    }
    else
    {
        ui->resSearch->setText("The result: key - " + QString::number(res.first));
    }
}

