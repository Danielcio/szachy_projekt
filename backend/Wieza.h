#ifndef SZACH_WIEZA_H
#define SZACH_WIEZA_H
#include "Figura.h"

class Wieza : public Figura{
public:
    bool sprawdzRuch(int staryX, int staryY, int nowyX,int nowyY,Figura* mapa[][8])override;
    Wieza(Kolor kolor): Figura(kolor){}
};


#endif //SZACH_WIEZA_H
