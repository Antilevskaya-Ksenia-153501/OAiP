#include "canva.h"

Canva::Canva(QObject *parent) : QGraphicsScene(parent)
{

}

Canva::~Canva()
{

}

void Canva::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - 5, event->scenePos().y() - 5, 10, 10, QPen(Qt::NoPen), QBrush(Qt::black));
    previousPoint = event->scenePos();
}

void Canva::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(), previousPoint.y(), event->scenePos().x(), event->scenePos().y(), QPen(Qt::black,10,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
