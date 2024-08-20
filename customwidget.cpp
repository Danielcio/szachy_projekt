#include "customwidget.h"
#include "backend/Plansza.h"

#include <QPainter>
#include <QMouseEvent>
//#include "prostokat.h"
#include  "plansza_frontend.h"
#include "figura_frontend.h"
#include <iostream>
#include<QDebug>
    CustomWidget::CustomWidget(QWidget *parent) :
    QWidget(parent)
{
}

void CustomWidget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
    QRect r1 = rect().adjusted(10,10,-10,-10);
    painter.setPen(QColor("#c7cc37"));
    painter.drawRect(r1);
    plansza.paintEvent(&painter);
    //int ROZMIAR = 50;
    //Figura figura("♔");

    //if(m_lastPos.isNull()) {
         // figura("♔").position(());
         //   } else {
         //        figura.moveCenter(m_lastPos);
         //    }
  //  figura.paintEvent(&painter,200,200);
   // QRect r2(QPoint(10,30),QSize(40,40));
    //Figura figura("♔");
    //figura.paintEvent(&painter,10,30);
    //if(m_lastPos.isNull()) {
      // r2.moveCenter(r1.center());
    //} else {
      //  r2.moveCenter(m_lastPos);
     //}
     //painter.fillRect(r2, QColor("#111211"));
    //  QRect r3(QPoint(0,0),QSize(20,20));
    //   if(m_lastPos.isNull()) {
    //      r3.moveCenter(r1.center());
    //   } else {
    //       r3.moveCenter(m_lastPos);
    //   }
    //   painter.fillRect(r3, QColor("#CD5C5C"));
    //prostokat pr1;
    QFont font = painter.font();
        font.setPointSize(10);
    painter.setFont(font);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect buttonRect(20, 150, 100, 30);
    painter.fillRect(buttonRect, czyWcisniety ? Qt::darkGreen : Qt::green);
    painter.setPen(Qt::black);
    painter.drawRect(buttonRect);
    painter.drawText(buttonRect, Qt::AlignCenter, "Rozpocznij gre!");
 }
 void CustomWidget::mousePressEvent(QMouseEvent *event)
 {//std::cout<<"a";
    plansza.mousePressEvent(event);
     int x=event->pos().x();
    int y=event->pos().y();
     if(event->button() == Qt::LeftButton && x>=20 && x<=120 && y>=150 && y<=180 )
    {
        czyWcisniety=true;
         plansza.wygenerujPlansze();
         update();
         //qInfo()

         }
   // event->ignore();
//    // m_lastPos = event->pos();
 update();
//   //  nowy_punkt = event->pos();
//   //  update();
}

 void CustomWidget::mouseMoveEvent(QMouseEvent *event)
 {
//    // m_lastPos = event->pos();
//     //update();
//   //  nowy_punkt= event->pos();
//    // update();
}

// // void CustomWidget::mouseMoveEvent(QMouseEvent *event)
// // {
// //     nowy_punkt = event->pos();
// //     update();
// // }
// // void CustomWidget::mousePressEvent(QMouseEvent *event)
// // {
// //     nowy_punkt = event->pos();
// //     update();
// // }
void CustomWidget::mouseReleaseEvent(QMouseEvent *event){
    czyWcisniety=false;
    update();
    qInfo()<<"puszczono przycisk" ;
}
