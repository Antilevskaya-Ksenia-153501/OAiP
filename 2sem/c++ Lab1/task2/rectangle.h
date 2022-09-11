#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rectangle: public Figure
{
    Q_OBJECT
public:
    Rectangle(QObject* parent = 0, int temp_a = 0, int temp_b = 0);
    ~Rectangle();
    int a;
    int b;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double Area();
    double Perimeter();
};

#endif // RECTANGLE_H
