#include<stdio.h>
int main()
{
    freopen("10090.txt", "r", stdin);
    long long int n,c1,n1,c2,n2,m1,m2,rem;
    float r1,r2;
    while(scanf("%lld",&n) && n!=0)
    {
        scanf("%lld %lld",&c1,&n1);
        scanf("%lld %lld",&c2,&n2);

        if(n<n1 && n<n2)
            printf("failed\n");
       else
       {
        r1=(float)c1/n1;
        r2=(float)c2/n2;
        if(r1<r2)
        {
            m1=n/n1;
            rem=n-m1*n1;
            while(rem%n2!=0)
            {
                m1--;
                rem+=n1;
                if(m1==0)
                    break;
            }
            m2=rem/n2;
        }
        else
        {
          m2=n/n2;
            rem=n-m2*n2;
            while(rem%n1!=0)
            {
                m2--;
                rem+=n2;
                if(m2==0)
                    break;
            }
            m1=rem/n1;
        }
        if(m1*n1+m2*n2==n)
            printf("%lld %lld\n",m1,m2);
        else printf("failed\n");
       }
    }
    return 0;
}
