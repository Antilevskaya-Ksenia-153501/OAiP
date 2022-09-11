#include "window.h"
#include <QPainter>

Window::Window(QObject* parent):
    Base(parent)
{

}
Window::~Window()
{

}
void Window::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-5, -15 , 30, 30);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
