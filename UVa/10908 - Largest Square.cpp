//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("10908.txt", "r", stdin);
    int M, N, Q, i, L, t, r, c, round, left, right, up, down,p;
    char grid[102][102], centr;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &M, &N, &Q);
        printf("%d %d %d\n", M, N, Q);
        getchar();
        for(i=0;i<M;i++)
            gets(grid[i]);

        for(i=1;i<=Q;i++)
        {
            scanf("%d %d", &r, &c);


            if(r<M && c<N)
            {
                L=1;
                centr=grid[r][c];
                round=1;
            }
            else
            {
                L=0;
                round=0;
            }
            up=down=r;
            left=right=c;
            while(round==1)
            {
                for(up=up-1, p=left-1;p<=right+1&&round==1;p++)
                    if(up>=M || up<0 || p>=N || p<0)
                    {
                        round=0;
                        break;
                    }
                    else if(grid[up][p]!=centr)
                    {
                        round=0;
                        break;
                    }
                for(down=down+1, p=left-1; p<=right+1&& round==1;p++)
                    if(down>=M || down<0 || p>=N || p<0)
                    {
                        round=0;
                        break;
                    }
                    else if(grid[down][p]!=centr)
                    {
                        round=0;
                        break;
                    }
                for(left=left-1, p=up+1;p<=down-1&&round==1;p++)
                    if(left<0 || left>=N || p>=M || p<0)
                    {
                        round=0;
                        break;
                    }
                    else if(grid[p][left]!=centr)
                    {
                        round=0;
                        break;
                    }
                for(right=right+1, p=up+1;p<=down-1&&round==1;p++)
                    if(right<0 || right>=N || p>=M || p<0)
                    {
                        round=0;
                        break;
                    }
                    else if(grid[p][right]!=centr)
                    {
                        round=0;
                        break;
                    }
                if(round==1)
                    L+=2;
            }
            printf("%d\n",L);
        }
    }
    return 0;
}
