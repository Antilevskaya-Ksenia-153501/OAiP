#include "figure.h"

Figure::Figure(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Figure::~Figure()
{

}
QRectF Figure::boundingRect() const
{
    return QRectF(-350,-250,700,500);
}

void Figure::Rotation_r()
{
    angle += 3;
    this->setRotation(angle);
}

void Figure::Rotation_l()
{
    angle -= 3;
    this->setRotation(angle);
}

void Figure::Move_r()
{
    this->moveBy(10,0);
    x1 += 10;
}

void Figure::Move_l()
{
    this->moveBy(-10,0);
    x1 -= 10;
}

void Figure::Move_up()
{
    this->moveBy(0,-10);
    y1 -= 10;

}

void Figure::Move_down()
{
    this->moveBy(0,10);
    y1 += 10;
}

void Figure::Scale_i()
{

    scale *= 1.5;
    this->setScale(scale);
}

void Figure::Scale_d()
{
    scale /= 1.5;
    this->setScale(scale);
}
