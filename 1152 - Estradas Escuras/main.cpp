#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

typedef struct grafo
{
    int V, E;
    vector<pair<int, iPair> > edges;
}Grafo;

struct DisjointSets
{
    int *pai, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        pai = new int[n+1];
        rnk = new int[n+1];

        for(int i=0; i <= n; i++)
        {
            rnk[i] = 0;

            pai[i] = i;
        }
    }

    int find(int u)
    {
        if(u != pai[u])
            pai[u] = find(pai[u]);
        return pai[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if(rnk[x] > rnk[y])
            pai[y] = x;
        else
            pai[x] = y;

        if(rnk[x] == rnk[y])
            rnk[y]++;
    }
};

Grafo*criar_grafo(int V, int E)
{
    Grafo*x = new Grafo;
    x->V = V;
    x->E = E;
}

void addEdge(Grafo*x, int inicio, int destino, int peso)
{
    x->edges.push_back({peso, {inicio, destino}});
}

int Kruskal(Grafo*G)
{
    int mst_wt = 0;

    sort(G->edges.begin(), G->edges.end());
    DisjointSets ds(G->V);

    vector< pair<int, iPair> >::iterator it;
    for(it = G->edges.begin(); it != G->edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v)
        {
            //cout << u << " - " << v <<endl;

            mst_wt+= it->first;

            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{
    int n, m, i;
    int ini, fim, peso, total = 0;
    while(1)
    {
        cin >> n >> m;
        Grafo*g = criar_grafo(n, m);

        if(n == 0 && m == 0)
            return 0;

        for(i = 0; i < m; i++)
        {
            cin >> ini >> fim >> peso;
            total += peso;
            addEdge(g, ini, fim, peso);
        }

        //cout << "Edges of MST are \n";
        int mst_wt = Kruskal(g);

        cout << total - mst_wt << endl;
        total = 0;
    }
    return 0;
}
