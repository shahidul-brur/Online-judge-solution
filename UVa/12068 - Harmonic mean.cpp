//Accepted

#include<stdio.h>
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{

    freopen("12068.txt", "r", stdin);
    unsigned long long t,n, num[20],i,j,lcm,c,sum,g;
    scanf("%llu",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%llu",&n);
        for(i=0;i<n;i++)
            scanf("%llu",&num[i]);
        if(n==1)
            printf("Case %llu: %llu/1\n",c,num[0]);
        else
        {
            lcm=(num[0]*num[1])/gcd(num[0],num[1]);
            for(i=2;i<n;i++)
            {
                lcm=(lcm*num[i])/gcd(lcm,num[i]);
            }
            sum=0;
            for(i=0;i<n;i++)
            {
                sum+=(lcm/num[i]);
            }
            n=n*lcm;
            g=gcd(n,sum);
            n=n/g;
            sum=sum/g;
            printf("Case %llu: %llu/%llu\n",c,n,sum);
        }

    }
    return 0;
}
