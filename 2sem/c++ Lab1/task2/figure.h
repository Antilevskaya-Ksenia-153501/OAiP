#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>

class Figure: public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
    Figure(QObject *parent = 0);
    ~Figure();
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)= 0;
    void Rotation_r();
    void Rotation_l();
    void Move_r();
    void Move_l();
    void Move_up();
    void Move_down();
    void Scale_i();
    void Scale_d();
    virtual double Area()= 0;
    virtual double Perimeter()= 0;
    int x1 = 0;
    int y1 = 0;

private:
    double angle = 0;
    double scale = 1;


};

#endif // FIGURE_H
