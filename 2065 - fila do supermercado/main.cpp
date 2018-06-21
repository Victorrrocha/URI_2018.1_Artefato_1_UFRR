#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main()
{
    int n,m, i;
    int caixa_temp, compras;
    cin >> n >> m;
    //scanf("%d", &n, &m);
    int caixa[n];
    int cliente[m];

    for(i=0; i<n; i++)
    {
        cin >> caixa_temp;
        caixa[i] = caixa_temp;
    }

    for(i=0; i<m; i++)
    {
        cin >> compras;
        cliente[i] = compras;
    }

    int temp[n];
    int t = 0, time =0;

    while(t < m)
    {
        if(t<n)
        {
            temp[t] = cliente[t]*caixa[t];
            t++;
        }
        else
        {
            int index = temp[0];
            int z = 0;
            for(i = 0; i < n; i++)
            {
                if(index>temp[i])
                {
                    index = temp[i];
                    z=i;
                }
            }
            temp[z]+=cliente[t]*caixa[z];
            z = 0;
            t++;
        }
    }
    int index = temp[0];
    for(i =0; i< n; i++)
    {
        if(index < temp[i])
            index = temp[i];
    }
    cout << index << endl;

    return 0;
}
