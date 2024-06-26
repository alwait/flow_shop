#include <iostream>
#include "Zadanie.h"
#include "Flowshop.h"

int main() {
    //Flowshop tasma = Flowshop(true);
    Flowshop tasma = Flowshop(7,2,1,20,2);
    string nazwaPliku="instancja.txt";
    //Flowshop tasma = Flowshop(nazwaPliku);

    cout << tasma.toString() << endl;

    Rozwiazanie rozwiazaniePZ = tasma.przegladZupelny();
    cout << "Przeglad zupelny: " << rozwiazaniePZ.toString() << endl;

    Rozwiazanie rozwiazanieNEH = tasma.NEH();
    cout << "NEH: " << rozwiazanieNEH.toString() << endl;

    if(tasma.liczbaProcesorow==2) {
        Rozwiazanie rozwiazanieJ = tasma.Johnson();
        cout << "Johnson: " << rozwiazanieJ.toString() << endl;
    }

    return 0;
}
