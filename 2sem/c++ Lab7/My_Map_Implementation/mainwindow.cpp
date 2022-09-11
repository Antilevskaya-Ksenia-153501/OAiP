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
    ui->line_data->setInputMask("99");
    ui->line_keyDelete->setInputMask("99");
    ui->line_keyFind->setInputMask("99");
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
    QString res_key = "Key: ";
    QString res_value = "Value: ";
    auto result = Map.Insert(std::pair<int, int>(ui->line_key->text().toInt(), ui->line_data->text().toInt()));
    for(MyMap<int, int>::MyMapIterator_List it = Map.Begin_List(); it != Map.End_List(); it++)
    {
        res_key += QString::number(it->first) + " ";
        res_value += QString::number(it->second) + " ";
    }
    ui->plainTextEdit->appendPlainText(res_key + "\n");
    ui->plainTextEdit->appendPlainText(res_value + "\n");
    if (!result.second)
    {
        QMessageBox::information(this, "Error", "Your map already has this key");
        return;
    }
    ui->line_key->clear();
    ui->line_data->clear();
}

void MainWindow::on_buttonRemove_clicked()
{
    if (ui->line_keyDelete->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    ui->plainTextEdit->clear();
    QString res_key = "Key: ";
    QString res_value = "Value: ";
    Map.Erase(ui->line_keyDelete->text().toInt());
    for(MyMap<int, int>::MyMapIterator it = Map.Begin(); it != Map.End(); it++)
    {
        res_key += QString::number(it->first) + " ";
        res_value += QString::number(it->second) + " ";
    }
    ui->plainTextEdit->appendPlainText(res_key + "\n");
    ui->plainTextEdit->appendPlainText(res_value + "\n");
    ui->line_keyDelete->clear();
}

void MainWindow::on_buttonSearch_clicked()
{
    if (ui->line_keyFind->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    auto res = Map.Find(ui->line_keyFind->text().toInt());
    if (res.first == 0 && res.second == 0)
    {
        QMessageBox::information(this, "Error", "Your map does not have such key");
        return;
    }
    else
    {
        ui->resultSerach->setText("The result: key - " + QString::number(res.first) + "; date - " + QString::number(res.second));
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
    QString res_key = "Key: ";
    QString res_value = "Value: ";
    for(MyMap<int, int>::MyMapIterator it = Map.Begin(); it != Map.End(); it++)
    {
        res_key += QString::number(it->first) + " ";
        res_value += QString::number(it->second) + " ";
    }
    ui->plainTextEdit->appendPlainText(res_key + "\n");
    ui->plainTextEdit->appendPlainText(res_value + "\n");
}

