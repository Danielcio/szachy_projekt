#include "Goniec.h"
#include <iostream>
//Goniec porusza się wyłącznie po przekątnych pól, w dowolnym kierunku, o dowolną liczbę niezajętych pól

bool Goniec::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) {
    return sprawdzRuchUkosny(staryX,staryY,nowyX,nowyY,mapa);
}