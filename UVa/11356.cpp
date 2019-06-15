//Accepted
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
    freopen("11356.txt", "r", stdin);
    int t, cas, y, m, d, i, j, days, day[14], len, need, preD;
    char month[15], M[14][15];
    day[4]=day[6]=day[9]=day[11]=30;
    day[2]=28;
    day[1]=day[3]=day[5]=day[7]=day[8]=day[10]=day[12]=31;
    strcpy(M[1], "January");
    strcpy(M[2], "February");
    strcpy(M[3], "March");
    strcpy(M[4], "April");
    strcpy(M[5], "May");
    strcpy(M[6], "June");
    strcpy(M[7], "July");
    strcpy(M[8], "August");
    strcpy(M[9], "September");
    strcpy(M[10], "October");
    strcpy(M[11], "November");
    strcpy(M[12], "December");

    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d-%s", &y, &month);
        scanf("%d",&days);
        len=strlen(month);
        d=0;
        for(i=0;month[i]!='-';i++);
        for(j=i+1;j<len;j++)
            d=d*10+month[j]-'0';
        month[i]='\0';
        for(i=1;i<=12;i++)
            if(strcmp(M[i], month)==0)
            {
                m=i;
                break;
            }
        preD=d;
        while(days>0)
        {
            if(m==2 and isLeapyear(y)==1)
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
        printf("Case %d: %d-%s-",cas,y,M[m]);
        if(d<10)
            printf("0");
        printf("%d\n",d);
    }
    return 0;
}
