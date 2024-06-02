#ifndef TASMA_ROZWIAZANIE_H
#define TASMA_ROZWIAZANIE_H

#include <vector>
#include <string>

using namespace std;

class Flowshop;

class Rozwiazanie {
public:
    int cmax;
    vector<int> pi;

    Rozwiazanie();
    Rozwiazanie(Flowshop);
    string toString();
};


#endif //TASMA_ROZWIAZANIE_H
