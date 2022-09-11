#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include "matriculant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStandardItemModel* model;
    Matriculant* person;
    Human* ptr;
    QString filePath;

private slots:
    void Read_from_file();
    void on_button_read_file_clicked();

    void on_button_add_clicked();

    void countComboBox();

    void on_button_delete_clicked();

    void on_button_search_clicked();

    void on_button_back_clicked();

    void on_button_sort_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void Write_to_file();
    void on_button_write_to_file_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
