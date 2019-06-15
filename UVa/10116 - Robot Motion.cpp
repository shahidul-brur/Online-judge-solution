//Accepted

#include <bits/stdc++.h>
using namespace std;
int R, C, S, finish, visit[500][500], loop, lr, lc;
char grid[500][500];
int GO(int r, int c, int step)
{
    if(visit[r][c]>0)
    {
        loop=1;
        lr=r;
        lc=c;
        return step;
    }
    if(visit[r][c]==0)
        visit[r][c]=step;
    int rr=r, cc=c;
    if(grid[r][c]=='E')
        cc=c+1;
    else if(grid[r][c]=='W')
        cc=c-1;
    else if(grid[r][c]=='N')
        rr=r-1;
    else if(grid[r][c]=='S')
        rr=r+1;
    if(rr<0 || rr>=R || cc<0 || cc>=C)
    {
        finish=1;
        return step;
    }
    GO(rr, cc, step+1);
}
int main()
{
    //freopen("10116.txt", "r", stdin);
    int i, mov;
    while(cin>>R>>C>>S)
    {
        if(R==0 && C==0 && S==0)
            break;
        for(i=0;i<R;i++)
            cin>>grid[i];
        finish=loop=0;
        memset(visit, 0, sizeof(visit));
        mov=GO(0, S-1, 1);
        if(loop==1)
            printf("%d step(s) before a loop of %d step(s)\n", visit[lr][lc]-1, mov-visit[lr][lc]);
        else printf("%d step(s) to exit\n", mov);
    }
    return 0;
}
