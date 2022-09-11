#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);
    ui->button_calculate->setEnabled(false);
    ui->line_a->setInputMask("0.0");
    ui->line_b->setInputMask("0.0");
    ui->line_c->setInputMask("0.0");
    ui->line_d->setInputMask("0.0");
    ui->line_e->setInputMask("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::verification()
{
    QString check;
    int count = 0;
    check = ui->infix_notation->text();
    for(int i = 0; i < check.length(); i++)
    {
       if (check[i] == 'a' || check[i] == 'b' || check[i] == 'c' || check[i] == 'd' || check[i] == 'e' || check[i] == '+' || check[i] == '-' || check[i] == '/' || check[i] == '*' || check[i] == '(' || check[i] == ')')
           continue;
       else
           ++count;
    }
    if (count)
    {
        QMessageBox::information(this, "ERROR","Incorrect. Expression can only consist of 'a, b, c, d, e, +, -, =, /, *, (, )' ");
        ui->infix_notation ->clear();
        return;
    }
}

int MainWindow::prec(QChar c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

QString MainWindow::infixToPostfix(QString formula)
{
    Stack_QChar st;
    QString result;
    for(int i = 0; i < formula.length(); i++)
    {
        QChar c = formula[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if(c == '(')
        {
            st.push('(');
        }
        else if(c == ')')
        {
            while(st.peek() != '(')
            {
                result += st.peek();
                st.pop();
            }
        st.pop();
        }
        else
        {
            while(!st.formula_empty() && prec(formula[i]) <= prec(st.peek()))
            {
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.formula_empty())
    {
        result += st.peek();
        st.pop();
    }
    return result;
}

double MainWindow::evaluatePostfix(QString exp, double a, double b, double c, double d, double e)
{
    Stack_Double st;
    for (int i = 0; i < exp.size(); ++i)
    {
        if(exp[i] == 'a' || exp[i] == 'b' || exp[i] == 'c' || exp[i] == 'd' ||exp[i] == 'e')
        {
            if (exp[i].unicode() == 'a')
                st.push(a);
            if (exp[i].unicode() == 'b')
                st.push(b);
            if (exp[i].unicode() == 'c')
                st.push(c);
            if (exp[i].unicode() == 'd')
                st.push(d);
            if (exp[i].unicode() == 'e')
                st.push(e);
        }
        else
        {
            double val1 = st.peek();
            st.pop();
            double val2 = st.peek();
            st.pop();
            switch (exp[i].unicode())
            {
            case '+': st.push(val2 + val1); break;
            case '-': st.push(val2 - val1); break;
            case '*': st.push(val2 * val1); break;
            case '/': st.push(val2 / val1); break;
            }
        }
    }
    return st.peek();
}

void MainWindow::on_button_postfix_convertation_clicked()
{
    if (ui->infix_notation->text().isEmpty())
    {
        QMessageBox::information(this, "ERROR","The line is empty");
        return;
    }
    verification();
    ui->button_calculate->setEnabled(true);
    result = infixToPostfix(ui->infix_notation->text());
    ui->postfix_notation->setText(result);
}

void MainWindow::on_button_calculate_clicked()
{
    double calculation = evaluatePostfix(result, ui->line_a->text().toDouble(), ui->line_b->text().toDouble(), ui->line_c->text().toDouble(), ui->line_d->text().toDouble(), ui->line_e->text().toDouble());
    ui->label_result->setText(QString::number(calculation));
    ui->line_a->clear();
    ui->line_b->clear();
    ui->line_c->clear();
    ui->line_d->clear();
    ui->line_e->clear();
}
