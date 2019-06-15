#include <stdio.h>
#include <string.h>
#define MAXI(a, b) a>b ? a:b
int price[1002], weight[1002], capa, n, precal[1002][32];
int decide(int pos, int w)
{
    if(pos==n)
        return 0;
    if(precal[pos][w]!=-1)
        return precal[pos][w];
    int profit1, profit2;
    if(weight[pos]+w<=capa)
        profit1=price[pos]+decide(pos+1, w+weight[pos]);
    else profit1=0;
    profit2=decide(pos+1, w);
    precal[pos][w]=MAXI(profit1, profit2);
    return precal[pos][w];
}

int main()
{
    freopen("10130.txt", "r", stdin);
    int t, g, i, sum, j, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0;i<n;i++)
            scanf("%d %d", &price[i], &weight[i]);
        scanf("%d", &g);
        sum=0;
        for(i=0;i<g;i++)
        {
            for(j=0;j<n;j++)
                for(k=0;k<31;k++)
                    precal[j][k]=-1;
            scanf("%d", &capa);
            sum+=decide(0, 0);
        }
        printf("%d\n", sum);
    }
    return 0;
}
