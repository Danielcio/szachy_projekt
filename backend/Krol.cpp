#include "Krol.h"
//bool Krol::czyRuchDozwolony(int staryX, int staryY, int nowyX, int nowyY){
  //  return true;
  //  //}

//krol porusza sie w kazdym kierunku po jednym polu
bool Krol::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) {
    int deltaX=nowyX-staryX;
    int deltaY=nowyY-staryY;
    if((deltaX==1||deltaX==0||deltaX==-1)&&(deltaY==1||deltaY==0||deltaY==-1)) {
        return true;
    }

    return false;
}
