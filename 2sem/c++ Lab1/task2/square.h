#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "polygon.h"

class Square: public Polygon
{
    Q_OBJECT
public:
    Square(QObject* parent = 0, int temp_R = 0, int temp_n = 0);
    ~Square();

};

#endif // SQUARE_H
