//Accepted

#include <stdio.h>

int main()
{
    freopen("11958.txt", "r", stdin);
    int t, cas, bus, cH, cM, aH, aM, duration, i, mini, time;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d %d:%d", &bus, &cH, &cM);
        cM+=(cH*60);
        scanf("%d:%d %d", &aH, &aM, &duration);
        aM+=(aH*60);
        if(aM<cM)
            aM=aM+1440;
        mini=aM-cM+duration;
        for(i=2;i<=bus;i++)
        {
            scanf("%d:%d %d", &aH, &aM, &duration);
            aM+=(aH*60);
            if(aM<cM)
                aM+=1440;
            time=aM-cM+duration;
            if(time<mini)
                mini=time;
        }
        printf("Case %d: %d\n", cas, mini);
    }
    return 0;
}
