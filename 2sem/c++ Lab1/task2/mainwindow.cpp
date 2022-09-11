#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,600);
    this->setFixedSize(1200,600);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lineEdit->setInputMask("999");
    ui->lineEdit_2->setInputMask("999");
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->change_figure->setEnabled(false);
    enabled_false();
    ui->button_delete_canva->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nullpointer()
{
    if(object)
    {
        delete object;
    }
}
void MainWindow::clear()
{
    ui->area->setText("");
    ui->perimeter->setText("");
    ui->label_x->setText("");
    ui->text_3->setText("");
    ui->label_y->setText("");
    ui->text_4->setText("");
}

void MainWindow::enabled_true()
{
    ui->left_Rotation->setEnabled(true);
    ui->right_Rotation->setEnabled(true);
    ui->Move_up->setEnabled(true);
    ui->Move_right->setEnabled(true);
    ui->Move_down->setEnabled(true);
    ui->Move_left->setEnabled(true);
    ui->Scale_increase->setEnabled(true);
    ui->Scale_decrease->setEnabled(true);
    ui->button_area->setEnabled(true);
    ui->button_perimeter->setEnabled(true);
    ui->button_coordinates->setEnabled(true);
}

void MainWindow::enabled_false()
{
    ui->left_Rotation->setEnabled(false);
    ui->right_Rotation->setEnabled(false);
    ui->Move_up->setEnabled(false);
    ui->Move_right->setEnabled(false);
    ui->Move_down->setEnabled(false);
    ui->Move_left->setEnabled(false);
    ui->Scale_increase->setEnabled(false);
    ui->Scale_decrease->setEnabled(false);
    ui->button_area->setEnabled(false);
    ui->button_perimeter->setEnabled(false);
    ui->button_coordinates->setEnabled(false);
}

void MainWindow::on_right_Rotation_pressed()
{
   object->Rotation_r();
}

void MainWindow::on_left_Rotation_pressed()
{
    object->Rotation_l();
}

void MainWindow::on_Move_right_pressed()
{
    object->Move_r();
}

void MainWindow::on_Move_left_pressed()
{
    object->Move_l();
}

void MainWindow::on_Move_up_pressed()
{
    object->Move_up();
}

void MainWindow::on_Move_down_pressed()
{
    object->Move_down();
}

void MainWindow::on_Scale_increase_pressed()
{
    object->Scale_i();
}

void MainWindow::on_Scale_decrease_pressed()
{
    object->Scale_d();
}

void MainWindow::on_button_add_Circle_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter radius:");
    ui->lineEdit->show();
    ui->text_2->setText("");
    ui->lineEdit_2->hide();
    enabled_true();
    this->nullpointer();
    object = new Circle(0, ui->lineEdit->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a circle");
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_Square_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    ui->text_2->setText("");
    ui->lineEdit_2->hide();
    enabled_true();
    this->nullpointer();
    object = new Square(0, ui->lineEdit->text().toInt(), 4);
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a square");
    ui->lineEdit->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}


void MainWindow::on_button_add_5pointstar_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    ui->text_2->setText("Enter inscribed circle radius:");
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new eight_point_star(0, 5, ui->lineEdit->text().toInt(),  ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a 5-point star");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_6pointstar_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    ui->text_2->setText("Enter inscribed circle radius:");
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new eight_point_star(0, 6, ui->lineEdit->text().toInt(),  ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a 6-point star");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_8pointstar_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    ui->text_2->setText("Enter inscribed circle radius:");
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new eight_point_star(0, 8, ui->lineEdit->text().toInt(),  ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a 8-point star");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_Triangle_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    enabled_true();
    this->nullpointer();
    object = new Triangle(0,ui->lineEdit->text().toInt(), 3);
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a triangle");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_Hexagon_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter circumcircle radius:");
    ui->lineEdit->show();
    enabled_true();
    this->nullpointer();
    object = new Hexagon(0,ui->lineEdit->text().toInt(), 6);
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a hexagon");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_Rectangle_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter lenght:");
    ui->lineEdit->show();
    ui->text_2->setText("Enter width:");
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new Rectangle(0,ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a rectangle");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);

}

void MainWindow::on_button_add_Rhombus_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter the first diagonal:");
    ui->lineEdit->show();
    ui->text_2->setText("Enter the second diagonal:");
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new Rhombus(0,ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose a rhombus");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_Ellipse_clicked()
{
    scene->clear();
    clear();
    ui->text_1->setText("Enter minor axis:");
    ui->text_2->setText("Enter major axis:");
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    enabled_true();
    this->nullpointer();
    object = new Ellipse(0,ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    scene->addItem(object);
    object->setPos(300,200);
    ui->statusbar->showMessage("You chose an ellipse");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->change_figure->setEnabled(true);
}

void MainWindow::on_button_add_canva_clicked()
{
    clear();
    paint = new Canva();
    paint->setSceneRect(0,0,600,400);
    ui->text_1->setText("");
    ui->text_2->setText("");
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->graphicsView->setScene(paint);
    enabled_false();
    ui->button_add_Triangle->setEnabled(false);
    ui->button_add_Square->setEnabled(false);
    ui->button_add_Hexagon->setEnabled(false);
    ui->button_add_5pointstar->setEnabled(false);
    ui->button_add_6pointstar->setEnabled(false);
    ui->button_add_8pointstar->setEnabled(false);
    ui->button_add_Circle->setEnabled(false);
    ui->button_add_Rectangle->setEnabled(false);
    ui->button_add_Rhombus->setEnabled(false);
    ui->button_add_Ellipse->setEnabled(false);
    ui->button_add_canva->setEnabled(false);
    ui->button_delete_canva->setEnabled(true);
    ui->statusbar->showMessage("You chose a canva");
}

void MainWindow::on_button_delete_canva_clicked()
{
    delete paint;
    ui->graphicsView->setScene(scene);
    ui->button_add_Triangle->setEnabled(true);
    ui->button_add_Square->setEnabled(true);
    ui->button_add_Hexagon->setEnabled(true);
    ui->button_add_5pointstar->setEnabled(true);
    ui->button_add_6pointstar->setEnabled(true);
    ui->button_add_8pointstar->setEnabled(true);
    ui->button_add_Circle->setEnabled(true);
    ui->button_add_Rectangle->setEnabled(true);
    ui->button_add_Rhombus->setEnabled(true);
    ui->button_add_Ellipse->setEnabled(true);
    ui->button_delete_canva->setEnabled(false);
    ui->button_add_canva->setEnabled(true);
    ui->statusbar->showMessage("  ");
}

void MainWindow::on_button_area_clicked()
{
    double S = object->Area();
    ui->area->setText(QString::number(S));
}

void MainWindow::on_button_perimeter_clicked()
{
    double P = object->Perimeter();
    ui->perimeter->setText(QString::number(P));
}

void MainWindow::on_button_coordinates_clicked()
{
    ui->label_x->setText("x = ");
    ui->text_3->setText(QString::number(object->x1));
    ui->label_y->setText("y = ");
    ui->text_4->setText(QString::number(object->y1));
}

void MainWindow::on_change_figure_clicked()
{
    scene->clear();
    ui->button_add_Triangle->setEnabled(true);
    ui->button_add_Square->setEnabled(true);
    ui->button_add_Hexagon->setEnabled(true);
    ui->button_add_5pointstar->setEnabled(true);
    ui->button_add_6pointstar->setEnabled(true);
    ui->button_add_8pointstar->setEnabled(true);
    ui->button_add_Circle->setEnabled(true);
    ui->button_add_Rectangle->setEnabled(true);
    ui->button_add_Rhombus->setEnabled(true);
    ui->button_add_Ellipse->setEnabled(true);
    ui->button_add_canva->setEnabled(true);
    ui->change_figure->setEnabled(false);
    ui->text_1->setText("");
    ui->lineEdit->hide();
    ui->text_2->setText("");
    ui->lineEdit_2->hide();
    enabled_false();
    clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->statusbar->showMessage("  ");
}

