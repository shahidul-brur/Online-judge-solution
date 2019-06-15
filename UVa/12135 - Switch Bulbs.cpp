/**********************************************************
Status:     Accepted
Problem:    UVa : 12135 - Switch Bulbs
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 28 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
map<string, int> id;
vector<int> toggles[45];
char target[20];
int dis[32800], visited[32800], bulbs, switc;
void bfs(char *start)
{
    queue<string> q;
    q.push(start);
    visited[0]=1;
    dis[0]=0;
    while(!q.empty())
    {
        char u[20];
        strcpy(u, q.front().c_str());
        q.pop();
        char *ptr;
        int from=strtol(u, &ptr, 2);
        for(int i=0;i<switc;i++)
        {
            char v[20];
            strcpy(v, u);
            for(int j=0;j<toggles[i].size();j++)
            {
                int p=bulbs-1-(toggles[i][j]);
                if(u[p]=='0')
                    v[p]='1';
                else v[p]='0';
            }
            int index=strtol(v, &ptr, 2);
            if(visited[index]==0)
            {
                q.push(v);
                dis[index]=dis[from]+1;
                visited[index]=1;
            }
        }
    }
}
int main()
{
    //freopen("12135.txt", "r", stdin);
    int test, cas, query, toggle, i, j, ans, bulb;
    char start[20];
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>bulbs>>switc;
        for(i=0;i<bulbs;i++)
            start[i]='0';
        start[i]='\0';
        for(i=0;i<switc;i++)
        {
            cin>>toggle;
            while(toggle--)
            {
                cin>>bulb;
                toggles[i].push_back(bulb);
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(dis, -1, sizeof(dis));
        cin>>query;
        printf("Case %d:\n", cas);
        while(query--)
        {
            cin>>target;
            bfs(start);
            char *ptr;
            int dest=strtol(target, &ptr, 2);
            cout<<dis[dest]<<endl;
        }
        printf("\n");
        for(i=0;i<switc;i++)
            toggles[i].resize(0);
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
