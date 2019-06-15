//Accepted

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("11292.txt", "r", stdin);
    int k, d, i, j, cost, dragon[20005], knight[20005], kill;
    while(scanf("%d %d", &d, &k)!=EOF)
    {
        if(d==0 && k==0)
            break;
        for(i=0;i<d;i++)
            scanf("%d", &dragon[i]);
        for(i=0;i<k;i++)
            scanf("%d", &knight[i]);
        sort(dragon, dragon+d);
        sort(knight, knight+k);
        kill=cost=0;
        j=0;
        for(i=0;i<d;i++)
        {
            for(;j<k;j++)
            {
                if(knight[j]>=dragon[i])
                {
                    kill++;
                    cost+=knight[j];
                    j++;
                    break;
                }
            }
        }
        if(kill==d)
            printf("%d\n", cost);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}
