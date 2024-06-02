//
// Created by aleks on 31.05.2024.
//

#include "Zadanie.h"

Zadanie::Zadanie(int Nr, vector<Operacja> Operacje) {
    nr=Nr;
    operacje=Operacje;
}

int Zadanie::sumOperacji()const {
    int sum=0;
    for(Operacja op: this->operacje){
        sum+=op.pj;
    }
    return sum;
}

