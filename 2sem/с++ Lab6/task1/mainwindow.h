#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mytree_task.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PrintTree(MyTreeNode<int, int> *root, int space);
private slots:
    void on_Add_clicked();
    void on_Delete_clicked();
    void on_DirectOrder_clicked();
    void on_ReverseOrder_clicked();
    void on_AscendingOrder_clicked();
    void on_Task_clicked();

    void on_Search_clicked();

private:
    Ui::MainWindow *ui;
    MyTree_Task<int,int> AVL;
};
#endif // MAINWINDOW_H
