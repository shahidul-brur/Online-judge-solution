//Accepted

#include <bits/stdc++.h>
using namespace std;
int X, Y;
int valid(int x, int y)
{
    if(x>=0 && x<=X && y>=0 && y<=Y)
        return 1;
    else return 0;
}
int ori(char p)
{
    if(p=='N')
        return 0;
    if(p=='S')
        return 1;
    if(p=='E')
        return 2;
    else if(p=='W')
        return 3;
}
char changeDir(char di, char ch)
{
    if(ch=='L')
    {
        if(di=='E')
            return 'N';
        else if(di=='W')
            return 'S';
        else if(di=='S')
            return 'E';
        else return 'W';
    }
    else if(ch=='R')
    {
        if(di=='E')
            return 'S';
        else if(di=='W')
            return 'N';
        else if(di=='S')
            return 'W';
        else return 'E';
    }
}
int main()
{
    freopen("118.txt", "r", stdin);
    int px, py, off[52][52], x[]={0, 0, 1, -1}, y[]={1, -1, 0, 0}, len, p, q, lost, i;
    char dir, inst[102], temp[3];
    scanf("%d %d", &X, &Y);
    memset(off, 0, sizeof(off));
    while(scanf("%d %d \n%c", &px, &py, &dir)!=EOF)
    {
        scanf("%s", inst);
        len=strlen(inst);
        lost=0;
        for(i=0;i<len;i++)
        {
            if(inst[i]=='F')
            {
                p=px+x[ori(dir)];
                q=py+y[ori(dir)];
                if(valid(p, q)==0)
                {
                    if(off[px][py]==0)
                    {
                        lost=1;
                        off[px][py]=1;
                        break;
                    }
                }
                else if(valid(p, q)==1)
                {
                    px=p;
                    py=q;
                }
            }
            else dir=changeDir(dir, inst[i]);
        }
        printf("%d %d %c", px, py, dir);
        if(lost==1)
            printf(" LOST");
        printf("\n");
    }
    return 0;
}
