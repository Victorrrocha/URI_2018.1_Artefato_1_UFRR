#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//ÁRVORE DE SEGMENTO DA SOMA
int buildsegTreeProd(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
        return vet[low];
    } else {
        int mid = (low + high) / 2;
        int somaEsq = buildsegTreeProd(segTree, vet, low, mid, 2 * pos + 1);
        int somaDir = buildsegTreeProd(segTree, vet, mid + 1 , high, 2 * pos + 2);
        segTree[pos] = somaEsq * somaDir;
        return segTree[pos];
    }
}

//BUSCA EM UMA ARVORE DE SEGMENTO
int searchProd(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return 1;
    }
    int mid = (low + high) / 2;
    int somaEsq = searchProd(segTree, low, mid, qlow, qhigh, 2 * pos + 1);
    int somaDir = searchProd(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 2);
    return somaEsq * somaDir;
}

int main() {
    int* segTreeProd;
    int* vet;
    int z, tam_segTree;
    int TAM, N, K, I, V, J;

    while(scanf("%d %d", &N, &K) != EOF)
    {

    }




        tam_segTree = 2 * TAM - 1;
        vet = (int*) malloc(TAM * sizeof(int));
        segTreeprod = (int*) malloc(tam_segTree * sizeof(int));



    return 0;
}
