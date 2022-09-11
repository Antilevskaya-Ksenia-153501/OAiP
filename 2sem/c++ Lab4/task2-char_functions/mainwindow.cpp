#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 600);
    this->setFixedSize(1200,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void *MainWindow::Memcpy(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr || n <= 0)
        return NULL;
    char* temp_s1 = (char*)s1;
    const char* temp_s2 = (const char*)s2;
    for (size_t i = 0; i < n; i++)
        temp_s1[i] = temp_s2[i];
    return s1;
}

void *MainWindow::Memmove(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr || n <= 0)
        return NULL;
    char* temp_s1 = (char*)s1;
    const char* temp_s2 = (const char*)s2;
    char* temp = new char[n];
    for (size_t i = 0; i < n; i++)
        temp[i] = temp_s2[i];
    for (size_t i = 0; i < n; i++)
        temp_s1[i] = temp[i];
    delete[] temp;
    return s1;
}

char *MainWindow::Strcpy(char *s1, const char *s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return NULL;
    char* temp_s1 = s1;
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return temp_s1;
}

char *MainWindow::Strncpy(char *s1, const char *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr)
        return NULL;
    char* temp_s1 = s1;
    while (*s2 != '\0' && n--)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    return temp_s1;
}

char *MainWindow::Strcat(char *s1, const char *s2)
{
    int i, j;
    char* temp_s1 = s1;
    for (i = 0; s1[i] != '\0'; i++);
    for (j = 0; s2[j] != '\0'; j++)
        s1[i + j] = s2[j];
    s1[i + j] = '\0';
    return temp_s1;
}

char *MainWindow::Strncat(char *s1, const char *s2, size_t n)
{
    char* temp_s1 = s1;
    int i, j = 0;
    for (i = 0; s1[i] != '\0'; i++);
    while (s2[j] != '\0' && n--)
    {
        s1[i + j] = s2[j];
        j++;
    }
    s1[i + j] = '\0';
    return temp_s1;
}

int MainWindow::Memcmp(const void *s1, const void *s2, size_t n)
{
    const char* temp_s1 = (const char*)s1;
    const char* temp_s2 = (const char*)s2;
    int a, b;
    for (size_t i = 0; i < n; i++)
    {
        a = (int)temp_s1[i];
        b = (int)temp_s2[i];
        if ((a < b) || (a > b))
            return (a - b);
    }
    return 0;
}

int MainWindow::Strcmp(const char *s1, const char *s2)
/*Нулевое значение говорит о том, что обе строки равны.
    Значение больше нуля указывает на то, что строка string1 больше строки string2, значение меньше нуля свидетельствует об обратном.
    Функция strcmp начинает сравнивать по одному символу и как только будут найдены первые неодинаковые символы, чей код окажется больше, та строка и будет считаться большей.*/
{
    int temp = 0;
    while (!(temp = *(unsigned char*)s1 - *(unsigned char*)s2) && *s1)
    {
        s1++;
        s2++;
    }
    if (temp < 0)
        return -1;
    else if (temp > 0)
        return 1;
    return 0;
}

int MainWindow::Strcoll(const char *s1, const char *s2)
{
    int temp = 0;
    while (!(temp = *(unsigned char*)s1 - *(unsigned char*)s2) && *s1)
    {
        s1++;
        s2++;
    }
    if (temp < 0)
        return -1;
    else if (temp > 0)
        return 1;
    return 0;
}

int MainWindow::Strncmp(const char *s1, const char *s2, size_t n)
{
    int temp = 0;
    while (*s1 != '\0' && *s2 != '\0' && n && !(temp = *(unsigned char*)s1 - *(unsigned char*)s2))
    {
        s1++;
        s2++;
        n--;
    }
    if (temp < 0)
        return -1;
    else if (temp > 0)
        return 1;
    return 0;
}

char *MainWindow::Strtok(char *s1, char *s2)
{
    static char* input = NULL;
    if (s1 != NULL)
        input = s1;
    if (input == NULL)
        return NULL;

    char* result = new char[strlen(input) + 1];
    int i = 0;

    for (; input[i] != '\0'; i++)
    {
        if (input[i] != *s2)
            result[i] = input[i];

        else
        {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }
    result[i] = '\0';
    input = NULL;
    return result;
}

void *MainWindow::Memset(void *s, int c, size_t n)
{
    unsigned char* s_temp = (unsigned char*)s;
    while (n--)
    {
        *s_temp++ = (char)c;
    }
    return s;
}

size_t MainWindow::Strlen(const char *str)
{
    int size = 0;
    if (str != NULL)
    {
        while (*(str + size) != '\0')
            ++size;
    }
    return size;
}

void MainWindow::on_button_memcpy_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Memcpy((void*)first.c_str(), (void*)second.c_str(), 2);
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);

}

void MainWindow::on_button_memmove_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Memmove((void*)first.c_str(), (void*)second.c_str(), 2);
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strcpy_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Strcpy((char*)first.c_str(), second.c_str());
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strncpy_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Strncpy((char*)first.c_str(), second.c_str(), 2);
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strcat_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Strcat((char*)first.c_str(), second.c_str());
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strncat_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    void* temp_result = Strncat((char*)first.c_str(), second.c_str(), 2);
    QString result = (char*)temp_result;
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_memcmp_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    int temp_result = Memcmp(first.c_str(), second.c_str(), 2);
    QString result = QString::number(temp_result);
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strcmp_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    int temp_result = Strcmp(first.c_str(), second.c_str());
    QString result = QString::number(temp_result);
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strcoll_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    int temp_result = Strcoll(first.c_str(), second.c_str());
    QString result = QString::number(temp_result);
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strncmp_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    int temp_result = Strncmp(first.c_str(), second.c_str(), 2);
    QString result = QString::number(temp_result);
    ui->lineEdit_3->setText(result);
}

void MainWindow::on_button_strlen_clicked()
{
    QString temp_first = ui->lineEdit->text();
    std::string first = temp_first.toStdString();
    QString temp_second = ui->lineEdit_2->text();
    std::string second = temp_second.toStdString();
    int temp_result = Strlen(first.c_str());
    QString result = QString::number(temp_result);
    ui->lineEdit_3->setText(result);
}

