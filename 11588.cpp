#include <stdio.h>
int main()
{
    freopen("11588.txt", "r", stdin);
    int t, cas, R, C, M, N, i, j, maxi, v[27], p, sum;
    char grid[25][25];
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d%d",&R,&C,&M,&N);
        for(i=0;i<R;i++)
            scanf("%s",&grid[i]);
        for(i=0;i<26;i++)
            v[i]=0;
        maxi=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                p=grid[i][j]-'A';
                v[p]++;
                if(v[p]>maxi)
                    maxi=v[p];
            }
        }
        sum=0;
        for(i=0;i<26;i++)
        {
            if(v[i]==maxi)
                sum+=(v[i]*M);
            else
                sum+=(v[i]*N);
        }
        printf("Case %d: %d\n",cas, sum);
    }
    return 0;
}
