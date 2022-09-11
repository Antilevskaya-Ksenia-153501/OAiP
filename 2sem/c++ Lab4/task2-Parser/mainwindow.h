#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<mystring.h>
#include<myvector.h>
#include "string.h"
#include <regex>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MyString QStringToMyString(QString input);
    QString MyStringToQString(MyString input);
    std::string MyStringToStdString(MyString input);
    MyString StdStringToMyString(std::string input);

private slots:
    void on_find_types_of_variables_clicked();
    void on_find_class_structure_array_clicked();
    void on_find_function_clicked();
    void on_find_changing_variables_clicked();
    void on_find_local_variables_clicked();
    void on_find_overload_functions_clicked();
    void on_find_depth_clicked();
    void on_find_logic_errors_clicked();
    void on_open_file_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
