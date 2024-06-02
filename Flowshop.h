#ifndef TASMA_FLOWSHOP_H
#define TASMA_FLOWSHOP_H

#include <iostream>
#include "Zadanie.h"
#include "Rozwiazanie.h"
using namespace std;

class Flowshop {
public:
    vector<Zadanie> zadania;
    int liczbaProcesorow;

    Flowshop(vector<Zadanie>);
    Flowshop(bool);
    Flowshop(string);
    Flowshop(int, int, int, int, int);
    vector<Zadanie> przyporzadkujNumery(vector<Zadanie>,vector<int>);
    Rozwiazanie przegladZupelny();
    Rozwiazanie NEH();
    Rozwiazanie Johnson();
    string toString();

};
vector<int> ZadanieToKolejnosc(vector<Zadanie> zadania);


#endif //TASMA_FLOWSHOP_H
