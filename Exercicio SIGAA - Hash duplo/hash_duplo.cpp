#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "hash_duplo.h"

using namespace std;


void inicializa(string vet[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        vet[i] = "-1";
    }
}

int h_hash(string word)
{
    int first = word[0];
    return first%M;
}

int g_hash(string word)
{
    int M1;
    M1 = M -2;
    int second = word[1];
    return 1 + (second%M1);
}

void inserir(string vet[], string word)
{
    int i=1;
    int posicao = h_hash(word);
    if(vet[posicao] == "-1" || vet[posicao] == "-2")
    {
        vet[posicao] = word;
    }
    else{
        while(i < M)
        {
            posicao = (h_hash(word) + i*g_hash(word))&M;
            if(vet[posicao] == "-1" || vet[posicao] == "-2");
            {
                vet[posicao] = word;
                i = M;
            }
            i++;
        }

    }
}

int busca(string vet[], string word)
{
    int i=1;
    int posicao = h_hash(word);
    if(vet[posicao] == word)
    {
        return posicao;
    }
    else{
        while(i < M)
        {
            posicao = (h_hash(word) + i*g_hash(word))&M;
            if(vet[posicao] == word);
            {
                return posicao;
            }
            i++;
        }

    }
}

int remover(string vet[], string word)
{
    int posicao = busca(vet, word);
    vet[posicao] = "-2";
}

void imprimir(string vet[])
{
    int i;
    for(i = 0; i < M; i++)
    {
        if(vet[i] != "-1" && vet[i] != "-2")
        {
            cout << vet[i] << endl;
        }
    }
    cout << endl;
}
