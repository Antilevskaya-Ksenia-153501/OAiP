#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include "mydeque.h"

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

    void on_pop_front_clicked();
    void on_pop_back_clicked();
    void on_push_back_clicked();
    void on_push_front_clicked();

private:
    Ui::MainWindow *ui;
    MyDeque<int> deque;
};
#endif // MAINWINDOW_H
