#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqueue_task.h"
#include <QDebug>
#include <QString>

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
    void on_push_back_clicked();
    void on_display_clicked();
    void on_pop_front_clicked();
    void on_task_clicked();

private:
    Ui::MainWindow *ui;
    MyQueue_task<QString> queue;
};
#endif // MAINWINDOW_H
