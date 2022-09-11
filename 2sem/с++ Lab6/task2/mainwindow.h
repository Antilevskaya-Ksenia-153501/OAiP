#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable_Task.h"

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
    void on_Add_clicked();
    void on_Delete_clicked();
    void on_Search_clicked();
    void on_Task_clicked();
private:
    Ui::MainWindow *ui;
    HashTable_Task<int, int> table;
};
#endif // MAINWINDOW_H
