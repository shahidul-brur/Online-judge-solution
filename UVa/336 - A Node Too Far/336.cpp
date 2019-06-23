//Accepted

#include <bits/stdc++.h>
using namespace std;
int visited[32], v[32][500];
vector<int> mutual[32];
map <int, int> connect;
void visit(int node, int ttl)
{
    visited[node]=1;
    v[node][ttl]=1;
    if(ttl>0)
    {
        for(int i=0;i<mutual[node].size();i++)
            if(v[mutual[node][i]][ttl-1]==0)
                visit(mutual[node][i], ttl-1);
    }
}
int main()
{
    //freopen("336.txt", "r", stdin);
    int connection, cas=1, unreached, node1, j, node2, initNode, initTTL, i, c;

    while(cin>>connection)
    {
        if(connection==0)
            break;
        connect.clear();
        c=0;

        for(i=0;i<connection;i++)
        {
            cin>>node1>>node2;
            if(connect.find(node1)==connect.end())
                connect[node1]=c++;

            if(connect.find(node2)==connect.end())
                connect[node2]=c++;
            mutual[connect[node1]].push_back(connect[node2]);
            mutual[connect[node2]].push_back(connect[node1]);
        }
        while(cin>>initNode>>initTTL)
        {
            if(initNode==0 && initTTL==0)
                break;
            memset(visited, 0, sizeof (visited));
            memset(v, 0, sizeof (v));
            visited[connect[initNode]]=1;
            visit(connect[initNode], initTTL);
            for(i=0, unreached=0;i<c;i++)
                if(visited[i]==0)
                    unreached++;
            cout<<"Case "<<cas<<": "<<unreached<<" nodes not reachable from node "<<initNode<<" with TTL = "<<initTTL<<"."<<endl;
            cas++;
        }
        for(i=0;i<c;i++)
            mutual[i].resize(0);
    }
    return 0;
}
