#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "stack_qchar.h"
#include "stack_double.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString result;
    int prec(QChar c);
    QString infixToPostfix(QString s);
    double evaluatePostfix(QString exp , double a = 0, double b = 0, double c = 0, double d = 0, double e = 0);
private slots:
    void on_button_calculate_clicked();
    void on_button_postfix_convertation_clicked();
    void verification();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
