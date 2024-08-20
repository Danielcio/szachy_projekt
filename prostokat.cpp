#include "prostokat.h"
#include <QPainter>
#include <QMouseEvent>
//prostokat::prostokat(QWidget *parent) :
  // QWidget(parent)
//{
//}
void prostokat::paintEvent(QPaintEvent *)
{
    QPainter rysowac(this);
//prostokat::prostokat() {
    QRect r3(QPoint(0,0),QSize(20,20));
        // if(nowy_punkt.isNull()) {
        //     r3.moveCenter(r1.center());
        //   } else {
    //r3.moveTopLeft(nowy_punkt);
    //   }
    rysowac.fillRect(r3, QColor("#c7cc37"));
}

void prostokat::mousePressEvent(QMouseEvent *event)
{

    nowy_punkt = event->pos();
    update();
}

void prostokat::mouseMoveEvent(QMouseEvent *event)
{

    nowy_punkt= event->pos();
    update();
}
