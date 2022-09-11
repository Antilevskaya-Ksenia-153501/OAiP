#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QGraphicsItem>
#include "base.h"

class Window: public Base
{
    Q_OBJECT

public:
    Window(QObject* parent = 0);
    ~Window();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WINDOW_H
