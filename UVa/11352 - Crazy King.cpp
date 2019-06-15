//Accepted

#include <bits/stdc++.h>
using namespace std;
int x[]={2, 2, -2, -2, 1, 1, -1, -1}, y[]={1, -1, 1, -1, 2, -2, 2, -2};
int X[]={0, 0, 1, -1, -1, -1, 1, 1}, Y[]={1, -1, 0, 0, 1, -1, -1, 1};
int moves[110][110], sR, sC, dR, dC, m, n;
char grid[110][110];
int valid(int x, int y)
{
    if(x>=0 && x<m && y>=0 && y<n)
        return 1;
    return 0;
}
void lowestMove()
{
    queue<int> r;
    queue<int> c;
    r.push(sR);
    c.push(sC);
    moves[sR][sC]=1;
    while(!r.empty())
    {
        int ur=r.front(), uc=c.front();
        r.pop(); c.pop();
        for(int i=0;i<8;i++)
        {
            int vr=ur+X[i], vc=uc+Y[i];
            if(valid(vr, vc)==1)
            {
                if((grid[vr][vc]=='.' || grid[vr][vc]=='B') && moves[vr][vc]==0)
                {
                    //printf("%d %d\n", vr, vc);
                    moves[vr][vc]=moves[ur][uc]+1;
                    r.push(vr);
                    c.push(vc);
                }
            }
        }
    }
}
int main()
{
    freopen("11352.txt", "r", stdin);
    int t, i, j, k, l;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=0;i<m;i++)
        {
            scanf("%s", grid[i]);
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='A')
                    sR=i, sC=j;
                else if(grid[i][j]=='B')
                    dR=i, dC=j;
            }
        }
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                if(grid[j][k]=='Z')
                {
                    for(int i=0;i<8;i++)
                    {
                        int vr=j+x[i], vc=k+y[i];
                        if(valid(vr, vc)==1)
                        {
                            if(grid[vr][vc]=='.')
                                grid[vr][vc]='*';
                        }
                    }
                }
            }
        }
        memset(moves, 0, sizeof(moves));
        lowestMove();
        if(moves[dR][dC]<=1)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n", moves[dR][dC]-1);
    }
    return 0;
}

