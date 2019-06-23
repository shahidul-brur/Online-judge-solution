//Accepted
#include<stdio.h>
int main()
{
    //freopen("12032.txt", "r", stdin);
    long long int t,n,r[100010],c,i,max,k,dif;
    r[0]=0;
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        max=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&r[i]);
            dif=r[i]-r[i-1];
            if(dif>max)
                max=dif;
        }
        k=max;
        for(i=1;i<=n;i++)
        {
            dif=r[i]-r[i-1];
            if(dif>k)
            {
                max++;
                k=max;
                i=0;
            }
            else if(dif==k)
                k--;
        }
        printf("Case %lld: %lld\n",c,max);
    }
    return 0;
}
