#include <stdio.h>
#include <string.h>
int main()
{
    freopen("10050.txt", "r", stdin);
    int t, n, h, p, day[3655], lost, i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(day, 0, sizeof(day));
        scanf("%d", &p);
        for(j=1;j<=p;j++)
        {

            scanf("%d", &h);
            for(i=h;i<=n;i+=h)
            {
                day[i]=1;
            }
        }
        lost=0;
        for(i=1;i<=n;i++)
        {
            if((i+1)%7!=0 && i%7!=0)
            {
                if(day[i]==1)
                    lost++;
            }
        }
        printf("%d\n", lost);
    }
    return 0;
}
