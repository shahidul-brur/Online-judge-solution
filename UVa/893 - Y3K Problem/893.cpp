#include <stdio.h>
#include <string.h>
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
    //freopen("893.txt", "r", stdin);
    int y, m, d, days, day[14], need, preD;
    day[1]=day[3]=day[5]=day[7]=day[8]=day[10]=day[12]=31;
    day[2]=28;
    day[4]=day[6]=day[9]=day[11]=30;
    while(scanf("%d %d %d %d",&days, &d, &m, &y)!=EOF)
    {
        if(days==0 && m==0 && d==0 && y==0)
            break;
        preD=d;

        while(days>0)
        {
            if(m==2 && isLeapyear(y)==1)
                need=29-preD;
            else
                need=day[m]-preD;

            if(days>need)
            {
                days-=need;
                preD=0;
                d=day[m];
                m++;
                if(m>12)
                {
                    m=m-12;
                    y++;
                }
            }
            else
            {
                d=preD+days;
                preD=d;
                days=0;
            }
        }
        printf("%d %d %d\n",d,m,y);
    }
    return 0;
}
