#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Star:public Figure
{
    Q_OBJECT
public:
    Star(QObject* parent = 0, int n_temp = 0, int r_temp = 0, int R_temp = 0);
    ~Star();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double Area();
    double Perimeter();
    int n;
    int r;
    int R;
};

#endif // STAR_H
