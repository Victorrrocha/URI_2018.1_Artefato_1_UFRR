#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

///Algoritmo de Tarjan adiquirido em https://www.geeksforgeeks.org/detect-cycle-in-a-graph///

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

/// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;
    return false;
}

/// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

int main()
{
    int T, N, M, A, B, i, j;

    cin >> T;
    for(i=0; i<T; i++){

        cin >> N; cin >> M;
        Graph lista(N+1);
        for(j = 0; j < M; j++)
        {
            cin >> A; cin >> B;
            lista.addEdge(A, B);
        }

        if(lista.isCyclic())
            cout << "SIM" <<endl;
        else
            cout << "NAO"<<endl;
    }
}
