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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *buttonFlip;
    QLineEdit *line_set;
    QPushButton *buttonSet;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_reset;
    QPushButton *buttonReset;
    QPushButton *buttonAll;
    QLabel *resAll;
    QPushButton *buttonUlong;
    QLabel *resTo_Ulong;
    QPushButton *buttonUllong;
    QLabel *resTo_Ullong;
    QPushButton *buttonAny;
    QLabel *resAny;
    QPushButton *buttonNone;
    QLabel *resNone;
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
        plainTextEdit->setGeometry(QRect(20, 20, 571, 411));
        buttonFlip = new QPushButton(centralwidget);
        buttonFlip->setObjectName(QString::fromUtf8("buttonFlip"));
        buttonFlip->setGeometry(QRect(620, 50, 75, 24));
        line_set = new QLineEdit(centralwidget);
        line_set->setObjectName(QString::fromUtf8("line_set"));
        line_set->setGeometry(QRect(620, 120, 113, 22));
        buttonSet = new QPushButton(centralwidget);
        buttonSet->setObjectName(QString::fromUtf8("buttonSet"));
        buttonSet->setGeometry(QRect(750, 120, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 90, 151, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 160, 161, 16));
        line_reset = new QLineEdit(centralwidget);
        line_reset->setObjectName(QString::fromUtf8("line_reset"));
        line_reset->setGeometry(QRect(620, 190, 113, 22));
        buttonReset = new QPushButton(centralwidget);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        buttonReset->setGeometry(QRect(750, 190, 75, 24));
        buttonAll = new QPushButton(centralwidget);
        buttonAll->setObjectName(QString::fromUtf8("buttonAll"));
        buttonAll->setGeometry(QRect(620, 250, 75, 24));
        resAll = new QLabel(centralwidget);
        resAll->setObjectName(QString::fromUtf8("resAll"));
        resAll->setGeometry(QRect(710, 245, 111, 31));
        buttonUlong = new QPushButton(centralwidget);
        buttonUlong->setObjectName(QString::fromUtf8("buttonUlong"));
        buttonUlong->setGeometry(QRect(620, 300, 75, 24));
        resTo_Ulong = new QLabel(centralwidget);
        resTo_Ulong->setObjectName(QString::fromUtf8("resTo_Ulong"));
        resTo_Ulong->setGeometry(QRect(710, 300, 121, 21));
        buttonUllong = new QPushButton(centralwidget);
        buttonUllong->setObjectName(QString::fromUtf8("buttonUllong"));
        buttonUllong->setGeometry(QRect(620, 340, 75, 24));
        resTo_Ullong = new QLabel(centralwidget);
        resTo_Ullong->setObjectName(QString::fromUtf8("resTo_Ullong"));
        resTo_Ullong->setGeometry(QRect(710, 340, 151, 21));
        buttonAny = new QPushButton(centralwidget);
        buttonAny->setObjectName(QString::fromUtf8("buttonAny"));
        buttonAny->setGeometry(QRect(620, 380, 75, 24));
        resAny = new QLabel(centralwidget);
        resAny->setObjectName(QString::fromUtf8("resAny"));
        resAny->setGeometry(QRect(710, 380, 121, 21));
        buttonNone = new QPushButton(centralwidget);
        buttonNone->setObjectName(QString::fromUtf8("buttonNone"));
        buttonNone->setGeometry(QRect(620, 420, 75, 24));
        resNone = new QLabel(centralwidget);
        resNone->setObjectName(QString::fromUtf8("resNone"));
        resNone->setGeometry(QRect(710, 421, 131, 20));
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
        buttonFlip->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        buttonSet->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter position to change:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter position to change:", nullptr));
        buttonReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        buttonAll->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        resAll->setText(QString());
        buttonUlong->setText(QCoreApplication::translate("MainWindow", "To_Ulong", nullptr));
        resTo_Ulong->setText(QString());
        buttonUllong->setText(QCoreApplication::translate("MainWindow", "To_Ullong", nullptr));
        resTo_Ullong->setText(QString());
        buttonAny->setText(QCoreApplication::translate("MainWindow", "Any", nullptr));
        resAny->setText(QString());
        buttonNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        resNone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
