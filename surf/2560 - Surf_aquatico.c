#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int x, int y){
    return (x < y) ? x : y;
}

int maior(int x, int y){
    return (x > y) ? x : y;
}
//ÁRVORE DE SEGMENTO QUE ENCONTRA O MENOR
void buildMinsegTree(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
    } else {
        int mid = (low + high) / 2;
        buildMinsegTree(segTree, vet, low, mid, 2 * pos);
        buildMinsegTree(segTree, vet, mid + 1 , high, 2 * pos + 1);
        segTree[pos] = min(segTree[2 * pos], segTree[2 * pos + 1]);
    }
}

//ÁRVORE DE SEGMENTO QUE ENCORNTRA O MAIOR
void buildMaxsegTree(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
    } else {
        int mid = (low + high) / 2;
        buildMaxsegTree(segTree, vet, low, mid, 2 * pos);
        buildMaxsegTree(segTree, vet, mid + 1 , high, 2 * pos + 1);
        segTree[pos] = maior(segTree[2 * pos], segTree[2 * pos + 1]);
    }
}

//ÁRVORE DE SEGMENTO DA SOMA
int buildsegTreeSoma(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
        return vet[low];
    } else {
        int mid = (low + high) / 2;
        int somaEsq = buildsegTreeSoma(segTree, vet, low, mid, 2 * pos);
        int somaDir = buildsegTreeSoma(segTree, vet, mid + 1 , high, 2 * pos + 1);
        segTree[pos] = somaEsq + somaDir;
        return segTree[pos];
    }
}

//BUSCA EM UMA ARVORE DE SEGMENTO
int searchMinimum(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    return min(searchMinimum(segTree, low, mid, qlow, qhigh, 2 * pos),
               searchMinimum(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 1));
}

int searchMaximum(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    return maior(searchMaximum(segTree, low, mid, qlow, qhigh, 2 * pos),
               searchMaximum(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 1));
}

int searchSoma(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return 0;
    }
    int mid = (low + high) / 2;
    int somaEsq = searchSoma(segTree, low, mid, qlow, qhigh, 2 * pos);
    int somaDir = searchSoma(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 1);
    return somaEsq + somaDir;
}

int main() {
    int segTreeMin[800000];
    int segTreeMax[800000];
    int segTreeSoma[800000];
    int vet[200000];
    int i, v, tam_segTree;
    int TAM, b;

    long int somaTotal;
    long int somaMin;
    long int somaMax;
    long int score;

    while(scanf("%d %d",&TAM, &b) != EOF){

        somaTotal = 0;
        somaMin = 0;
        somaMax = 0;
        score = 0;

        for(i = 1; i <= TAM; i++){
            scanf("%d", &v);
            vet[i] = v;
        }

        buildMinsegTree(segTreeMin, vet, 1, TAM, 1);
        buildMaxsegTree(segTreeMax, vet, 1, TAM, 1);
        buildsegTreeSoma(segTreeSoma, vet, 1, TAM, 1);

        for(i=0; i<=TAM-b; i++){
            int qhigh = b+i;

            somaTotal += searchSoma(segTreeSoma, 1, TAM, i+1, qhigh, 1);
            somaMin += searchMinimum(segTreeMin, 1, TAM, i+1, qhigh, 1);
            somaMax += searchMaximum(segTreeMax, 1, TAM, i+1, qhigh, 1);
        }

        score = somaTotal - (somaMin + somaMax);

        printf("%ld\n", score);
    }
    return 0;
}

