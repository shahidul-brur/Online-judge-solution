//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("647.txt", "r", stdin);
    int dieThrow[1005], p, position[7], ex, jump[102], loseTurn[102], extraTurn[102], i, j, temp1, temp2, thr=1, turn, win;
    while(scanf("%d", &temp1)!=EOF)
    {
        if(temp1==0)
            break;
        dieThrow[thr++]=temp1;
    }
    while(scanf("%d", &temp1)!=EOF)
    {
        if(temp1==0)
            break;

        p=temp1;
        win=0;
        for(i=1;i<=100;i++)
            jump[i]=i;

        while(scanf("%d %d", &temp1, &temp2)!=EOF)
        {
            if(temp1==0 && temp2==0)
                break;
            jump[temp1]=temp2;
        }
        memset(extraTurn, 0, sizeof(extraTurn));
        memset(loseTurn, 0, sizeof(loseTurn));

        while(scanf("%d", &temp1)!=EOF)
        {
            if(temp1==0)
                break;
            temp2=temp1;
            if(temp2<0)
                temp2=0-temp2;
            if(temp1>0)
                extraTurn[temp2]=1;
            else loseTurn[temp2]=1;
        }
        for(i=1;i<=p;i++)
            position[i]=0;

        for(turn=1, i=1;i<thr;i++)
        {
            if(turn>p)
                turn=1;
            if(position[turn]==100)
            {
                win=turn;
                break;
            }
            if(loseTurn[position[turn]]==1);
            else
            {
                if(position[turn]+dieThrow[i]<=100)
                {
                    position[turn]+=dieThrow[i];
                    position[turn]=jump[position[turn]];
                }
                ex=0;
                while(extraTurn[position[turn]]==1)
                {
                    i++;
                    ex=1;
                    if(position[turn]+dieThrow[i]<=100)
                    {
                        position[turn]+=dieThrow[i];
                        position[turn]=jump[position[turn]];
                    }
                }
                if(ex==1)
                    i--;
            }
            if(position[turn]==100)
            {
                win=turn;
                break;
            }
            turn++;
        }
        printf("%d\n", win);
    }
    return 0;
}
