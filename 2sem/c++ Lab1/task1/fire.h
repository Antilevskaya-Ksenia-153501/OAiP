#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include <QGraphicsItem>
#include "base.h"

class Fire: public Base
{
    Q_OBJECT

public:
    Fire(QObject*parent = 0);
    ~Fire();
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FIRE_H
