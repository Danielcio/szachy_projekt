#ifndef PLANSZA_FRONTEND_H
#define PLANSZA_FRONTEND_H
#include <QPainter>
#include <QWidget>
#include "figura_frontend.h"
#include "backend/Plansza.h"

class PlanszaFrontend : public QWidget
{Q_OBJECT
private:

    void narysujPole(int x ,int y, const QString kolor,QPainter *painter);
    FiguraFrontend *figury [8][8];
     QPoint m_lastPos;
    int staryX=-1;
     int staryY=-1;
    Plansza plansza;
     bool czyRuchNieudany=false;

public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    explicit PlanszaFrontend(QWidget *parent = 0);
    // PlanszaFrontend(QWidget *parent);
    void paintEvent(QPainter * painter);
    void wygenerujPlansze();
    std::vector<FiguraFrontend*> zbiteBiale;
     std::vector<FiguraFrontend*> zbiteCzarne;

};

#endif // PLANSZA_FRONTEND_H
