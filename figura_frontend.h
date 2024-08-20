#ifndef FIGURA_FRONTEND_H
#define FIGURA_FRONTEND_H
#include <QPainter>
#include <QWidget>
#include<QString>
class FiguraFrontend
{
public:
    FiguraFrontend(QString ikona);
    void paintEvent(QPainter * painter, int x, int y);

private:
    QString ikona;

};

#endif // FIGURA_FRONTEND_H
