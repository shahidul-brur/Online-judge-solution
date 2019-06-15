//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("10377.txt", "r", stdin);
    int t, cas=1, i, len, r, c, pR, pC;
    char maze[62][62], command[500], state;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        getchar();
        for(i=0;i<r;i++)
            gets(maze[i]);
        scanf("%d %d", &pR, &pC);
        pR--;
        pC--;
        getchar();
        state='N';
        if(cas>1)
            printf("\n");
        while(gets(command))
        {
            len=strlen(command);
            if(len==0)
                break;
            for(i=0;i<len;i++)
            {
                if(command[i]=='R')
                {
                    if(state=='N')
                        state='E';
                    else if(state=='S')
                        state='W';
                    else if(state=='E')
                        state='S';
                    else if(state=='W')
                        state='N';

                }
                else if(command[i]=='L')
                {
                    if(state=='N')
                        state='W';
                    else if(state=='S')
                        state='E';
                    else if(state=='E')
                        state='N';
                    else if(state=='W')
                        state='S';
                }
                else if(command[i]=='F')
                {
                    if(state=='N')
                    {
                        if(pR>0)
                        {
                            if(maze[pR-1][pC]==' ')
                                pR--;
                        }
                    }
                    else if(state=='S')
                    {
                        if(pR<r-1)
                        {
                            if(maze[pR+1][pC]==' ')
                                pR++;
                        }
                    }
                    else if(state=='E')
                     {
                        if(pC<c-1)
                        {
                            if(maze[pR][pC+1]==' ')
                                pC++;
                        }
                    }
                    else if(state=='W')
                    {
                        if(pC>0)
                        {
                            if(maze[pR][pC-1]==' ')
                                pC--;
                        }
                    }
                }
                else if(command[i]=='Q')
                {
                    printf("%d %d %c\n", pR+1, pC+1, state);
                }
            }
        }
        cas++;
    }
    return 0;
}
