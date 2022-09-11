#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void* Memcpy(void* s1, const void* s2, size_t n);
    void* Memmove(void* s1, const void* s2, size_t n);
    char* Strcpy(char* s1, const char* s2);
    char* Strncpy(char* s1, const char* s2, size_t n);
    char* Strcat(char* s1, const char* s2);
    char* Strncat(char* s1, const char* s2, size_t n);
    int Memcmp(const void* s1, const void* s2, size_t n);
    int Strcmp(const char* s1, const char* s2);
    int Strcoll(const char* s1, const char* s2);
    int Strncmp(const char* s1, const char* s2, size_t n);
    char* Strtok(char* s1,  char* s2);
    void* Memset(void* s, int c, size_t n);
    size_t Strlen(const char* str);

private slots:
    void on_button_memcpy_clicked();
    void on_button_memmove_clicked();
    void on_button_strcpy_clicked();
    void on_button_strncpy_clicked();
    void on_button_strcat_clicked();
    void on_button_strncat_clicked();
    void on_button_memcmp_clicked();
    void on_button_strcmp_clicked();
    void on_button_strcoll_clicked();
    void on_button_strncmp_clicked();
    void on_button_strlen_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
