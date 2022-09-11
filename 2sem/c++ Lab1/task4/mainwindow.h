#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "radio_studio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QStandardItemModel* model = 0;
    Radio_studio* Studio = 0;
    int amount = 0;
    QString filePath;
    ~MainWindow();

private slots:
    void on_button_read_file_clicked();
    void Read_from_file();
    void Write_to_file();

    void countComboBox();
    void on_button_add_clicked();
    void on_button_sort_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_button_write_file_clicked();

    void on_button_delete_clicked();

    void on_button_search_clicked();

    void on_button_update_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
