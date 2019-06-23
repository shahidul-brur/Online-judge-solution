//Accepted

#include <stdio.h>

int main()
{
    freopen("11945.txt", "r", stdin);
    int t, cas, part[10], i, j, a, b, rem, avgInt;
    double total, ac, avg;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        total=0.0;
        for(i=0;i<12;i++)
        {
            scanf("%lf", &ac);
            total+=ac;
        }
        avg=total/12.0;
        avgInt=(int)(total/12);
        avgInt=avgInt-(avgInt%1000);
        avg=avg-avgInt;

        i=0;
        while(avgInt>0)
        {
            if(avgInt%1000!=0)
                part[i++]=avgInt%1000;
            avgInt/=1000;
        }
        printf("%d $", cas);
        for(j=i-1;j>=0;j--)
        {
            printf("%d,",part[j]);
        }
        printf("%.2lf\n", avg);
    }
    return 0;
}
