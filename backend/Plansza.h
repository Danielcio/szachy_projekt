#include "Figura.h"
#include <vector>
#include <utility>
#include "WynikRuchu.h"

#ifndef SZACH_PLANSZA_H
#define SZACH_PLANSZA_H

class Plansza {
private:
    void zaktualizujKrola(Kolor kolor, int x, int y);
    WynikRuchu zmienPozycje(int staryX, int staryY, int nowyX, int nowyY);
    Figura* mapa[8][8]{};
    Kolor poprzednikolor=Czarny;
public:
    std::vector<Figura*> zbiteBialeFigury;
    std::vector<Figura*> zbiteCzarneFigury;
    std::pair<int, int> bialyKrol;
    std::pair<int, int> czarnyKrol;
    Plansza();
    //na potrzeby teststów jednostkowych
    Plansza(Figura* mapa[8][8]);
    void wygenerujMape();
    WynikRuchu przesunFigure(int staryX, int staryY, int nowyX, int nowyY);
    bool czyMomentZamiany(int x, int y);
    bool czySzach(Kolor kolorKrola);
    Kolor czyjaTura();
    bool zamienFigure(int x, int y, Kolor kolor, int nrFigury,int xx);

};

#endif //SZACH_PLANSZA_H

// zbicie -> push_back
// wziecie figury -> [3,4,nullptr,2, 1]
// vec.erase(<startowy nr indeksu>, <ilosc elementow do usuniecia>)
// vec.erase(1,1) // usuwamy drugi element
