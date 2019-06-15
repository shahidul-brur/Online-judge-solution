/**********************************************************
Status:     Accepted
Problem:    UVa 10977 - Enchanted Forest
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created:  - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int grid[202][202], dist[202][202], R, C;
int x[]={0, 0, 1, -1};
int y[]={1, -1, 0, 0};
bool valid(int r, int c)
{
    if(r<1 || r>R || c<1 || c>C)
        return 0;
    if(grid[r][c]==0)
        return 0;
    return 1;
}
int sqr(int x)
{
    return ((x)*(x));
}
int dis(int x1, int y1, int x2, int y2)
{
    int s = sqr(x1 - x2) + sqr(y1 - y2);
    int root = sqrt(s);
    if(root*root<s)
        root++;
    return root;
}
void bfs()
{
    queue<int> qr;
    queue<int> qc;
    qr.push(1);
    qc.push(1);
    dist[1][1]=0;
    while(!qr.empty())
    {
        int ur=qr.front();
        int uc=qc.front();
        qr.pop(); qc.pop();
        for(int i=0;i<4;i++)
        {
            int vr=ur+x[i];
            int vc=uc+y[i];
            if(valid(vr, vc) && dist[vr][vc]==-1)
            {
                dist[vr][vc]=dist[ur][uc]+1;
                qr.push(vr);
                qc.push(vc);
            }
        }
    }
}
int main()
{
    //freopen("10977.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, r, c, L, i, j, k;
    while(scanf("%d %d", &R, &C)!=EOF)
    {
        if(R==0 && C==0)
            break;
        for(i=0;i<=R+1;i++)
        {
            for(j=0;j<=C+1;j++)
            {
                grid[i][j]=1;
                dist[i][j]=-1;
            }
        }
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d", &r, &c);
            grid[r][c]=0;
        }
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d", &r, &c, &L);
            grid[r][c]=0;
            for(k=r-L;k<=r+L;k++)
            {
                for(j=c-L;j<=c+L;j++)
                {
                    if(valid(k, j))
                    {
                        int d = dis(r, c, k, j);
                        if(d<=L)
                            grid[k][j]=0;
                    }
                }
            }
        }
         
        bfs();
        if(dist[R][C]==-1)
            printf("Impossible.\n");
        else printf("%d\n", dist[R][C]);
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
