#ifndef SIX_POINT_STAR_H
#define SIX_POINT_STAR_H

#include <QObject>
#include <QGraphicsItem>
#include "star.h"

class six_point_star: public Star
{
    Q_OBJECT
public:
    six_point_star(QObject* parent = 0, int n_temp = 0, int r_temp = 0, int R_temp = 0);
    ~six_point_star();
};

#endif // SIX_POINT_STAR_H
