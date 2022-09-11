#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <cmath>

#include "figure.h"
#include "polygon.h"
#include "star.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "five_point_star.h"
#include "six_point_star.h"
#include "eight_point_star.h"
#include "hexagon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "ellipse.h"
#include "canva.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_right_Rotation_pressed();
    void on_left_Rotation_pressed();

    void on_Move_right_pressed();
    void on_Move_left_pressed();
    void on_Move_up_pressed();
    void on_Move_down_pressed();

    void on_Scale_increase_pressed();
    void on_Scale_decrease_pressed();

    void on_button_add_Circle_clicked();

    void on_button_add_Square_clicked();

    void on_button_add_5pointstar_clicked();

    void on_button_add_6pointstar_clicked();

    void on_button_add_8pointstar_clicked();

    void on_button_add_Triangle_clicked();

    void on_button_add_Hexagon_clicked();

    void on_button_area_clicked();


    void on_button_perimeter_clicked();

    void on_button_add_Rectangle_clicked();

    void on_button_add_Rhombus_clicked();

    void on_button_add_Ellipse_clicked();

    void on_button_coordinates_clicked();

    void on_button_add_canva_clicked();

    void on_button_delete_canva_clicked();

    void on_change_figure_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Figure* object = 0;
    Canva* paint;
    void nullpointer();
    void clear();
    void enabled_true();
    void enabled_false();

};
#endif // MAINWINDOW_H
