#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rhombus: public Figure
{
public:
    Rhombus(QObject* parent = 0, int temp_d1 = 0, int temp_d2 = 0);
    ~Rhombus();
    int d1;
    int d2;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double Area();
    double Perimeter();
};

#endif // RHOMBUS_H
