//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[5000];
int d[5000], source, dest, parent[5000];
void bfs()
{
    queue<int> q;
    q.push(source);
    parent[source]=source;
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
                parent[v]=u;
            }
        }
    }
}
int main()
{
    freopen("10009.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, M, N, n=0, path[5000], p, j, t, cas=1;
    string A, B;
    map<string, int> mp;
    map<int, string> ist;
    scanf("%d", &t);
    while(t--)
    {
        cin>>M>>N;
        for(i=0;i<M;i++)
        {
            cin>>A>>B;
            if(mp.find(A)==mp.end())
            {
                mp[A]=n;
                ist[n]=A;
                n++;
            }
            if(mp.find(B)==mp.end())
            {
                mp[B]=n;
                ist[n]=B;
                n++;
            }
            g[mp[A]].push_back(mp[B]);
            g[mp[B]].push_back(mp[A]);
        }
        if(cas>1)
            printf("\n");
        for(i=0;i<N;i++)
        {
            cin>>A>>B;
            source=mp[A];
            dest=mp[B];
            memset(d, 0, sizeof(d));
            memset(parent, 0, sizeof(parent));
            bfs();

            for(j=dest, p=0;;p++)
            {
                path[p]=j;
                if(j==source)
                    break;
                j=parent[j];
            }
            for(j=p;j>=0;j--)
            {
                A=ist[path[j]];
                printf("%c", A[0]);
            }
            printf("\n");

        }


        for(j=0;j<=n;j++)
            g[j].resize(0);
        mp.clear();
        ist.clear();
        cas++;
    }
    return 0;
}

