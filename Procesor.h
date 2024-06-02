#ifndef TASMA_PROCESOR_H
#define TASMA_PROCESOR_H


#include "Zadanie.h"
#include <vector>
using namespace std;

class Procesor {
public:
    vector<Zadanie> zadania;
    int czasDzialania;
    int nr;

    Procesor(int, int);
    void dodajZadanie(Zadanie,int);

};

int dodajOffset(int, int);

#endif //TASMA_PROCESOR_H
