//Accepted
#include<stdio.h>
int main()
{
    freopen("11559.txt", "r", stdin);
    long long int n,b,h,w,i,j,k,p,a[25],cost,min;
    while(scanf("%lld %lld %lld %lld",&n,&b,&h,&w)!=EOF)
    {
        min=1000000;
        for(i=0;i<h;i++)
        {
            scanf("%lld",&p);
            cost=p*n;
            for(j=0;j<w;j++)
                scanf("%lld",&a[j]);
            for(k=0;k<w;k++)
            {
                if(a[k]>=n && cost<=b && cost<=min)
                {
                    min=cost;
                    break;
                }
            }
        }
        if(min==1000000)
            printf("stay home\n");
        else printf("%lld\n",min);
    }
    return 0;
}
