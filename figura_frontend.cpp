#include "figura_frontend.h"

FiguraFrontend::FiguraFrontend(QString ikona) {
    this->ikona=ikona;



}
void FiguraFrontend::paintEvent(QPainter * painter,int x,int y){
    QFont font("Arial", 30);
    painter->setFont(font);
    painter->drawText(x, y, this->ikona);
}
