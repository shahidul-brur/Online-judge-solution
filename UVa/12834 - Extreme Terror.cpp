#include<stdio.h>
long long exp[1000000],gave[1000000];
int main()
{
    freopen("12834.txt", "r", stdin);
    long long int t,n,k,c,i,j,tExp,tGave,sub,temp,den;
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lld %lld",&n,&k);
        tExp=tGave=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&exp[i]);
            tExp+=exp[i];
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&gave[i]);
            tGave+=gave[i];
        }
        sub=tGave-tExp;
        if(sub>0)
            printf("Case %lld: %lld\n",c,sub);
        else if(sub==0)
            printf("Case %lld: No Profit\n",c);
        else if(sub<0)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<n;j++)
                {
                    if(exp[j]<exp[j+1])
                    {
                        temp=exp[j];
                        exp[j]=exp[j+1];
                        exp[j+1]=temp;
                    }
                }
            }
            den=0;
            for(i=1;i<=k;i++)
                den+=exp[i];

            sub+=den;
            if(sub>0)
                printf("Case %lld: %lld\n",c,sub);
            else if(sub<=0)
                printf("Case %lld: No Profit\n",c);
        }
    }
    return 0;
}
