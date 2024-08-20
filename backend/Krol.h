//
// Created by Bruker on 04.03.2024.
//

#ifndef SZACH_KROL_H
#define SZACH_KROL_H
#include "Figura.h"

class Krol : public Figura{
public:
    bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY,Figura* mapa[][8]);// override;
    Krol(Kolor kolor): Figura(kolor){}

};


#endif //SZACH_KROL_H
