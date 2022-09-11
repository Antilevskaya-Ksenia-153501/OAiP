#ifndef POLYGON_H
#define POLYGON_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Polygon: public Figure
{
    Q_OBJECT
public:
    Polygon(QObject* parent = 0, int temp_R = 0, int temp_n = 0);
    ~Polygon();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double Area();
    double Perimeter();
    int R;
    int n;
;};

#endif // POLYGON_H
