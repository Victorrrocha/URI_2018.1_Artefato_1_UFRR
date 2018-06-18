#include <iostream>
#include <stdio.h>

using namespace std;

struct hash_table
{
    int info;
    hash_table*next;
};

void inserir(hash_table*tabela[], int posicao, int numero)
{
    hash_table* novo;
    novo = new hash_table();
    novo->info = numero;
    if(tabela[posicao] != NULL)
        tabela[posicao]->next = novo;
    else
        tabela[posicao] = novo;
    novo->next = NULL;
}

int mod(int n, int m)
{
    return n%m;
}

void imprime(hash_table* tabela[], int m)
{
    hash_table* aux;
    for(int i = 0; i < m; i++)
    {
        cout << i << " -> ";
        aux = tabela[i];
        while(aux != NULL)
        {
            cout << aux->info << " -> ";
            aux = aux->next;
        }
        cout << "\\" << "\n";
    }
}

void inicializar(hash_table* tabela[], int m)
{
    for(int i = 0; i < m; i++)
    {
        tabela[i] = NULL;
    }
}

int main()
{
    int N, M, C,n, i, j;
    int posicao;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d", &M, &C);
        hash_table* tabela[M];
        hash_table* aux;

        inicializar(tabela, M);

        for(j = 0; j < C; j++)
        {
            scanf("%d", &n);
            posicao = mod(n, M);
            if(posicao <= M)
                inserir(tabela, posicao, n);
        }
        imprime(tabela, M);
    }
    return 0;
}
