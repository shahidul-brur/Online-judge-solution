//Accepted

#include <stdio.h>
int isLeapyear(int year)
{
    if(year%100==0)
    {
        if(year%400==0)
            return 1;
        else return 0;
    }
    else
    {
        if(year%4==0)
            return 1;
        else
            return 0;
    }
}
int main()
{
    freopen("12148.txt", "r", stdin);
    int n, d[1001], m[1001], y[1001], i, unit[1001], total, cnt, day[14], nextD, nextM, nextY, D;
    day[1]=day[3]=day[5]=day[7]=day[8]=day[10]=day[12]=31;
    day[2]=28;
    day[4]=day[6]=day[9]=day[11]=30;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        cnt=total=0;
        scanf("%d %d %d %d", &d[0], &m[0], &y[0], &unit[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d %d", &d[i], &m[i], &y[i], &unit[i]);
            if(m[i-1]==2 && isLeapyear(y[i-1])==1)
                D=29;
            else
                D=day[m[i-1]];
            if(d[i-1]<D)
            {
                nextD=d[i-1]+1;
                nextM=m[i-1];
                nextY=y[i-1];
            }
            else
            {
                nextD=1;
                nextM=m[i-1]+1;
                nextY=y[i-1];
                if(nextM>12)
                {
                    nextM=1;
                    nextY++;
                }
            }
            if(d[i]==nextD && m[i]==nextM && y[i]==nextY)
            {
                cnt++;
                total+=(unit[i]-unit[i-1]);
            }
        }
        printf("%d %d\n", cnt, total);
    }
    return 0;
}
