QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += "C:\Users\Notebook\Desktop\Study\c++ Labs 2 sem\c++ Lab4\MyStringLib(QT)\build-MyStringLib-Desktop_Qt_6_2_3_MinGW_64_bit-Debug\debug\MyStringLib.dll"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MyStringLib_global.h \
    mainwindow.h \
    mystring.h \
    myvector.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

