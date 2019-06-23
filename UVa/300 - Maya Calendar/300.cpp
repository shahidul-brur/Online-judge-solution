//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("300.txt", "r", stdin);
    int n, c, y, d, days, year, num, ch, i, j, day, m;
    char month[15];
    scanf("%d", &n);
    printf("%d\n",n);
    for(c=1;c<=n;c++)
    {
        scanf("%d. %s %d", &d, month, &y);

        if(strcmp(month, "pop")==0)
            m=1;
        else if(strcmp(month, "no")==0)
            m=2;
        else if(strcmp(month, "zip")==0)
            m=3;
        else if(strcmp(month, "zotz")==0)
            m=4;
        else if(strcmp(month, "tzec")==0)
            m=5;
        else if(strcmp(month, "xul")==0)
            m=6;
        else if(strcmp(month, "yoxkin")==0)
            m=7;
        else if(strcmp(month, "mol")==0)
            m=8;
        else if(strcmp(month, "chen")==0)
            m=9;
        else if(strcmp(month, "yax")==0)
            m=10;
        else if(strcmp(month, "zac")==0)
            m=11;
        else if(strcmp(month, "ceh")==0)
            m=12;
        else if(strcmp(month, "mac")==0)
            m=13;
        else if(strcmp(month, "kankin")==0)
            m=14;
        else if(strcmp(month, "muan")==0)
            m=15;
        else if(strcmp(month, "pax")==0)
            m=16;
        else if(strcmp(month, "koyab")==0)
            m=17;
        else if(strcmp(month, "cumhu")==0)
            m=18;
        else if(strcmp(month, "uayet")==0)
            m=19;
        m--;
        days=365*y+m*20+d+1;
        year=days/260;
        day=days%260;
        for(ch=0, num=0, i=1;i<=day;i++, ch++, num++)
        {
            if(num==13)
                num=0;
            if(ch==20)
                ch=0;
        }
        if(num==0)
        {
            num=13;
            year--;
        }
        printf("%d ", num);
        if(ch==1)
            printf("imix ");
        else if(ch==2)
            printf("ik ");
        else if(ch==3)
            printf("akbal ");
        else if(ch==4)
            printf("kan ");
        else if(ch==5)
            printf("chicchan ");
        else if(ch==6)
            printf("cimi ");
        else if(ch==7)
            printf("manik ");
        else if(ch==8)
            printf("lamat ");
        else if(ch==9)
            printf("muluk ");
        else if(ch==10)
            printf("ok ");
        else if(ch==11)
            printf("chuen ");
        else if(ch==12)
            printf("eb ");
        else if(ch==13)
            printf("ben ");
        else if(ch==14)
            printf("ix ");
        else if(ch==15)
            printf("mem ");
        else if(ch==16)
            printf("cib ");
        else if(ch==17)
            printf("caban ");
        else if(ch==18)
            printf("eznab ");
        else if(ch==19)
            printf("canac ");
        else if(ch==20 || ch==0)
            printf("ahau ");

        printf("%d\n", year);
    }
    return 0;
}
