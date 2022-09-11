#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "doubly_linked_list.h"

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

    void on_Update_clicked();

    void on_Delete_clicked();

private:
    Ui::MainWindow *ui;
    Doubly_Linked_List* List = nullptr;
};
#endif // MAINWINDOW_H
