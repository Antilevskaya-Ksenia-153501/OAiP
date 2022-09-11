#include "star.h"
#include<QPainter>

Star::Star(QObject* parent, int n_temp, int r_temp,int R_temp):
    Figure(parent)
{
    n = n_temp;
    r = r_temp;
    R = R_temp;
}

Star::~Star()
{

}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{    float a=0;
     int* point_x = new int [n*2+1];
     int* point_y = new int [n*2+1];
     for (int i=1;i<n*2+2;i++)
     {
         if (!(i%2))
        {
         point_x[i] =r/2*cos(a*M_PI/180);
         point_y[i]= -r/2*sin(a*M_PI/180);
        }
        else
         {
          point_x[i] = R*cos(a*M_PI/180);
          point_y[i] = -R*sin(a*M_PI/180);
         }
         a=a+180/n;
      }
      point_x[n*2+1] = point_x[1];
      point_y[n*2+1] = point_y[1];

      QPolygon polygon;
      for (int i=1;i<n*2+2;i++)
      {
        polygon << QPoint(point_x[i], point_y[i]);
      }
      painter->setBrush(Qt::yellow);
      painter->drawPolygon(polygon);
      delete[]  point_x;
      delete[]  point_y;
      Q_UNUSED(option);
      Q_UNUSED(widget);
}

double Star::Area()
{
    return (n * R * R * tan(M_PI/n) * cos(2*M_PI/ n));
}

double Star::Perimeter()
{
    return (2 * n * R * tan(M_PI/n));
}



