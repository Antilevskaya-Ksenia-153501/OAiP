/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QPushButton *find_types_of_variables;
    QPlainTextEdit *plainTextEdit_Output;
    QPushButton *find_class_structure_array;
    QPushButton *find_function;
    QPushButton *find_changing_variables;
    QPushButton *find_local_variables;
    QPushButton *find_overload_functions;
    QPushButton *find_depth;
    QPushButton *find_logic_errors;
    QPushButton *open_file;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 20, 461, 421));
        QFont font;
        font.setFamilies({QString::fromUtf8("GeoSlab703 MdCn BT")});
        font.setPointSize(13);
        plainTextEdit->setFont(font);
        find_types_of_variables = new QPushButton(centralwidget);
        find_types_of_variables->setObjectName(QString::fromUtf8("find_types_of_variables"));
        find_types_of_variables->setGeometry(QRect(520, 20, 101, 31));
        find_types_of_variables->setFont(font);
        plainTextEdit_Output = new QPlainTextEdit(centralwidget);
        plainTextEdit_Output->setObjectName(QString::fromUtf8("plainTextEdit_Output"));
        plainTextEdit_Output->setGeometry(QRect(670, 20, 511, 421));
        plainTextEdit_Output->setFont(font);
        find_class_structure_array = new QPushButton(centralwidget);
        find_class_structure_array->setObjectName(QString::fromUtf8("find_class_structure_array"));
        find_class_structure_array->setGeometry(QRect(510, 60, 131, 31));
        find_class_structure_array->setFont(font);
        find_function = new QPushButton(centralwidget);
        find_function->setObjectName(QString::fromUtf8("find_function"));
        find_function->setGeometry(QRect(530, 100, 81, 31));
        find_function->setFont(font);
        find_changing_variables = new QPushButton(centralwidget);
        find_changing_variables->setObjectName(QString::fromUtf8("find_changing_variables"));
        find_changing_variables->setGeometry(QRect(510, 140, 121, 31));
        find_changing_variables->setFont(font);
        find_local_variables = new QPushButton(centralwidget);
        find_local_variables->setObjectName(QString::fromUtf8("find_local_variables"));
        find_local_variables->setGeometry(QRect(530, 180, 91, 31));
        find_local_variables->setFont(font);
        find_overload_functions = new QPushButton(centralwidget);
        find_overload_functions->setObjectName(QString::fromUtf8("find_overload_functions"));
        find_overload_functions->setGeometry(QRect(520, 220, 111, 31));
        find_overload_functions->setFont(font);
        find_depth = new QPushButton(centralwidget);
        find_depth->setObjectName(QString::fromUtf8("find_depth"));
        find_depth->setGeometry(QRect(530, 260, 81, 31));
        find_depth->setFont(font);
        find_logic_errors = new QPushButton(centralwidget);
        find_logic_errors->setObjectName(QString::fromUtf8("find_logic_errors"));
        find_logic_errors->setGeometry(QRect(530, 300, 81, 31));
        find_logic_errors->setFont(font);
        open_file = new QPushButton(centralwidget);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        open_file->setGeometry(QRect(540, 460, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("GeoSlab703 MdCn BT")});
        font1.setPointSize(14);
        open_file->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        find_types_of_variables->setText(QCoreApplication::translate("MainWindow", "types(int, float...)", nullptr));
        find_class_structure_array->setText(QCoreApplication::translate("MainWindow", "class/structure/array", nullptr));
        find_function->setText(QCoreApplication::translate("MainWindow", "functions", nullptr));
        find_changing_variables->setText(QCoreApplication::translate("MainWindow", "changing variables", nullptr));
        find_local_variables->setText(QCoreApplication::translate("MainWindow", "local variables", nullptr));
        find_overload_functions->setText(QCoreApplication::translate("MainWindow", "overload functions", nullptr));
        find_depth->setText(QCoreApplication::translate("MainWindow", "depth ", nullptr));
        find_logic_errors->setText(QCoreApplication::translate("MainWindow", "logic errors", nullptr));
        open_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
