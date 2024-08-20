//
// Created by Bruker on 04.03.2024.
//

#ifndef SZACH_SKOCZEK_H
#define SZACH_SKOCZEK_H
#include "Figura.h"

class Skoczek : public Figura {

public:
    bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY,Figura* mapa[][8]) override;
    Skoczek(Kolor kolor) : Figura(kolor){}


};


#endif //SZACH_SKOCZEK_H
