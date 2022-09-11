#include "base.h"
#include<QPainter>


Base::Base(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

QRectF Base::boundingRect() const
{
     return QRectF(-400,-300,800,600);
}

Base::~Base()
{

}

void Base::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-50, 0) << QPoint(-30,20) << QPoint(50,20)<< QPoint(50,-20) << QPoint(-30, -20) << QPoint(-50,0);
    painter->setBrush(QBrush("#8E8E8E"));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Base::Move_r()
{
    this->moveBy(10,0);
    if(this->x() + 10 > 300)
    {
        this->setX(290);
    }
}

void Base::Move_l()
{
    this->moveBy(-10,0);
    if(this->x() - 10 < -300)
    {
        this->setX(-290);
    }
}

void Base::Move_up()
{
    this->moveBy(0,-10);
    if(this->y() - 10 < -200)
    {
        this->setY(-190);
    }
}

void Base::Move_down()
{
    this->moveBy(0,10);
    if(this->y()  + 10 > 200)
    {
        this->setY(190);
    }
}






