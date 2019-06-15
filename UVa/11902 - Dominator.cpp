/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int adj[102][102];
int vis[102][102];
int n;
void bfs(int source, int target)
{
    queue<int> q;
    q.push(source);
    vis[target][source]=1;
    int f=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(adj[u][i]==1)
            {
                vis[target][i]++;
                if(i==target)
                {
                    f=1;
                    break;
                }
                if(vis[target][i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(f==1)
            break;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &adj[i][j]);

    memset(vis, 0, sizeof(vis));

    for(int i=0;i<n;i++)
        bfs(0, i);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", vis[j][i]);
            /*
            if(vis[j][i]==1)
                printf("Y ");
            else printf("N ");
                */
        }
        printf("\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

