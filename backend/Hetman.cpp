#include "Hetman.h"
#include "Figura.h"

//Hetman może poruszać się w dowolnym kierunku (poziomo, pionowo oraz na ukos) o dowolną liczbę wolnych pól
bool Hetman::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) {
     if(sprawdzRuchPionowy(staryX,staryY,nowyX,nowyY,mapa) || sprawdzRuchUkosny(staryX,staryY,nowyX,nowyY,mapa)) {
        return true;
    }

     return false;
}
