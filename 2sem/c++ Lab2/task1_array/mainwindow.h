#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sportsman.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Sportsman *sportsman = 0;
    QStandardItemModel *model = 0;
    QString filePath;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void countComboBox();

    void Read_from_file();
    void on_button_read_from_file_clicked();

    void on_button_add_clicked();

    void on_button_delete_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_button_search_clicked();

    void on_button_back_clicked();

    void on_button_search1_clicked();

    void on_button_search2_clicked();

    void on_button_find_youngest_clicked();

    void on_button_write_to_file_clicked();
    void Write_to_file();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
