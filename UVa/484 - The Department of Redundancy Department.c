//Accepted

#include<stdio.h>
#define MAX 100000
int main()
{
    freopen("484.txt", "r", stdin);
    long long int list[MAX],f[MAX],i=0,n,j,found;
    while(scanf("%lld",&n)!=EOF)
    {
        found=0;
        for(j=0;j<i;j++)
        {
            if(list[j]==n)
            {
                f[j]++;
                found=1;
                break;
            }
        }
        if(found==0)
        {
            list[i]=n;
            f[i]=1;
            i++;
        }
    }
    for(j=0;j<i;j++)
    {
        printf("%lld %lld\n",list[j],f[j]);
    }
    return 0;
}
