#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//ÁRVORE DE SEGMENTO DO PRODUTO
int buildsegTree(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
        return vet[low];
    } else {
        int mid = (low + high) / 2;
        int Esq = buildsegTree(segTree, vet, low, mid, 2 * pos);
        int Dir = buildsegTree(segTree, vet, mid + 1 , high, 2 * pos + 1);
        segTree[pos] = Esq * Dir;
        return segTree[pos];
    }
}

//TROCA E ATUALIZA UMA ARVORE DE SEGMENTO
int troca(int segTree[], int low, int high, int indice, int pos, int valor){
    if(indice == low && indice == high){
        segTree[pos] = valor;
        return segTree[pos];
    }
    if(indice > high || indice < low){
        return 1;
    }
    int mid = (low + high) / 2;
    int esq = troca(segTree, low, mid, indice, 2 * pos, valor);
    int dir = troca(segTree, mid + 1, high, indice, 2 * pos + 1, valor);

    return segTree[pos] = segTree[pos * 2] * segTree[pos * 2 + 1];
}

//BUSCA EM UMA ARVORE DE SEGMENTO
int search(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return 1;
    }
    int mid = (low + high) / 2;
    int Esq = search(segTree, low, mid, qlow, qhigh, 2 * pos);
    int Dir = search(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 1);
    return Esq * Dir;
}

int main() {
    int segTree[400005];
    int vet[100005];
    int m, tam_segTree;
    int n, k, i, v, valor, result;
    char op[1];

    for (m=1; m<100005; m++){
        vet[m] = 1;
    }

    while(scanf("%d %d",&n, &k) != EOF){

        for(m = 1; m <= n; m++){
            scanf("%d", &valor);
            if(valor>0){
                vet[m] = 1;
            } else if(valor<0){
                vet[m] = -1;
            } else {
                vet[m] = 0;
            }
        }

        tam_segTree = 4*n-1;

        buildsegTree(segTree, vet, 1, n, 1);

        for(m = 0; m < k; m++){
            scanf(" %c %d %d", &op, &i, &v);
            if(op[0] == 'C'){
                if(v>0){
                    troca(segTree, 1, n, i, 1, 1);
                } else if(v<0){
                    troca(segTree, 1, n, i, 1, -1);
                } else {
                    troca(segTree, 1, n, i, 1, 0);
                }

            } else if(op[0] == 'P'){
                result = search(segTree, 1, n, i, v, 1);
                if(result>0){
                    printf("+");
                } else if(result<0){
                    printf("-");
                } else {
                    printf("0");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
