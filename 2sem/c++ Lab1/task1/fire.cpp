#include "fire.h"
#include<QPainter>

Fire::Fire(QObject* parent):
    Base(parent)
{

}

Fire::~Fire()
{

}

void Fire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(50,-20) << QPoint(70, -30) << QPoint(60, -10) << QPoint(70, 0) << QPoint(60, 10) << QPoint(70, 30) << QPoint(50, 20);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
