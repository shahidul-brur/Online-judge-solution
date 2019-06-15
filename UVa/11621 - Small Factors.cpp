//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    long long int L[99999],i,j,k=0,v,n;
    for(i=0;i<=31;i++)
    {
        for(j=0;j<=19;j++)
        {
            v=pow(2,i)*pow(3,j);
            if(v>2147483648)
                break;
            L[k++]=pow(2,i)*pow(3,j);
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-1;j++)
        {
            if(L[j]>L[j+1])
            {
                v=L[j];
                L[j]=L[j+1];
                L[j+1]=v;
            }
        }
    }
    while(scanf("%lld",&n)&&n!=0)
    {
        for(i=0;i<k;i++)
        {
            if(L[i]>=n)
            {
                printf("%lld\n",L[i]);
                break;
            }
        }
    }
    return 0;
}
