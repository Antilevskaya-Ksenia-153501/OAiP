#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "polygon.h"

class Triangle: public Polygon
{
    Q_OBJECT
public:
    Triangle(QObject* parent = 0, int temp_R = 0, int temp_n = 0);
    ~Triangle();

};

#endif // TRIANGLE_H
