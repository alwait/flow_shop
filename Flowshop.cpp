#include "Flowshop.h"
#include "Rozwiazanie.h"
#include <algorithm>
#include <iostream>
#include <random>


Flowshop::Flowshop(vector<Zadanie> Zadania) {
    zadania = Zadania;
    liczbaProcesorow = Zadania.begin()->operacje.size();
}

Flowshop::Flowshop(int iloscZadan, int iloscOperacji, int zakresDolPj, int zakresGoraPj, int ziarno) {
    vector<Operacja> operacje;
    mt19937 gen(ziarno);
    uniform_int_distribution<> distrib(zakresDolPj, zakresGoraPj);

    for(int j=1; j<=iloscZadan; ++j) {
        for (int i = 1; i <= iloscOperacji; ++i) {
            operacje.push_back(Operacja(i, distrib(gen)));
        }
        zadania.push_back(Zadanie(j,operacje));
        operacje.clear();
    }
    liczbaProcesorow=zadania.begin()->operacje.size();

}

Flowshop::Flowshop(bool generujInstancje) {
    zadania = {
            Zadanie(1, {{1, 2},
                        {2, 1},
                        {3, 3}}),
            Zadanie(2, {{1, 4},
                        {2, 2},
                        {3, 1}}),
            Zadanie(3, {{1, 1},
                        {2, 5},
                        {3, 2}}),
            Zadanie(4, {{1, 4},
                        {2, 8},
                        {3, 2}})
    };
    liczbaProcesorow = 3;

}

vector<Zadanie> Flowshop::przyporzadkujNumery(vector<Zadanie> zadania, vector<int> kolejnosc) {
    vector<Zadanie> zadaniaKolejnosc;
    std::sort(zadania.begin(), zadania.end(), [](const Zadanie &a, const Zadanie &b) {
        return a.nr < b.nr;
    });
    for (int i = 0; i < kolejnosc.size(); ++i) {
        zadaniaKolejnosc.push_back(zadania[kolejnosc[i] - 1]);
    }
    return zadaniaKolejnosc;
}

vector<int> ZadanieToKolejnosc(vector<Zadanie> zadania) {
    vector<int> kolejnosc;
    for (Zadanie zad: zadania) {
        kolejnosc.push_back(zad.nr);
    }
    return kolejnosc;
}

string Flowshop::toString() {
    string rozwiazanie = "zadanie: {operacje} \n";
    for(Zadanie zad: this->zadania){
        rozwiazanie = rozwiazanie + to_string(zad.nr) + ": {";
        for(int i=0; i<zad.operacje.size(); ++i){
            rozwiazanie = rozwiazanie + to_string(zad.operacje[i].pj);
            if(i<zad.operacje.size()-1) rozwiazanie = rozwiazanie +  + ",";
            else rozwiazanie = rozwiazanie +  + "}";
        }
        rozwiazanie = rozwiazanie + "\n";
    }
    return rozwiazanie;
}

Rozwiazanie Flowshop::przegladZupelny() {
    vector<Zadanie> zadaniaOpt, ZaadaniaTemp;
    vector<int> kolejnosc;
    int cmax = INT_MAX, cmaxTemp;
    for (Zadanie zad: zadania) {
        kolejnosc.push_back(zad.nr);
    }
    std::sort(kolejnosc.begin(), kolejnosc.end());
    do {
        ZaadaniaTemp = przyporzadkujNumery(zadania, kolejnosc);
        cmaxTemp = Rozwiazanie(Flowshop(ZaadaniaTemp)).cmax;
        if (cmaxTemp < cmax) {
            cmax = cmaxTemp;
            zadaniaOpt = ZaadaniaTemp;
        }
    } while (std::next_permutation(kolejnosc.begin(), kolejnosc.end()));
    return Rozwiazanie(Flowshop(zadaniaOpt));
}

Rozwiazanie Flowshop::NEH() {
    vector<Zadanie> zadaniaLocal;
    vector<int> kolejnosc, kolejnoscOpt;
    int zadanie = 1, index = 0, cmax = INT_MAX, cmaxTemp;
    for (int j = 0; j < zadania.size(); j++) {
        zadanie=j+1;
        index = 0;
        cmax = INT_MAX;
        for (int i = 0; i < zadanie; ++i) {
            kolejnosc.insert(kolejnosc.begin() + index, zadanie);
            zadaniaLocal = przyporzadkujNumery(zadania, kolejnosc);
            cmaxTemp = Rozwiazanie(Flowshop(zadaniaLocal)).cmax;
            if (cmaxTemp < cmax) {
                cmax = cmaxTemp;
                kolejnoscOpt = ZadanieToKolejnosc(zadaniaLocal);
            }
            kolejnosc.erase(kolejnosc.begin() + index);
            index++;
        }
        kolejnosc = kolejnoscOpt;
    }

    return Rozwiazanie(Flowshop(przyporzadkujNumery(zadania, kolejnoscOpt)));
}

Rozwiazanie Flowshop::Johnson() {
    vector<Zadanie> L, R;
    int operacjaL=0, operacjaR=1;
    for(Zadanie zad: this->zadania){
        if(zad.operacje[operacjaL].pj < zad.operacje[operacjaR].pj)
            L.push_back(zad);
        else
            R.push_back(zad);
    }
    ranges::sort(L, [&operacjaL](const Zadanie &a, const Zadanie &b)
    {
        return a.operacje[operacjaL].pj <= b.operacje[operacjaL].pj;
    });
    ranges::sort(R, [&operacjaR](const Zadanie &a, const Zadanie &b)
    {
        return a.operacje[operacjaR].pj >= b.operacje[operacjaR].pj;
    });
    L.insert( L.end(), R.begin(), R.end());
    return Rozwiazanie(L);
}








