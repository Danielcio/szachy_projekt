#include "mainwindow.h"
#include <QtGui>
#include "customwidget.h"
#include <QApplication>
#include "plansza_frontend.h"

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);
    QScopedPointer<QWidget> widget(new CustomWidget());
    //QScopedPointer<QWidget> plansza(new Plansza());

    widget->resize(800, 500);
    widget->show();
    //plansza->show();
   return app.exec();
  //   QApplication a(argc, argv);
  //    MainWindow w;
  //  QScopedPointer<QWidget> widget(new CustomWidget());
  // widget->resize(800, 500);
  //  //widget->show();
  //  w.show();
  //   return a.exec();
}
