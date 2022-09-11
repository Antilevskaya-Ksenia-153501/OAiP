#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filePath;
    int row = 0, column = 0;
private slots:
    void on_check_textEdit_clicked();
    bool checking(QString* t, int size);
    QString* AddNewItem(QString* person, const int amount);
    void on_check_file_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
