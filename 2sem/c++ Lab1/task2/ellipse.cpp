#include "ellipse.h"
#include<QPainter>

Ellipse::Ellipse(QObject *parent, int temp_a, int temp_b) :
    Figure(parent)
{
    a = temp_a;
    b = temp_b;
}

Ellipse::~Ellipse()
{

}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(-b/2, -a/2, b, a);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Ellipse::Area()
{
    return (M_PI * a * b);
}

double Ellipse::Perimeter()
{
    return (2 * M_PI * sqrt((a * a + b * b)/8));
}

