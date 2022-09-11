#include "rectangle.h"
#include<QPainter>

Rectangle::Rectangle(QObject *parent, int temp_a, int temp_b) :
    Figure(parent)
{
    a = temp_a;
    b = temp_b;
}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-a/2, -b/2) << QPoint(a/2, -b/2) << QPoint(a/2, b/2) << QPoint(-a/2, b/2);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Rectangle::Area()
{
    return (a * b);
}

double Rectangle::Perimeter()
{
    return (2 * a + 2 * b);
}
