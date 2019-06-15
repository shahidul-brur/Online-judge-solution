//Accepted
#include<stdio.h>
int main()
{
    //freopen("10489.txt", "r", stdin);
    long long int t,n,b,chc,k,i,j,m,g;
    scanf("%lld",&t);
    while(t--)
    {
        chc=0;
        scanf("%lld %lld",&n,&b);
        while(b--)
        {
            scanf("%lld",&k);
            g=1;
            while(k--)
            {
                scanf("%lld",&m);
                g=g%n*m%n;
            }
            chc=chc%n + g%n;
        }
        printf("%lld\n",chc%n);
    }
    return 0;
}
