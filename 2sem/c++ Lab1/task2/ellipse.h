#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Ellipse: public Figure
{
    Q_OBJECT
public:
    Ellipse(QObject* parent = 0, int temp_a = 0, int temp_b = 0);
    ~Ellipse();
    int a = 0;
    int b = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double Area();
    double Perimeter();

};

#endif // ELLIPSE_H
