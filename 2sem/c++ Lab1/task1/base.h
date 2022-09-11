#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QGraphicsItem>

class Base : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
     Base(QObject *parent = 0);
    ~Base();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Move_r();
    void Move_l();
    void Move_up();
    void Move_down();

};

#endif
