#include<stdio.h>
int main()
{
    int n, k, i, st, mem=0,ans;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&st);
            if(st<(6-k))
            mem++;
        }
    ans=mem/3;
    printf("%d\n",ans);
    mem=0;
    ans=0;
    }
    return 0;
}