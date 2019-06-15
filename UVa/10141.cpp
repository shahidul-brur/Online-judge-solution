#include <stdio.h>
#include <string.h>
#define eps 1e-6
struct req
{
    int met;
    double price;
    char name[85];
}prop[10000];

int main()
{
    freopen("10141.txt", "r", stdin);
    int n, i, j, cas=1, maxi, p, tm, ans;
    double tmp;
    char temp[85];
    while(scanf("%d %d", &n, &p)!=EOF)
    {
        if(n==0 && p==0)
            break;
        getchar();
        for(i=1;i<=n;i++)
        {
            gets(temp);
        }

        for(i=0;i<p;i++)
        {
            gets(prop[i].name);
            scanf("%lf %d", &prop[i].price, &prop[i].met);
            getchar();
            for(j=1;j<=prop[i].met;j++)
            {
                gets(temp);
            }
        }

        for(i=0;i<p;i++)
        {
            for(j=0;j<p-1;j++)
            {
                if(prop[j].price > prop[j+1].price+eps)
                {
                    tm=prop[j].met;
                    prop[j].met=prop[j+1].met;
                    prop[j+1].met=tm;

                    tmp=prop[j].price;
                    prop[j].price=prop[j+1].price;
                    prop[j+1].price=tmp;

                    strcpy(temp, prop[j].name);
                    strcpy(prop[j].name, prop[j+1].name);
                    strcpy(prop[j+1].name, temp);
                }
            }
        }

        maxi=prop[0].met;
        ans=0;
        for(i=1;i<p;i++)
        {
            if(prop[i].met > maxi)
            {
                ans=i;
                maxi=prop[i].met;
            }
        }
        if(cas>1)
            printf("\n");
        printf("RFP #%d\n", cas);
        printf("%s\n", prop[ans].name);
        cas++;

    }
    return 0;
}
