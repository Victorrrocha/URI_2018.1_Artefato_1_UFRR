#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<bits/stdc++.h>
#include "hash_duplo.h"

using namespace std;

int main()
{
    string tabela[TAM];
    inicializa(tabela);

    inserir(tabela, "david");
    inserir(tabela, "adao");
    inserir(tabela, "cesar");
    inserir(tabela, "amelia");
    inserir(tabela, "arnaldo");

    imprimir(tabela);

    remover(tabela, "adao");

    imprimir(tabela);

    inserir(tabela, "adao");

    imprimir(tabela);

    return 0;
}
