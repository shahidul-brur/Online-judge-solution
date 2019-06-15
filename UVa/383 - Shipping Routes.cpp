//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[40];
int d[40], source, dest;
void bfs()
{
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]==0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("383.txt", "r", stdin);
    int i, t, cas=1, M, N, P, shipment;
    string A, B;
    map<string, int> mp;
    scanf("%d", &t);
    printf("SHIPPING ROUTES OUTPUT\n");
    while(t--)
    {
        scanf("%d %d %d", &M, &N, &P);
        for(i=0;i<M;i++)
        {
            cin>>A;
            mp[A]=i;
        }
        for(i=0;i<N;i++)
        {
            cin>>A>>B;
            g[mp[A]].push_back(mp[B]);
            g[mp[B]].push_back(mp[A]);
        }
        printf("\nDATA SET  %d\n\n", cas);
        for(i=0;i<P;i++)
        {
            cin>>shipment>>A>>B;
            source=mp[A];
            dest=mp[B];
            memset(d, 0, sizeof(d));
            bfs();
            if(d[dest]==0)
                printf("NO SHIPMENT POSSIBLE\n");
            else
                printf("$%d\n", shipment*d[dest]*100);
        }
        for(i=0;i<M;i++)
        {
            g[i].resize(0);
        }
        mp.clear();
        cas++;
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}

