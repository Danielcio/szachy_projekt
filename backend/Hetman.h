#ifndef SZACH_HETMAN_H
#define SZACH_HETMAN_H
#include "Figura.h"

class Hetman : public Figura{
public:
   bool sprawdzRuch(int staryX,int staryY,int nowyX,int nowyY,Figura* mapa[][8]) override;
    Hetman(Kolor kolor): Figura(kolor){}

};


#endif //SZACH_HETMAN_H
