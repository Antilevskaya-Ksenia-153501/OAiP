#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<MySet.h>
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
    void on_buttonDelete_clicked();
    void on_buttonSearch_clicked();

private:
    Ui::MainWindow *ui;
    MySet<int, int> Set;
};
#endif // MAINWINDOW_H
