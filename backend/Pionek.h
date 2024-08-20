#ifndef SZACH_PIONEK_H
#define SZACH_PIONEK_H
#include "Figura.h"

class Pionek : public Figura {

public:
    bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) override;
    bool sprawdzBicie(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) override;
    Pionek(Kolor kolor) : Figura(kolor) {}
   // ~Pionek();
  // void Ruch();
};
//
// Plansza
// figury Figura[]; //[Pionek, Kon, Wieza, Pionek, Pionek]
// mapa Figura*[][] // [&Pionek, &Kon, NULL, NULL, NULL]

// obsluzRuch()
// if( figury[0].czyRuchDozwolony(2,2) ) {
        //przesun(figura[0], 2, 2)
//}

// przesun () {
// jezeli kolizja
// delete Figura
// umiesc Figura1 w tym miejscu
// w starym miejscu umiesc NULL
// }
#endif //SZACH_PIONEK_H
