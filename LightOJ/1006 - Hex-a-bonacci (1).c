//Accepted

#include<stdio.h>
int main()
{


    long long int caseno = 0, cases, sq[10010],a,b,c,d,e,f,n,i;
    scanf("%lld", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        sq[0]=a;
        sq[1]=b;
        sq[2]=c;
        sq[3]=d;
        sq[4]=e;
        sq[5]=f;
        for(i=6;i<=n;i++)
        {
            sq[i]=(sq[i-1]%10000007+sq[i-2]%10000007+sq[i-3]%10000007+sq[i-4]%10000007+sq[i-5]%10000007+sq[i-6]%10000007)%10000007;
        }
        printf("Case %lld: %lld\n", ++caseno, sq[n] % 10000007);
    }
    return 0;
}
