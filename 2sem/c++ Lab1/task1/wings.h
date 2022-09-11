#ifndef WINGS_H
#define WINGS_H

#include <QObject>
#include <QGraphicsItem>
#include "base.h"

class Wings: public Base
{
    Q_OBJECT

public:
    Wings(QObject* parent = 0);
    ~Wings();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WINGS_H
