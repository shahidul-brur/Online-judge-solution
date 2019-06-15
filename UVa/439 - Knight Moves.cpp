//Accepted

#include <bits/stdc++.h>
using namespace std;
int x[]={2, 2, -2, -2, 1, 1, -1, -1}, y[]={1, -1, 1, -1, 2, -2, 2, -2};
int moves[10][10], sR, sC, dR, dC;
int valid(int x, int y)
{
    if(x>=1 && x<=8 && y>=1 && y<=8)
       return 1;
    return 0;
}
void lowestMove()
{
    queue<int> r;
    queue<int> c;
    r.push(sR);
    c.push(sC);
    while(!r.empty())
    {
        int ur=r.front(), uc=c.front();
        r.pop(); c.pop();
        for(int i=0;i<8;i++)
        {
            int vr=ur+x[i], vc=uc+y[i];
            if(valid(vr, vc)==1)
            {
                if(moves[vr][vc]==0)
                {
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
    freopen("439.txt", "r", stdin);
    char from[4], to[4];
    while(scanf("%s %s", from, to)!=EOF)
    {
        sR=from[0]-'a'+1;
        sC=from[1]-'0';
        dR=to[0]-'a'+1;
        dC=to[1]-'0';
        memset(moves, 0, sizeof(moves));
        if(strcmp(from, to)!=0)
            lowestMove();
        printf("To get from %s to %s takes %d knight moves.\n", from, to, moves[dR][dC]);
    }
    return 0;
}
