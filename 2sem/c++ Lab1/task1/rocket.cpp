#include "rocket.h"
#include "ui_rocket.h"

Rocket::Rocket(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rocket)
{
    ui->setupUi(this);
    this->resize(800,600);
    this->setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene->setSceneRect(-300,-200,600,400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    base1 = new Base;
    window1 = new Window;
    wings1 = new Wings;
    fire1 = new Fire();
    scene->addItem(base1);
    base1->setPos(0,0);
    scene->addItem(window1);
    scene->addItem(wings1);
    scene->addItem(fire1);
}

Rocket::~Rocket()
{
    delete ui;
}

void Rocket::on_button_move_up_pressed()
{
    base1->Move_up();
    window1->Move_up();
    wings1->Move_up();
    fire1->Move_up();
}


void Rocket::on_button_move_right_pressed()
{
    base1->Move_r();
    window1->Move_r();
    wings1->Move_r();
    fire1->Move_r();
}


void Rocket::on_button_move_left_pressed()
{
    base1->Move_l();
    window1->Move_l();
    wings1->Move_l();
    fire1->Move_l();
}


void Rocket::on_button_move_down_pressed()
{
    base1->Move_down();
    window1->Move_down();
    wings1->Move_down();
    fire1->Move_down();
}
