/**********************************************************
Status:     Accepted
Problem:    11049 - Basic wall maze
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 13 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
typedef struct squre
{
    int row, col;
};
int startR, startC, finishR, finishC, wallW[8][8], wallS[8][8], wallN[8][8], wallE[8][8];
int visited[8][8];
squre parent[8][8];
void bfs()
{
    queue<int> r;
    queue<int> c;
    r.push(startR);
    c.push(startC);
    visited[startC][startR]=1;
    while(!r.empty())
    {
        int ur=r.front();
        r.pop();
        int uc=c.front();
        c.pop();
        int vr, vc;
        squre s;
        s.row=ur;
        s.col=uc;

        vr=ur+1;
        vc=uc;
        if(vr>=1 && vr<=6 && vc>=1 && vc<=6 && wallS[uc][ur]==0 && visited[vc][vr]==0)
        {
            parent[vc][vr]=s;
            visited[vc][vr]=1;
            r.push(vr);
            c.push(vc);
            //printf("%d %d\n", vc, vr);
        }

        vr=ur-1;
        vc=uc;
        if(vr>=1 && vr<=6 && vc>=1 && vc<=6 && wallN[uc][ur]==0 && visited[vc][vr]==0)
        {
            parent[vc][vr]=s;
            visited[vc][vr]=1;
            r.push(vr);
            c.push(vc);
            //printf("%d %d\n", vc, vr);
        }

        vr=ur;
        vc=uc+1;
        if(vr>=1 && vr<=6 && vc>=1 && vc<=6 && wallE[uc][ur]==0 && visited[vc][vr]==0)
        {
            parent[vc][vr]=s;
            visited[vc][vr]=1;
            r.push(vr);
            c.push(vc);
            //printf("%d %d\n", vc, vr);
        }

        vr=ur;
        vc=uc-1;

        if(vr>=1 && vr<=6 && vc>=1 && vc<=6 && wallW[uc][ur]==0 && visited[vc][vr]==0)
        {
            parent[vc][vr]=s;
            visited[vc][vr]=1;
            r.push(vr);
            c.push(vc);
            //printf("%d %d\n", vc, vr);
        }
    }
}
int main()
{
    //freopen("11049.txt", "r", stdin);
    int i, j, sr, sc, fr, fc, k, a, b;
    squre SL[40];
    char ans[40];
    while(cin>>startC>>startR)
    {
        if(startC==0 && startR==0)
            break;
        cin>>finishC>>finishR;
        memset(wallW, 0, sizeof(wallW));
        memset(wallE, 0, sizeof(wallE));
        memset(wallN, 0, sizeof(wallN));
        memset(wallS, 0, sizeof(wallS));
        memset(visited, 0, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        memset(SL, 0, sizeof(SL));
        for(i=1;i<=3;i++)
        {
            cin>>sc>>sr>>fc>>fr;
            if(sc==fc)
            {
                for(j=sr+1;j<=fr;j++)
                    wallE[sc][j]=1;
                for(j=sr+1;j<=fr;j++)
                    wallW[sc+1][j]=1;
            }
            else if(sr==fr)
            {
                for(j=sc+1;j<=fc;j++)
                    wallS[j][sr]=1;
                for(j=sc+1;j<=fc;j++)
                    wallN[j][sr+1]=1;
            }
        }

        bfs();
        a=finishR;
        b=finishC;
        k=0;
        for(;;)
        {
            SL[k].col=b;
            SL[k].row=a;
            k++;
            if(parent[b][a].row==startR && parent[b][a].col==startC)
                break;
            i=parent[b][a].row;
            j=parent[b][a].col;
            a=i;
            b=j;
        }
        SL[k].col=startC;
        SL[k].row=startR;
        for(i=k;i>0;i--)
        {
            if(SL[i].row==SL[i-1].row && SL[i].col==SL[i-1].col+1)
                printf("W");
            else if(SL[i].row==SL[i-1].row && SL[i].col==SL[i-1].col-1)
                printf("E");
            else if(SL[i].row==SL[i-1].row+1 && SL[i].col==SL[i-1].col)
                printf("N");
            else if(SL[i].row==SL[i-1].row-1 && SL[i].col==SL[i-1].col)
                printf("S");

        }
        printf("\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
