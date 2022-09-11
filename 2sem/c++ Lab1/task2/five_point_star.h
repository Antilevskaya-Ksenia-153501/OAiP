#ifndef FIVE_POINT_STAR_H
#define FIVE_POINT_STAR_H

#include <QObject>
#include <QGraphicsItem>
#include "star.h"

class five_point_star: public Star
{
    Q_OBJECT
public:
    five_point_star(QObject* parent = 0,  int n_temp = 0, int r_temp = 0, int R_temp = 0);
    ~five_point_star();


};

#endif // FIVE_POINT_STAR_H
