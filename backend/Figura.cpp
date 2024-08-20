#include "Figura.h"
#include <iostream>
//bool Figura::czyBicieDozwolone(int staryX, int staryY, int nowyX, int nowyY) {
  //  return true;
//}

// Tylko pionek ma inne dozwolone ruchy w przypadku bicia
//
bool Figura::sprawdzBicie(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) {
    return sprawdzRuch(staryX, staryY, nowyX, nowyY, mapa);
}

bool Figura::sprawdzRuchUkosny(int staryX,int staryY,int nowyX,int nowyY,Figura* mapa[][8]){
    int deltaX = nowyX - staryX;
    int deltaY = nowyY - staryY;
//sprawdzanie delty czy delty sa takie samy
    if(deltaX != deltaY && deltaX != -deltaY)
        return false;

    int xx = 1, yy = 1;

    if(deltaX < 0) {
        xx = -1;
        deltaX = deltaX * (-1);
    }

    if(deltaY < 0) {
        yy = -1;
    }

    int x = staryX;
    int y = staryY;
    int iloscIteracji = 0;

    while(iloscIteracji < deltaX - 1) {
        x = x + xx;
        y = y + yy;
        iloscIteracji++;

        if(mapa[x][y] != nullptr) {
            std::cout << "Figura na drodze"<< std::endl;
            return false;
        }
    }

    return true;
}

bool Figura::sprawdzRuchPionowy(int staryX, int staryY, int nowyX, int nowyY, Figura *mapa[][8]) {
    //czy ruch jest w lini prostej
    int deltaX = nowyX - staryX;
    int deltaY = nowyY - staryY;

    if (deltaX != 0 && deltaY != 0) {
        return false;
    }

    if (deltaX < 0) {
        for (int x = staryX - 1; x > nowyX; x--) {
            if (mapa[x][nowyY] != nullptr) {
                //std::cout << "przesuniecie pionka po x";
                return false;
            }
        }
    }
    if (deltaX > 0) {
        for (int x = staryX + 1; x < nowyX; x++) {
            if (mapa[x][nowyY] != nullptr) {
                // std::cout << "przesuniecie pionka po x";
                return false;
            }
        }
    }


    if (deltaY < 0) {
        for (int y = staryY - 1; y > nowyY; y--) {
            if (mapa[nowyX][y] != nullptr) {
                // std::cout << "przesuniecie pionka po x";
                return false;
            }
        }
    }
    if (deltaY > 0) {
        for (int y = staryY + 1; y < nowyY; y++) {
            if (mapa[nowyX][y] != nullptr) {
                // std::cout << "przesuniecie pionka po y";
                return false;
            }
        }
    }
    return true;
}