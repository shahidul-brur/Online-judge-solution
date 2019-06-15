//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> graph[22];
int dis[22][22];
void findShortestPath(int from)
{
    queue<int> q;
    q.push(from);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(dis[from][v]==0)
            {
                dis[from][v]=dis[from][u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("567.txt", "r", stdin);
    int i, n, from, to, city, c, cas=1, j;

    while(cin>>city)
    {
        for(i=0;i<city;i++)
        {
            cin>>c;
            graph[1].push_back(c);
            graph[c].push_back(1);
        }
        for(i=2;i<20;i++)
        {
            cin>>city;
            for(j=0;j<city;j++)
            {
                cin>>c;
                graph[i].push_back(c);
                graph[c].push_back(i);
            }
        }
        for(i=1;i<=20;i++)
            for(j=1;j<=20;j++)
                dis[i][j]=0;

        for(i=1;i<=20;i++)
            findShortestPath(i);
        cout<<"Test Set #"<<cas<<'\n';
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>from>>to;
            printf("%2d to %2d: %d\n", from, to, dis[from][to]);
        }
        cout<<'\n';
        for(i=0;i<=20;i++)
            graph[i].resize(0);
        cas++;
    }
    return 0;
}
