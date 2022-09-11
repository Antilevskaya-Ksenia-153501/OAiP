#include "wings.h"
#include<QPainter>

Wings::Wings(QObject* parent):
    Base(parent)
{

}

Wings::~Wings()
{

}

void Wings::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon, polygon2;
    polygon << QPoint(0,20) << QPoint(50, 40) << QPoint(50, 20);
    polygon2 << QPoint(0,-20) << QPoint(50, -40) << QPoint(50, -20);
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(polygon);
    painter->drawPolygon(polygon2);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
