QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canva.cpp \
    circle.cpp \
    eight_point_star.cpp \
    ellipse.cpp \
    figure.cpp \
    five_point_star.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    polygon.cpp \
    rectangle.cpp \
    rhombus.cpp \
    six_point_star.cpp \
    square.cpp \
    star.cpp \
    triangle.cpp

HEADERS += \
    canva.h \
    circle.h \
    eight_point_star.h \
    ellipse.h \
    figure.h \
    five_point_star.h \
    hexagon.h \
    mainwindow.h \
    polygon.h \
    rectangle.h \
    rhombus.h \
    six_point_star.h \
    square.h \
    star.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
