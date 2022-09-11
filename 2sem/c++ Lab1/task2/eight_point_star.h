#ifndef EIGHT_POINT_STAR_H
#define EIGHT_POINT_STAR_H

#include <QObject>
#include <QGraphicsItem>
#include "star.h"

class eight_point_star: public Star
{
public:
    eight_point_star(QObject* parent = 0, int n_temp = 0, int r_temp = 0, int R_temp = 0);
    ~eight_point_star();
};

#endif // EIGHT_POINT_STAR_H
