//Accepted

#include <stdio.h>
#include <string.h>
int isLeap(int year)
{
    if(year%400==0)
        return 1;
    if(year%100==0)
        return 0;
    if(year%4==0)
        return 1;
    return 0;
}
int main()
{
    freopen("12439.txt", "r", stdin);
    int t, cas, y1, d1, y2, d2, i=1, cnt, m1, m2, from, to, Yes;
    char mn1[15], mn2[15], mnth[13][15];
    strcpy(mnth[i++], "January");
    strcpy(mnth[i++], "February");
    strcpy(mnth[i++], "March");
    strcpy(mnth[i++], "April");
    strcpy(mnth[i++], "May");
    strcpy(mnth[i++], "June");
    strcpy(mnth[i++], "July");
    strcpy(mnth[i++], "August");
    strcpy(mnth[i++], "September");
    strcpy(mnth[i++], "October");
    strcpy(mnth[i++], "November");
    strcpy(mnth[i++], "December");
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s %d, %d", mn1, &d1, &y1);
        scanf("%s %d, %d", mn2, &d2, &y2);
        for(i=1;i<=12;i++)
        {
            if(strcmp(mn1, mnth[i])==0)
                m1=i;
            if(strcmp(mn2, mnth[i])==0)
                m2=i;
        }
        cnt=0;
        if(y1==y2 && isLeap(y1)==1)
        {
            if(m1>2 || m2<2);
            else if(m2==2 && d2<29);
            else if(m1<=2 && m2>2)
                cnt++;
            else if(m1<=2 && m2==2 && d2==29)
                cnt++;
        }
        else
        {
            if(isLeap(y1)==1 && m1<=2)
                cnt++;
            if(isLeap(y2)==1 && (m2>2 || (m2==2 && d2==29)))
                cnt++;

            from=to=0;
            for(i=y1+1;i<y2;i++)
            {
                if(i%4==0)
                {
                    from=i;
                    break;
                }
            }
            if(from!=0)
                for(i=y2-1;i>=from;i--)
                {
                    if(i%4==0)
                    {
                        to=i;
                        break;
                    }
                }
            if(from!=0)
                cnt=cnt+(to-from)/4+1;
            for(i=from, from=0;i<y2;i++)
            {
                if(i%100==0)
                {
                    from=i;
                    break;
                }
            }
            if(from!=0)
                for(i=to, to=0;i>=from;i--)
                {
                    if(i%100==0)
                    {
                        to=i;
                        break;
                    }
                }
            if(from!=0)
            {
                cnt=cnt-(to-from)/100-1;
            }
            for(i=from, from=0;i<y2;i++)
            {
                if(i%400==0)
                {
                    from=i;
                    break;
                }
            }
            if(from!=0)
                for(i=to, to=0;i>=from;i--)
                {
                    if(i%400==0)
                    {
                        to=i;
                        break;
                    }
                }
            if(from!=0)
            {
                cnt=cnt+(to-from)/400+1;
            }
        }
        printf("Case %d: %d\n", cas, cnt);
    }

    return 0;
}
