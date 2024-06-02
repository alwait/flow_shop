#include "Procesor.h"

Procesor::Procesor(int Nr, int czasStart){
    nr=Nr;
    czasDzialania=czasStart;
}

void Procesor::dodajZadanie(Zadanie zadanie, int offset) {
    this->zadania.push_back(zadanie);
    czasDzialania+=zadanie.operacje[nr-1].pj+offset;
}

int dodajOffset(int m1koniec, int m2start) {
    if(m1koniec <= m2start) return 0;
    else return m1koniec-m2start;
}
