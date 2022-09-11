#ifndef CANVA_H
#define CANVA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class Canva: public QGraphicsScene
{
    Q_OBJECT
public:
    Canva(QObject *parent = 0);
    ~Canva();

private:
    QPointF previousPoint;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CANVA_H
