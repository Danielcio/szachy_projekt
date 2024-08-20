//
// Created by Bruker on 04.03.2024.
//

#include "Skoczek.h"
//bool Skoczek::czyRuchDozwolony(int staryX, int staryY, int nowyX, int nowyY) {
   // return true;
//}

//ruch skoczka skoczek  może przeskakiwać inne bierki, ruchy skoczka przypominają kształt litery “L”,
// skoczek porusza się idąc dwa pola w dowolnym kierunku (góra, dół, lewo, prawo), a później o jedno w lewo bądź prawo
bool Skoczek::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]){
    int deltaX=nowyX-staryX;
    int deltaY=nowyY-staryY;
    if((deltaX==1||deltaX == -1)&& (deltaY==2||deltaY==-2)){
        return true;
    }
    else if((deltaY==1||deltaY == -1)&& (deltaX==2||deltaX==-2)){
        return true;
    }
    else{
        return false;
    }

}
