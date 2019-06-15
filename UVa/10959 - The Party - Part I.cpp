//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[1003];
int d[1003], source, dest;
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
    freopen("10959.txt", "r", stdin);
    int i, t, cas=1, n, couple;
    int A, B;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &couple);
        for(i=0;i<couple;i++)
        {
            cin>>A>>B;
            g[A].push_back(B);
            g[B].push_back(A);
        }
        memset(d, 0, sizeof(d));
        bfs();
        if(cas>1)
            printf("\n");
        for(i=1;i<n;i++)
            printf("%d\n", d[i]);
        for(i=0;i<n;i++)
            g[i].resize(0);
        cas++;
    }
    return 0;
}


