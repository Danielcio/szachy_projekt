#include <iostream>
#include "Wieza.h"

//bool Wieza::czyRuchDozwolony(int staryX, int staryY, int nowyX, int nowyY) {
// std::cout << "Wieza" << std::endl;
//  return true;
//}

bool Wieza::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura *mapa[][8]) {

    return sprawdzRuchPionowy(staryX, staryY, nowyX, nowyY, mapa);
}
