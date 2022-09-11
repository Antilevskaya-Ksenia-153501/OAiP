#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

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
    void on_add_clicked();
    void on_peek_clicked();
    void on_pop_clicked();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    Stack rect_stack;
};
#endif // MAINWINDOW_H
