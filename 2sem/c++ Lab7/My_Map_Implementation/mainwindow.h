#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mymap.h>
#include<QMessageBox>

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
    void on_buttonInsert_clicked();
    void on_buttonRemove_clicked();
    void on_buttonSearch_clicked();
    void on_buttonEdit_clicked();

private:
    Ui::MainWindow *ui;
    MyMap<int, int> Map;
};
#endif // MAINWINDOW_H
