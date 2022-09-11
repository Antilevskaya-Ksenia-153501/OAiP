#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200, 600);
    ui->line_set->setInputMask("99");
    ui->line_reset->setInputMask("99");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonFlip_clicked()
{
    ui->plainTextEdit->clear();
    BitSet.Flip();
    ui->plainTextEdit->appendPlainText(QString::fromStdString(BitSet.to_string()));
}

void MainWindow::on_buttonSet_clicked()
{
    ui->plainTextEdit->clear();
    if (ui->line_set->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    if (ui->line_set->text().toInt() >= 50 || ui->line_set->text().toInt() < 0)
    {
        QMessageBox::information(this, "Error", "Enter number from 0 to 49");
        return;
    }
    BitSet.Set(ui->line_set->text().toInt());
    ui->plainTextEdit->appendPlainText(QString::fromStdString(BitSet.to_string()));
    ui->line_set->clear();
}

void MainWindow::on_buttonReset_clicked()
{
    ui->plainTextEdit->clear();
    if (ui->line_reset->text().isEmpty())
    {
        QMessageBox::information(this, "Error", "Empty line");
        return;
    }
    if (ui->line_reset->text().toInt() >= 50 || ui->line_set->text().toInt() < 0)
    {
        QMessageBox::information(this, "Error", "Enter number from 0 to 49");
        return;
    }
    BitSet.Reset(ui->line_reset->text().toInt());
    ui->plainTextEdit->appendPlainText(QString::fromStdString(BitSet.to_string()));
    ui->line_reset->clear();
}

void MainWindow::on_buttonAll_clicked()
{
    if (BitSet.All())
        ui->resAll->setText("True");
    else
        ui->resAll->setText("False");
}

void MainWindow::on_buttonUlong_clicked()
{
    ui->resTo_Ulong->setText(QString::number(BitSet.to_ulong()));
}

void MainWindow::on_buttonUllong_clicked()
{
    ui->resTo_Ullong->setText(QString::number(BitSet.to_ullong()));
}

void MainWindow::on_buttonAny_clicked()
{
    if (BitSet.Any())
        ui->resAny->setText("True");
    else
        ui->resAny->setText("False");
}

void MainWindow::on_buttonNone_clicked()
{
    if (BitSet.None())
        ui->resNone->setText("True");
    else
        ui->resNone->setText("False");
}

