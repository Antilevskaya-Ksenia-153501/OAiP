#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<MyBitSet.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonFlip_clicked();
    void on_buttonSet_clicked();
    void on_buttonReset_clicked();
    void on_buttonAll_clicked();
    void on_buttonUlong_clicked();
    void on_buttonUllong_clicked();
    void on_buttonAny_clicked();
    void on_buttonNone_clicked();

private:
    Ui::MainWindow *ui;
    MyBitSet<50> BitSet;
};
#endif // MAINWINDOW_H
