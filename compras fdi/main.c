#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TAM 100000

typedef struct segmentTree{
    int segTreeMin[TAM*4];
    int segTreeMax[TAM*4];
} SegTree;

int min(int x, int y){
    return (x < y) ? x : y;
}

int maior(int x, int y){
    return (x > y) ? x : y;
}
//ÁRVORE DE SEGMENTO QUE ENCONTRA O MENOR E MAIOR
void buildsegTree(SegTree *arv, int vet[], int low, int high, int pos){

    if(low == high){
        arv->segTreeMax[pos] = vet[low];
        arv->segTreeMin[pos] = vet[low];
        return;
    } else {
        int mid = (low + high) / 2;
        buildsegTree(arv, vet, low, mid, 2 * pos);
        buildsegTree(arv, vet, mid + 1 , high, 2 * pos + 1);

        arv->segTreeMax[pos] = maior(arv->segTreeMax[2 * pos], arv->segTreeMax[2 * pos + 1]);
        arv->segTreeMin[pos] = min(arv->segTreeMin[2 * pos], arv->segTreeMin[2 * pos + 1]);
    }
}
//TROCA E ATUALIZA UMA ARVORE DE SEGMENTO
void troca(SegTree *arv, int low, int high, int indice, int pos, int valor){
    if(indice == low && indice == high){
        arv->segTreeMin[pos] = valor;
        arv->segTreeMax[pos] = valor;
    } else if(indice > high || indice < low){
        return;
    } else {
        int mid = (low + high) / 2;
        troca(arv, low, mid, indice, 2 * pos, valor);
        troca(arv, mid + 1, high, indice, 2 * pos + 1, valor);
        arv->segTreeMax[pos] = maior(arv->segTreeMax[2 * pos], arv->segTreeMax[2 * pos + 1]);
        arv->segTreeMin[pos] = min(arv->segTreeMin[2 * pos], arv->segTreeMin[2 * pos + 1]);
    }
}

//BUSCA EM UMA ARVORE DE SEGMENTO
int searchMinimum(SegTree *arv, int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return arv->segTreeMin[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    return min(searchMinimum(arv, low, mid, qlow, qhigh, 2 * pos),
               searchMinimum(arv, mid + 1, high, qlow, qhigh, 2 * pos + 1));
}

int searchMaximum(SegTree *arv, int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return arv->segTreeMax[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    return maior(searchMaximum(arv, low, mid, qlow, qhigh, 2 * pos),
               searchMaximum(arv, mid + 1, high, qlow, qhigh, 2 * pos + 1));
}

void diferenca(SegTree *arv, int low, int high, int qlow, int qhigh, int pos){
    int min = searchMinimum(arv, low, high, qlow, qhigh, pos);
    int max = searchMaximum(arv, low, high, qlow, qhigh, pos);
    printf("%d\n", max - min);
}

void imprimirSegTree(SegTree *arv, int tam){
    int i,n;
    printf("MAX: ");
    for(i=1; i<=tam; i++){
        n = arv->segTreeMax[i];
        printf("%d ", n);
    }
    printf("\nMIN: ");
    for(i=1; i<=tam; i++){
        n = arv->segTreeMin[i];
        printf("%d ", n);
    }
     printf("\n");
}

int main() {
    int vet[TAM];
    int i, v, k;
    int min, max, dif;
    int op, x, y, n;

    SegTree *arv = (SegTree*) malloc(sizeof(SegTree));

    while(scanf("%d",&n) != EOF){

        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            vet[i] = v;
        }

        buildsegTree(arv, vet, 1, n, 1);

        scanf("%d", &k);
        for(i=0; i<k; i++){
            scanf("%d %d %d", &op, &x, &y);

            if(op == 1){
                troca(arv, 1, n, x, 1, y);
            } else {
                diferenca(arv, 1, n, x, y, 1);
            }
        }
    }
    return 0;
}
