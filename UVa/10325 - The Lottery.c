#include<stdio.h>
int main()
{
    long long int n,m,num[20],i,j,k,count,tk[21474836];
    for(i=1;i<=2147483647;i++)
            tk[i]=i;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        for(i=1;i<=m;i++)
         scanf("%lld",&num[i]);
         for(i=1;i<=n;i++)
            tk[i]=i;
         count++;
         for(i=1;i<=m;i++)
         {
             if(num[i]!=1)
                for(j=2;j<=n;j++)
                {
                    if(tk[j]!=0 && tk[j]%num[i]==0)
                    {
                        count++;
                        tk[j]=0;
                    }
                }
         }
         printf("%lld\n",n-count);
    }
    return 0;
}
