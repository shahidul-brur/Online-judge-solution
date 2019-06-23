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
    freopen("11947.txt", "r", stdin);
    int y, m, d, days, day[14], need, preD, t, cas,temp;
    day[1]=day[3]=day[5]=day[7]=day[8]=day[10]=day[12]=31;
    day[2]=28;
    day[4]=day[6]=day[9]=day[11]=30;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d", &temp);
        m=temp/1000000;
        y=temp%10000;
        d=(temp/10000)%100;
        preD=d;
        days=280;
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
        printf("%d %02d/%02d/%d ",cas,m,d,y);
        if((m==1 && d>=21)||(m==2 && d<=19))
            printf("aquarius\n");
        else if((m==2 && d>=20)||(m==3 && d<=20))
            printf("pisces\n");
        else if((m==3 && d>=21)||(m==4 && d<=20))
            printf("aries\n");
        else if((m==4 && d>=21)||(m==5 && d<=21))
            printf("taurus\n");
        else if((m==5 && d>=22)||(m==6 && d<=21))
            printf("gemini\n");
        else if((m==6 && d>=22)||(m==7 && d<=22))
            printf("cancer\n");
        else if((m==7 && d>=23)||(m==8 && d<=21))
            printf("leo\n");
        else if((m==8 && d>=22)||(m==9 && d<=23))
            printf("virgo\n");
        else if((m==9 && d>=24)||(m==10 && d<=23))
            printf("libra\n");
        else if((m==10 && d>=24)||(m==11 && d<=22))
            printf("scorpio\n");
        else if((m==11 && d>=23)||(m==12 && d<=22))
            printf("sagittarius\n");
        else if((m==12 && d>=23)||(m==1 && d<=20))
            printf("capricorn\n");
    }
    return 0;
}
