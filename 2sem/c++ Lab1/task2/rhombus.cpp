#include "rhombus.h"
#include<QPainter>

Rhombus::Rhombus(QObject *parent, int temp_d1, int temp_d2) :
    Figure(parent)
{
    d1 = temp_d1;
    d2 = temp_d2;
}

Rhombus::~Rhombus()
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-d2/2, 0) << QPoint(0, -d1/2) << QPoint(d2/2, 0) << QPoint(0, d1/2);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Rhombus::Area()
{
    return (d1 * d2/2);
}

double Rhombus::Perimeter()
{
    return (2 * sqrt(d1 * d1 + d2 * d2));
}
