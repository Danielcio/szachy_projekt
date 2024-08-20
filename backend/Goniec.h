#ifndef SZACH_GONIEC_H
#define SZACH_GONIEC_H
#include "Figura.h"

//bool sprawdzRuchGonca(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]);
//dziedziczy po klasie figura
class Goniec : public Figura {
public:
    //nadpisana metoda z figura
    bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) override;
    Goniec(Kolor kolor) : Figura(kolor){}


};


#endif //SZACH_GONIEC_H
