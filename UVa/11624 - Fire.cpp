/**********************************************************
Status:     Accepted
Problem:    UVa 11624
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on: 08-08-2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6

typedef pair<int, int> pii;
char grid[1002][1002];
int Row, Col, dist[1002][1002], fireTime[1002][1002];
int x[]={0, 0, 1, -1};
int y[]={1, -1, 0, 0};
queue<pii> fires;
bool valid(int r, int c)
{
    if(r<0 || r>=Row || c<0 || c>=Col)
        return false;
    if(grid[r][c]=='#' || grid[r][c]=='F' || fireTime[r][c]>-1)
        return false;
    return true;
}
bool validMove(int r, int c)
{
    if(r<0 || r>=Row || c<0 || c>=Col)
        return false;
    if(grid[r][c]=='#' || grid[r][c]=='F' || dist[r][c]>-1)
        return false;
    return true;
}
void bfsFire()
{
    while(!fires.empty())
    {
        pii top = fires.front(); fires.pop();
        int r=top.first;
        int c=top.second;
        for(int i=0;i<4;i++)
        {
            int nr = r + x[i];
            int nc = c + y[i];
            if(valid(nr, nc))
            {
                fireTime[nr][nc] = fireTime[r][c] + 1;
                fires.push(pii(nr, nc));
            }
            
        }
    }
}
int bfs(int r, int c)
{
    if(r==0 || r==Row-1 || c==0 || c==Col-1)
        return 1;
    queue<pii> q;
    q.push(pii(r, c));
    dist[r][c]=0;
    while(!q.empty())
    {
        pii top = q.front(); q.pop();
        int r=top.first;
        int c=top.second;
        for(int i=0;i<4;i++)
        {
            int nr = r + x[i];
            int nc = c + y[i];
            if(validMove(nr, nc))
            {
                if(fireTime[nr][nc]==-1 || (dist[r][c] + 1)<fireTime[nr][nc])
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    if(nr==0 || nr==Row-1 || nc==0 || nc==Col-1)
                        return dist[nr][nc]+1;
                    q.push(pii(nr, nc));
                }
            }
            
        }
    }
    return -1;
}
int main()
{
    //freopen("11624.txt", "r", stdin);
    int test, cas, JR, JC;
    scanf("%d",&test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &Row, &Col);
        for(int i=0;i<Row;i++)
        {
            scanf("%s", grid[i]);
            for(int j=0;j<Col;j++)
            {
                dist[i][j]=-1;
                if(grid[i][j]=='J')
                {
                    JR=i;
                    JC=j;
                    fireTime[i][j]=-1;
                    dist[i][j]=0;
                }
                else if(grid[i][j]=='F')
                {
                    fires.push(make_pair(i, j));
                    fireTime[i][j]=0;
                }
                else fireTime[i][j]=-1;
            }
        }
        bfsFire();
        int d = bfs(JR, JC);
        if(d == -1)
            printf("IMPOSSIBLE\n");
        else printf("%d\n",d);
    }
    return 0;

}
/**********************************************************
About this problem:

************************************************************/
