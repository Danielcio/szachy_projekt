#include "plansza_frontend.h"
#include <QPainter>
#include "figura_frontend.h"
#include <iostream>
#include <QMouseEvent>
#include<qpushbutton.h>
#include "backend/WynikRuchu.h"
PlanszaFrontend::PlanszaFrontend(QWidget *parent):
QWidget(parent)
{
    wygenerujPlansze();

}
void PlanszaFrontend::wygenerujPlansze()
{
    //odpalenie backendu plansz poniewqaz backend porusza sie razem z fronendem
    plansza.wygenerujMape();

    for (int x=0;x<8;x++)
        for(int y=0;y<8;y++){
            delete figury[x][y];
            figury[x][y]=nullptr;}

    for(int x = 0; x < 8; x++) {
        figury[x][1] = new FiguraFrontend("♙");
        figury[x][6] = new FiguraFrontend("♟");
    }

    figury [0][0] =  new FiguraFrontend("♖");
    figury [1][0] = new FiguraFrontend ("♘");
    figury [2][0] = new FiguraFrontend ("♗");
    figury [3][0] = new FiguraFrontend ("♕");
    figury [4][0] = new FiguraFrontend ("♔");
    figury [5][0] = new FiguraFrontend ("♗");
    figury [6][0] = new FiguraFrontend ("♘");
    figury [7][0] = new FiguraFrontend ("♖");
    // druga strona planszy
    figury[0][7] =  new FiguraFrontend("♜");
    figury [1][7] = new FiguraFrontend ("♞");
    figury [2][7] = new FiguraFrontend ("♝");
    figury [3][7] = new FiguraFrontend ("♛");
    figury [4][7] = new FiguraFrontend ("♚");
    figury [5][7] = new FiguraFrontend ("♝");
    figury [6][7] = new FiguraFrontend ("♞");
    figury [7][7] = new FiguraFrontend ("♜");
        //figury[3][3]=new r2;
    //Figura[3][3]->moveCenter(m_lastPos);
    // figury[1][0]=new Figura ("♕");
    //  figury[2][0]=new Figura ("♕");
    //zbiteBiale[x][y] = nullptr;
    for(int x=0;x<zbiteBiale.size();x++){
        delete zbiteBiale[x];

    }

    for(int x=0;x<zbiteCzarne.size();x++){
        delete zbiteCzarne[x];

    }
    zbiteBiale.clear();
    zbiteCzarne.clear();
    czyRuchNieudany=false;
};
const int ROZMIAR = 50;
const int PRZES_X=170;
const int PRZES_Y=50;
void PlanszaFrontend::paintEvent(QPainter *painter)
{
    int zbiteX= PRZES_X+450;
    int zbiteY= PRZES_Y+20;
    qInfo()<<zbiteBiale.size();
    qInfo()<<zbiteCzarne.size();
    // if(zbiteBiale.size()>0){
    //    zbiteBiale[0]->paintEvent(painter,zbiteX,zbiteY);
    // }
    for(int x=0;x<zbiteBiale.size();x++){

        zbiteBiale[x]->paintEvent(painter,zbiteX,zbiteY);
        zbiteY+=40;

    }
    zbiteX+=100;
    zbiteY =PRZES_Y +20;
    for(int x=0;x<zbiteCzarne.size();x++){
        zbiteCzarne[x]->paintEvent(painter,zbiteX,zbiteY);
        zbiteY+=40;

    }
   //QPainter painter(this);
    QString kolor="#FFFFCC";
   for(int x=0; x<8; x++){
        if(kolor=="#FFFFCC")
            kolor="#996600";
        else {
            kolor="#FFFFCC";
        }
        for (int y = 0; y <8; y++) {
            //std::cout<<"test pola";
             narysujPole(x,y, kolor,painter);
            if(kolor=="#FFFFCC")
                 kolor="#996600";
            else {
                kolor="#FFFFCC";
            }}
        }
  // QRect r2(QPoint(60,30),QSize(20,20));

        //painter->fillRect(r2, QColor("#111211"));
     //  r2.moveCenter(m_lastPos);
        QString tekst = "RUCH ";
        Kolor czyjRuch= plansza.czyjaTura();
        if(czyjRuch==Bialy){
            tekst+="BIALYCH";
        }
        else tekst+="CZARNYCH";
        QFont font("Arial", 15);
        painter->setFont(font);
        painter->drawText(85, 40, tekst);
        if(plansza.czySzach(czyjRuch)){
           // QFont font("Arial", 15);
            painter->setPen(QColor("#d72b06"));

            painter->drawText(300, 40, "SZACH !!!");
        }
        if(czyRuchNieudany){
            // QFont font("Arial", 15);
            painter->setPen(QColor("#d72b06"));

            painter->drawText(400, 40, "Niemozesz wykonac ruchu !!!");
        }
        //QPushButton button;
        //button.setText("Klik");
        //button.show();

}


void PlanszaFrontend::narysujPole(int x ,int y, const QString  kolor,QPainter *painter)
{
    int posX = PRZES_X + x * ROZMIAR;
    int posY = PRZES_Y + y * ROZMIAR;
    QRect pole(QPoint(posX,posY),QSize(ROZMIAR,ROZMIAR));
    painter->fillRect(pole, QColor(kolor));
    if(figury[x][y] != nullptr) {
        figury[x][y] -> paintEvent(painter,posX+ROZMIAR/8,posY+(ROZMIAR*2/3)+5);
    }
   // Figura figura("♔");
    //figura.paintEvent(painter,x+ROZMIAR/8,y+(ROZMIAR*2/3)+5);

}
//Figura[1][0]("♙").moveCenter(m_lastPos);
void PlanszaFrontend::mousePressEvent(QMouseEvent *event){

    int x = (event->pos().x()- PRZES_X) / ROZMIAR;
    int y = (event->pos().y()- PRZES_Y) / ROZMIAR;
    m_lastPos = event->pos();
    //std::cout<<event->pos().x();
    qInfo()<<"to jest wartosc x"<<x<<" "<<"to jest wartosc y"<<y;
    if(x<0||x>7||y<0||y>7)
        return;
    if(staryX==-1){
        if(figury[x][y]==nullptr){
            return;
        }
        staryX=x;
        staryY=y;
        return;
    }
    if(x==staryX && y==staryY){
        staryX=-1;
        return;
    }
    qInfo()<<"TO JEST X "<<staryX<<" "<<staryY<<" "<<x<<" "<<y;
    //
    WynikRuchu wynik =plansza.przesunFigure(staryX,staryY,x,y);
    if(wynik==Bicie){

        if(plansza.czyjaTura()==Bialy)
        {
            qInfo()<<"to jest proba zbicia bialy";
            zbiteBiale.push_back(figury[x][y]);
        }
        else {
            qInfo()<<"to jest proba zbicia czarny";
            zbiteCzarne.push_back(figury[x][y]);
        }
    }
    if(wynik != Porazka && wynik != Szach) {
        czyRuchNieudany=false;
    figury[x][y]=figury[staryX][staryY];
    figury[staryX][staryY]=nullptr;
    }
    else
    {  czyRuchNieudany=true;

    }
    staryX=-1;
}

void PlanszaFrontend::mouseMoveEvent(QMouseEvent *event)
{qInfo()<<"to jest test";
    m_lastPos = event->pos();
    update();
      //nowy_punkt= event->pos();
     //update();
}
