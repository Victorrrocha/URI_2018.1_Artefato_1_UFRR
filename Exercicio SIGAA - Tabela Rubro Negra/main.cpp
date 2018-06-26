#include <iostream>
#include "arvRB.h"
#include <stdio.h>
#include <stdlib.h>

/// trabalho contribuição Ewelly, Francisco, Pedro, Victor ///
using namespace std;

int main()
{
    Arv* tab_hash[15];
    int i;
    for (i = 0; i<15; i++){
        tab_hash[i] = ARB_cria();
    }

    int n1 = 10, m = 13;
    int n2 = 9;
    int mod = n1%m;
    int mod2 = n2%m;

    inserir_hash(tab_hash[mod], n1);
    inserir_hash(tab_hash[mod2], n2);

    for(i = 0; i < 15; i++)
    {
        if(tab_hash[i] != NULL)
            imprime(tab_hash[i], 2);
    }


    return 0;
}
