//Accepted

#include<stdio.h>
int main()
{
    long long int n,pr,em,i,j,k,rem,div,rev;
    while(scanf("%lld",&n)!=EOF)
    {
        pr=em=rev=0;
        for(i=2;i<=n/2;i++)
        {
         if(n%i==0)
         {
            pr=1;
            break;
         }
       }
       if(pr==1)
        printf("%lld is not prime.\n",n);
       else if(pr==0)
       {
           div=n;
            while(div!=0)
            {
                rem=div%10;
                rev=rev*10+rem;
                div/=10;
            }
            for(i=2;i<=rev/2;i++)
            {
                if(rev%i==0)
                {
                    em=1;
                    break;
                }
            }
            if(em==0 && rev!=n)
                printf("%lld is emirp.\n",n);
            else
                printf("%lld is prime.\n",n);
       }
    }
    return 0;
}
