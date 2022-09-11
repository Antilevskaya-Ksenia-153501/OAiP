#ifndef ROCKET_H
#define ROCKET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include "base.h"
#include "window.h"
#include "wings.h"
#include "fire.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Rocket; }
QT_END_NAMESPACE

class Rocket : public QWidget
{
    Q_OBJECT

public:
    Rocket(QWidget *parent = nullptr);
    ~Rocket();

private:
    Ui::Rocket *ui;
    QGraphicsScene  *scene;
    Base* base1;
    Window* window1;
    Wings* wings1;
    Fire* fire1;
private slots:
    void on_button_move_up_pressed();
    void on_button_move_right_pressed();
    void on_button_move_left_pressed();
    void on_button_move_down_pressed();
};
#endif // ROCKET_H
