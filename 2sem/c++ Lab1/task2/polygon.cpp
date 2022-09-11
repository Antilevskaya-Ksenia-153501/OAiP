#include "polygon.h"
#include<QPainter>

Polygon::Polygon(QObject* parent, int temp_R, int temp_n):
    Figure(parent)
{
    R = temp_R;
    n = temp_n;
}

Polygon::~Polygon()
{

}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float a = 360/n;
    float angle;
    int* point_x = new int [n];
    int* point_y = new int [n];
    for(int i = 0; i < n; i++)
    {
        angle = a*i;
        point_x[i] = -R*sin(angle*M_PI/180);
        point_y[i] = -R*cos(angle*M_PI/180);
    }
    QPolygon polygon;
    for(int i = 0; i < n; i++)
    {
      polygon << QPoint(point_x[i], point_y[i]);
    }
    painter->setBrush(Qt::green);
    painter->drawPolygon(polygon);
    delete[]  point_x;
    delete[]  point_y;
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Polygon::Area()
{
    return ((n/2) * R * R * sin(2*M_PI/n));
}

double Polygon::Perimeter()
{
    return (n * 2 * R * sin(M_PI/n));
}
