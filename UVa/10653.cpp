//Accepted

#include <bits/stdc++.h>
#define MIN(a, b) (a<b ? a:b)
int x[]={0, 0, 1, -1}, y[]={1, -1, 0, 0};
using namespace std;
char grid[1002][1002];
int dis[1002][1002], R, C, sR, sC, dR, dC;
int valid(int x, int y)
{
    if(x>=0 && x<R && y>=0 && y<C)
        if(grid[x][y]=='.')
            return 1;
    return 0;
}
int lowestPath()
{
    queue<int> r;
    queue<int> c;
    r.push(sR);
    c.push(sC);
    while(!r.empty())
    {
        int ur=r.front(), uc=c.front();
        r.pop(); c.pop();
        for(int i=0;i<4;i++)
        {
            int vr=ur+x[i], vc=uc+y[i];
            if(valid(vr, vc)==1)
            {
                if(dis[vr][vc]==0)
                {
                    dis[vr][vc]=dis[ur][uc]+1;
                    r.push(vr);
                    c.push(vc);
                }
            }
        }
    }
    return dis[dR][dC];
}
int main()
{
    freopen("10653.txt", "r", stdin);
    int row, col, i, j, bomb, amount, ans;
    while(scanf("%d %d", &R, &C)!=EOF)
    {
        if(R==0 && C==0)
            break;
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
                grid[i][j] = '.';   //possible to go away by this point of grid, so set .
        scanf("%d", &bomb); //how many row contain one or more bomb ?
        for(i=0;i<bomb;i++)
        {
            scanf("%d %d", &row, &amount); //in which row and how many bomb in that row?
            for(j=0;j<amount;j++)
            {
                scanf("%d", &col);  // in which column of that row contain a bomb
                grid[row][col]='*';  //there is bomb! so not possible to go away by this point of grid, and so set 0
            }
        }

        memset(dis, 0, sizeof(dis));
        scanf("%d %d %d %d", &sR, &sC, &dR, &dC); //from which position? and where to go?
        ans=lowestPath();
        printf("%d\n", ans);
    }
    return 0;
}
