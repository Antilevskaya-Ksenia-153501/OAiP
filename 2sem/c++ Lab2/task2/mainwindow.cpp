#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFileDialog>
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString* MainWindow::AddNewItem(QString* person, const int count)
{
    if (count == 0)
    {
        person = new QString[count + 1];
    }
    else
    {
        QString* tempPerson = new QString[count + 1];
        for (int i = 0; i < count; i++)
        {
            tempPerson[i] = person[i];
        }
        delete[] person;
        person = tempPerson;
    }
    return person;
}

bool MainWindow::checking(QString *t, int size)
{
    Stack st;
    Stack temp_st;
    QChar ch;
    QChar bracket;
    QString temp;
    for (int i = 0; i < size; i++)
    {
        temp = t[i];
        for (int j = 0; j < t[i].size(); ++j)
        {
        ch = temp[j];

        switch (ch.unicode())
        {
        case '(':
        case '{':
        case '[':
            st.push(ch, i+1, j+1);
            temp_st.push(ch, i+1, j+1);
            break;

        case ')':
        case '}':
        case ']':
            if (st.st_empty())
            {
                row = i + 1;
                column = j + 1;
                return false;
            }
            bracket = st.peek();
            switch (bracket.unicode())
            {
            case '(': bracket = ')'; break;
            case '{': bracket = '}'; break;
            case '[': bracket = ']'; break;
            }
            if (bracket != ch)
            {
                QChar temp;
                int x1;
                while(!(temp_st.st_empty()))
                {
                    temp = temp_st.peek();
                    x1 = temp_st.peek_x();
                    temp_st.pop();
                }
                if ((temp.unicode() == '{' && ch == '}') || (temp.unicode() == '[' && ch == ']') || (temp.unicode() == '(' && ch == ')'))
                {
                    while(st.peek_x() != x1)
                    {
                        row = st.peek_x();
                        column = st.peek_y();
                        st.pop();}
                    }
                else
                {
                    row = i+1;
                    column = j+1;
                }
                return false;
            }
            st.pop();
            temp_st.pop();
            break;
        default: break;
        }
      }
    }
    while(!(temp_st.st_empty()))
    {
        temp = temp_st.peek();
        row = temp_st.peek_x();
        column = temp_st.peek_y();
        temp_st.pop();
    }
    return st.st_empty() ? true : false;

}

void MainWindow::on_check_textEdit_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QTextStream stream(&text);
    QString temp;
    QString* mas = 0;
    int size = 0;
    for (int i = 0; temp != "\n" && (!stream.atEnd()); i++)
    {
        temp = stream.readLine();
        mas = AddNewItem(mas,size);
        mas[i] = temp;
        size++;
    }
    bool verification = checking(mas,size);
    if (verification)
    {
        QMessageBox::information(this, "ERROR","Correct");
        return;
    }
    else
    {
        QString message = "Incorrect!!! Row: " + QString::number(row) + " Column: " + QString::number(column);
        QMessageBox::information(this, "ERROR", message);
        return;
    }
}

void MainWindow::on_check_file_clicked()
{
    filePath = QFileDialog:: getOpenFileName(this,"Choose file", "C:\\Users\\Notebook\\Desktop\\Study\\c++ Labs 2 sem\\c++ Lab2\\task2.txt", "Text File (*.txt)");
    QFile File(filePath);
    if (!File.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "ERROR", "Can't open the file");
        return;
    }
    else if (File.size() == 0)
    {
        QMessageBox::information(this, "ERROR", "The file is empty");
        return;
    }
    QTextStream stream(&File);
    QString text;
    QString* mas = 0;
    int size = 0;
    for (int i = 0; text != "\n" && (!stream.atEnd()); i++)
    {
        text = stream.readLine();
        mas = AddNewItem(mas,size);
        mas[i] = text;
        size++;
    }
    File.close();
    bool verification = checking(mas,size);
    if (verification)
    {
        QMessageBox::information(this, "ERROR","Correct");
        return;
    }
    else
    {
        QString message = "Incorrect!!! Row: " + QString::number(row) + " Column: " + QString::number(column);
        QMessageBox::information(this, "ERROR", message);
        return;
    }
}

