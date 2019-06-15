
/*Accepted*/

#include<stdio.h>
int main()
{
    //freopen("11799.txt", "r", stdin);
    int t, n, v[110],i,max=0,c;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
            if(v[i]>max)
                max=v[i];
        }
        printf("Case %d: %d\n",c,max);
        max=0;
    }
    return 0;
}
