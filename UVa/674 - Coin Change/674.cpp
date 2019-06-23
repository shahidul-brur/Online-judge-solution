#include <stdio.h>
#include <string.h>
int availableCents[]={1, 5, 10, 25, 50}, preCal[5][7492], v[5][7492];
int change(int pos, int am)
{
    if(pos>=5)
        return 0;
    if(v[pos][am]==1)
        return preCal[pos][am];

    int way1=0, way2=0;
    if(am==availableCents[pos])
        way1=1;
    else if(am>availableCents[pos])
        way1=change(pos, am-availableCents[pos]);
    if(am>=availableCents[pos]) way2=change(pos+1, am);
    v[pos][am]=1;
    preCal[pos][am]=way1+way2;
    return preCal[pos][am];
}
int main()
{
    int amount;
    memset(v, 0, sizeof(v));
    while(scanf("%d", &amount)!=EOF)
    {
        if(amount==0)
            printf("1\n");
        else
            printf("%d\n", change(0,amount));
    }
    return 0;
}
