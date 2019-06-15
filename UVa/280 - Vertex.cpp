//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> graph[102];
int visited[102];
void BFS(int source)
{
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    //freopen("280.txt", "r", stdin);
    int node, i, edge, e, test, start;
    vector<int> unreach;
    while(cin>>node)
    {
        if(node==0)
            break;
        while(cin>>edge)
        {
            if(edge==0)
                break;
            while(cin>>e)
            {
                if(e==0)
                    break;
                graph[edge].push_back(e);
            }
        }
        cin>>test;
        while(test--)
        {
            cin>>start;
            memset(visited, 0, sizeof(visited));
            BFS(start);

            for(i=1;i<=node;i++)
                if(visited[i]==0)
                    unreach.push_back(i);

            cout<<unreach.size();
            for(i=0;i<unreach.size();i++)
                cout<<" "<<unreach[i];
            cout<<'\n';
            unreach.resize(0);
        }
        for(i=0;i<=node;i++)
            graph[i].resize(0);
    }
    return 0;
}
