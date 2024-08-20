#ifndef SZACH_FIGURA_H
#define SZACH_FIGURA_H
#include "Kolor.h"

class Figura {
public:
    //bedzie nadpisana w kazdej figurze
    virtual bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8])=0;
    // bicie pionka
    virtual bool sprawdzBicie(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]);
    //ruch hetmana
    static bool sprawdzRuchPionowy(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]);
    //ruch gonca
    static bool sprawdzRuchUkosny(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]);
    bool wykonajRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]); // sprawdzRuch(), sprawdzBicie()
    Figura(Kolor kolor) : kolor(kolor){}
    virtual ~Figura() = default;
   // ~Figura();
    Kolor kolor;
};

#endif //SZACH_FIGURA_H