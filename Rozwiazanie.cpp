#include "Rozwiazanie.h"
#include "Flowshop.h"
#include "Procesor.h"

Rozwiazanie::Rozwiazanie() {
    cmax=0;
    pi={};
}

Rozwiazanie::Rozwiazanie(Flowshop tasma) {
    vector<Procesor> procesory;
    vector<Zadanie> zadania = tasma.zadania;

    for (int i = 0; i < tasma.liczbaProcesorow; ++i) {
        if (i > 0) procesory.push_back(Procesor(i + 1, procesory[i - 1].czasDzialania));
        else procesory.push_back(Procesor(i + 1, 0));
        procesory[i].dodajZadanie(zadania[0], 0);

    }

    for (int i = 1; i < zadania.size(); ++i) {
        for (int j = 0; j < tasma.liczbaProcesorow; ++j) {
            if (j > 0) procesory[j].dodajZadanie(zadania[i], dodajOffset(procesory[j - 1].czasDzialania,procesory[j].czasDzialania));
            else procesory[j].dodajZadanie(zadania[i], 0);
        }

    }
    cmax = procesory[tasma.liczbaProcesorow-1].czasDzialania;
    for(int i = 0; i< zadania.size(); ++i){
         pi.push_back( procesory[0].zadania[i].nr);
    }
}

string Rozwiazanie::toString() {
    string rozwiazanie = "cmax: " + to_string(this->cmax);
    rozwiazanie = rozwiazanie + ", ";
    for(int i=0; i< this->pi.size(); ++i){
        rozwiazanie = rozwiazanie + to_string(pi[i]) + " ";
    }
    return rozwiazanie;
}

