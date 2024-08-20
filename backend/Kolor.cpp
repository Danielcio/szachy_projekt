#include "Kolor.h"

Kolor przeciwnyKolor(Kolor kolor) {
    if(kolor == Bialy)
        return Czarny;

    return Bialy;
}
