#include<stdio.h>
int main()
{
    int t, i, j, k, l, cp, sec, count=0, n, px[n], py[n], m[100], mc=1;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        for(j=0;j<=n;j++)
            {
                scanf("%d %d",&px[j], &py[j]);
            }
        for(k=0;k<=n;k++)
        {
            for(l=0;l<=n;l++)
            {
                m[mc]=(py[k]-py[l])/(px[k]-px[l]);
                mc++;
            }
        }
        for(cp=1;cp<mc;cp++)
        {
            for(sec=2;sec<mc;sec++)
            {
                if(m[cp]==m[sec])
                    count++;
            }

        }
        printf("Case %d: %d",i,count);
    }
    return 0;
}
