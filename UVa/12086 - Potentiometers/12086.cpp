#include <stdio.h>
#include <string.h>

int main()
{
    freopen("12086.txt", "r", stdin);
    int cas=1, n, i, j, x, y, sum, R[200002];
    char cmd[6];
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        for(i=1;i<=n;i++)
            scanf("%d", &R[i]);
        if(cas>1)
            printf("\n");
        printf("Case %d:\n", cas);
        while(scanf("%s", cmd)!=EOF)
        {
            if(cmd[0]=='E')
                break;
            scanf("%d %d", &x, &y);
            if(cmd[0]=='S')
                R[x]=y;
            else if(cmd[0]=='M')
            {
                sum=0;
                for(i=x;i<=y;i++)
                sum+=R[i];
                printf("%d\n", sum);
            }
        }
        cas++;
    }
    return 0;
}
