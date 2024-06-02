#ifndef TASMA_ZADANIE_H
#define TASMA_ZADANIE_H


#include "Operacja.h"
#include <vector>
using namespace std;

class Zadanie {
public:
    int nr;
    vector<Operacja> operacje;

    Zadanie(int, vector<Operacja>);
    int sumOperacji() const;
};


#endif //TASMA_ZADANIE_H
