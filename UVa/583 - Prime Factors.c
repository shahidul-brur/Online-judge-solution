//Accepted

#include<stdio.h>
int main()
{
    int n,i,j,f[1000],N,flag;
    while(scanf("%d",&n) && n!=0)
    {
        flag=1;
        N=n;
        if(n<0)
            n=0-n;
        j=0;
        for(i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                flag=0;
                j++;
                f[j]=i;
                n=n/i;
                i=1;
            }
        }
        printf("%d =",N);
        if(N<0)
            printf(" -1 x");
        if(j>0)
            printf(" %d",f[1]);
        for(i=2;i<=j;i++)
            printf(" x %d",f[i]);
        if(flag==0)
            printf(" x");
        printf(" %d\n",n);
    }
    return 0;
}
