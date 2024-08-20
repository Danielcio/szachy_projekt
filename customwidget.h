#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H
#include "plansza_frontend.h"
#include <QWidget>
#pragma once

//include <QtWidgets>

    class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    PlanszaFrontend plansza;
    QPoint m_lastPos;
    bool czyWcisniety=false;
//QPoint nowy_punkt;
};

#endif // CUSTOMWIDGET_H
