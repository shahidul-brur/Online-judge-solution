//Accepted

#include <bits/stdc++.h>
using namespace std;
int R, C, x[]={0, -1, 0, 1}, y[]={-2, 0, 2, 0}, visited[52][52], gr, gc, SL[52][52];
char maze[52][52];
bool valid(int x, int y)
{
    if(x<2*R && x>0 && y>0 && y<4*C)
    {
        if(maze[x][y]==' ')
            return true;
        else return false;
    }
    else return false;
}
int GO(int r, int c, int step)
{
    visited[r][c]=1;
    if(step==1)
        SL[r][c]=step;
    if(r==gr && c==gc)
    {
        SL[r][c]=step;
        return 1;
    }
    for(int i=0;i<4;i++)
    {
        int rr=r+x[i];
        int cc=c+y[i];
        if(valid(rr, cc) && visited[rr+x[i]][cc+y[i]]==0)
        {
            if(GO(rr+x[i], cc+y[i], step+1)==1)
            {
                SL[r][c]=step;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("614.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int rS, cS, rG, cG, i, j, k, cas=1, p;
    while(cin>>R>>C>>rS>>cS>>rG>>cG)
    {
        if(R==0 && C==0 && rS==0 &&cS==0 && rG==0 &&cG==0)
            break;
        for(i=0;i<=R*2;i++)
        {
            for(j=0;j<=C*4;j++)
            {
                if(i%2==0 && j%4==0)
                    maze[i][j]='+';
                else if((i==0 || i==R*2) && j%4!=0)
                    maze[i][j]='-';
                else if(i%2==1 && (j==0 || j==C*4))
                        maze[i][j]='|';
                else maze[i][j]=' ';
            }
            maze[i][j+1]='\0';
        }
        for(i=1;i<=R;i++)
        {
            for(j=1;j<=C;j++)
            {
                cin>>p;
                if(p==1 || p==3)
                    maze[i*2-1][j*4]='|';
                if(p==2 || p==3)
                    maze[i*2][(j-1)*4+1]=maze[i*2][(j-1)*4+2]=maze[i*2][(j-1)*4+3]='-';
            }
        }
        gr=rG*2-1;
        gc=(cG-1)*4 + 2;
        memset(SL, 0, sizeof(SL));
        memset(visited, 0, sizeof(visited));
        GO(rS*2-1, (cS-1)*4+2, 1);
        cout<<"Maze "<<cas<< '\n'<<'\n';
        for(i=0;i<=R*2;i++)
        {
            for(j=0;j<=C*4;j++)
            {
                if(i%2==1 && j%4==1)
                {
                    if(SL[i][j+1]!=0)
                        printf("% 3d", SL[i][j+1]);
                    else if(SL[i][j+1]==0 && visited[i][j+1]==1)
                        printf("???");
                    else printf("   ");
                    j+=2;
                }
                else printf("%c", maze[i][j]);
            }
            cout<< '\n';
        }
        cout<< '\n'<< '\n';
        cas++;
    }
    return 0;
}
