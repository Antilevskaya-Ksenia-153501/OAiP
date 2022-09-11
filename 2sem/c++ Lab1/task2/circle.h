#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Circle:public Figure
{
    Q_OBJECT
public:
    Circle(QObject* parent = 0, int R_temp = 0);
    ~Circle();
     int R;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
     double Area();
     double Perimeter();

};

#endif // CIRCLE_H
