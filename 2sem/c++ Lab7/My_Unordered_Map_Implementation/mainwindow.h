#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<MyUnorderedMap.h>

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
    void on_buttonErase_clicked();
    void on_buttonEdit_clicked();
    void on_buttonSearch_clicked();

private:
    Ui::MainWindow *ui;
    MyUnorderedMap<int, int> Map;
};
#endif // MAINWINDOW_H
