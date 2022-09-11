#include "circle.h"
#include<QPainter>

Circle::Circle(QObject *parent, int R_temp) :
    Figure(parent)
{
    R = R_temp;
}

Circle::~Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(-R, -R, 2 * R, 2 * R);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Circle::Area()
{
    return (M_PI * R * R);
}

double Circle::Perimeter()
{
    return (2 * M_PI * R);
}

