#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QStandardItemModel* model = 0;
    Date* date = 0;
    int amount = 0;
    ~MainWindow();

private slots:
    void on_button_read_file_clicked();
    void Read_from_file();

    void Write_to_file();


    void on_button_nextday_clicked();

    void on_button_previousday_clicked();

    void on_button_is_leap_clicked();

    void on_button_duration_clicked();

    void on_button_ok_clicked();

    void on_button_week_number_clicked();

    void on_button_add_clicked();

    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::MainWindow *ui;
    QString filePath;
};
#endif // MAINWINDOW_H
