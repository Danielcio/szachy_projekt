#include "Plansza.h"
#include "Figura.h"
#include "Pionek.h"
#include "Goniec.h"
#include "Skoczek.h"
#include "Hetman.h"
#include "Krol.h"
#include "Wieza.h"
#include <iostream>
#include <typeinfo>
#include "WynikRuchu.h"

using namespace std;

void Plansza::wygenerujMape() {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            delete mapa[x][y];
            mapa[x][y] = nullptr;
        }
    }

    for(int x = 0; x < 8; x++) {
        mapa[x][1] = new Pionek(Bialy);
        mapa[x][6] = new Pionek(Czarny);
    }
    mapa [0][0] =  new Wieza(Bialy);
    mapa [1][0] = new Skoczek (Bialy);
    mapa [2][0] = new Goniec (Bialy);
    mapa [3][0] = new Hetman (Bialy);
    mapa [4][0] = new Krol (Bialy);
    bialyKrol = std::make_pair(4, 0);
    mapa [5][0] = new Goniec (Bialy);
    mapa [6][0] = new Skoczek (Bialy);
    mapa [7][0] = new Wieza (Bialy);
    //druga strona szachow czarne figury
    mapa[0][7] =  new Wieza(Czarny);
    mapa [1][7] = new Skoczek (Czarny);
    mapa [2][7] = new Goniec (Czarny);
    mapa [3][7] = new Hetman (Czarny);
    mapa [4][7] = new Krol (Czarny);
    czarnyKrol = std::make_pair(4, 7);
    mapa [5][7] = new Goniec (Czarny);
    mapa [6][7] = new Skoczek (Czarny);
    mapa [7][7] = new Wieza (Czarny);
   for(int x=0;x<zbiteBialeFigury.size();x++){
        delete zbiteBialeFigury[x];

    }
   for(int x=0;x<zbiteCzarneFigury.size();x++){
       delete zbiteCzarneFigury[x];

   }
    zbiteBialeFigury.clear();
    zbiteCzarneFigury.clear();
}

WynikRuchu Plansza::przesunFigure(int staryX, int staryY, int nowyX, int nowyY) {
    // 1. Czy figura znajduje sie na wskazanych wspolrzednych
    // 2. Czy figura moze przesunac sie na nowe wspolrzedne
    // 2.1 jesli bicie ->  imapa[staryY][staryX].czyBicieDozwolone(staryX, staryY, nowyY, nowyX),
    // 2.1 w innym wypadku -> imapa[staryY][staryX].czyRuchDozwolony(staryX, staryY, nowyY, nowyX)
    // 2.2 jezeli figura to nie koń -> sprawdzKolizje(staryX, staryY, nowyX, nowyY)

    //pionek[staryX][nowyX] -> czyRuchDozwolony(...)
    //      <przesun pionek>
    //      return true
    // else
    //      <nie przesuwaj>
    //      return false
//sprawdzenie czy wychodzimy poza mape
    if (staryX > 7 || staryX < 0 || staryY > 7 || staryY < 0 || nowyX > 7 || nowyX < 0 || nowyY > 7 || nowyY < 0) {
        return Porazka;
    }
// czy nie klikamy na puste pole
    if(mapa[staryX][staryY] == nullptr) {
        return Porazka;
    }
    //sparawdzenie kolejnosci ruchu
    if(poprzednikolor==mapa[staryX][staryY]->kolor){
        return Porazka;
    }

    if(mapa[nowyX][nowyY] == nullptr && !mapa[staryX][staryY] -> sprawdzRuch(staryX, staryY, nowyX, nowyY, mapa)) {
        return Porazka;
    }
    else if(mapa[nowyX][nowyY]!= nullptr) {
        if(mapa[staryX][staryY]->kolor == mapa[nowyX][nowyY] -> kolor || !mapa[staryX][staryY] -> sprawdzBicie(staryX, staryY, nowyX, nowyY, mapa))
            return Porazka;
    }

    //poprzednikolor= przeciwnyKolor(poprzednikolor);
    return zmienPozycje(staryX, staryY, nowyX, nowyY);
}

bool Plansza::czyMomentZamiany(int x, int y) {
    // Czy pionek znajduje w ostatnim rzedzie
    if (mapa[x][y]->kolor == Bialy) {
        if (y != 7) {
            return false;
        }
    } else {
        if (y != 0) {
            return false;
        }
    }

    // Czy figura to pionek
    const std::type_info& type = typeid(*mapa[x][y]);
    if (type != typeid(Pionek)) {
        return false;
    }

    return true;
}

WynikRuchu Plansza::zmienPozycje(int staryX, int staryY, int nowyX, int nowyY) {
    Figura* figura = mapa[nowyX][nowyY];
    mapa[nowyX][nowyY] = mapa[staryX][staryY];
    mapa[staryX][staryY] = nullptr;

// Jesli figura jest krolem, to sprawdz jej kolor i zaktualizuj odpowiednia parę współrzędnych

    const std::type_info& type = typeid(*mapa[nowyX][nowyY]);
    if (type == typeid(Krol))
        zaktualizujKrola(mapa[nowyX][nowyY]-> kolor, nowyX, nowyY);

    if(czySzach(mapa[nowyX][nowyY]->kolor)) {
        mapa[staryX][staryY] = mapa[nowyX][nowyY];
        mapa[nowyX][nowyY] = figura;

        if (type == typeid(Krol))
            zaktualizujKrola(mapa[staryX][staryY]-> kolor, staryX, staryY);

        return Szach;
    }
    poprzednikolor= przeciwnyKolor(poprzednikolor);
    if(figura != nullptr) {
        if(figura->kolor == Bialy) {
            zbiteBialeFigury.push_back(figura);
        }
        else {
            zbiteCzarneFigury.push_back(figura);
        }

        return Bicie;
    }


    return BrakBicia;
}

bool Plansza::zamienFigure(int x, int y, Kolor kolor, int nrFigury,int xx) {
    if(!czyMomentZamiany(x, y)) {
        return false;
    }
    if(xx==10 || xx==12)
    {
        nrFigury+=8;
    }

    Figura* bufor = mapa[x][y];
    if (kolor == Bialy) {
        if(nrFigury > zbiteBialeFigury.size() - 1) {
           return false;
        }
       mapa[x][y] = zbiteBialeFigury[nrFigury];
        zbiteBialeFigury[nrFigury] = bufor;
       poprzednikolor= przeciwnyKolor(poprzednikolor);
        return true;
   }

    if(nrFigury > zbiteCzarneFigury.size() - 1) {
        return false;
    }
   mapa[x][y] = zbiteCzarneFigury[nrFigury];
   zbiteCzarneFigury[nrFigury] = bufor;
   poprzednikolor= przeciwnyKolor(poprzednikolor);
    return true;
};

void Plansza::zaktualizujKrola(Kolor kolor, int x, int y) {
    if(kolor == Bialy) {
        bialyKrol = std::make_pair(x, y);
    }
    else {
        czarnyKrol = std::make_pair(x, y);
    }
}


bool Plansza::czySzach(Kolor kolorKrola) {
    std::pair<int, int> wspolrzedne;
    Kolor kolorFigury = przeciwnyKolor(kolorKrola);

    if (kolorKrola == Bialy) {
        wspolrzedne = bialyKrol;
    }
    else {
        wspolrzedne = czarnyKrol;
    }

     //Przejdz po wszystkich polach mapy
     //Jesli kolor jest przeciwny do koloru krola, to sprawdzamy czy figura ma na niego bicie
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if(mapa[x][y] != nullptr && mapa[x][y]->kolor == kolorFigury && mapa[x][y]->sprawdzBicie(x,y,wspolrzedne.first, wspolrzedne.second, mapa)) {
                cout << "Znaleziono szach, figura " <<x << ", " << y << " ma bicie na krola na " << wspolrzedne.first << ", " << wspolrzedne.second<<endl;
               return true;
            }
        }
    }

    return false;
}
Plansza::Plansza() {
    wygenerujMape();
}

Plansza::Plansza(Figura* mapa[8][8]) {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            this->mapa[x][y] = mapa[x][y];
        }
    }
}

Kolor Plansza::czyjaTura() {
    return przeciwnyKolor(poprzednikolor);
}
