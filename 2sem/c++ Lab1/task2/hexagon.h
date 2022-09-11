#ifndef HEXAGON_H
#define HEXAGON_H

#include <QObject>
#include <QGraphicsItem>
#include "polygon.h"

class Hexagon: public Polygon
{
public:
    Hexagon(QObject* parent = 0, int temp_R = 0, int temp_n = 0);
    ~Hexagon();
};

#endif // HEXAGON_H
