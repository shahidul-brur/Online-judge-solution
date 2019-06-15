//Accepted

#include<stdio.h>
int GCD(int a, int b)
{
    int min,max,gcd,k,tmp;
    if(a<b)
    {
        min=a;
        max=b;
    }
    else
    {
        min=b;
        max=a;
    }
    while(max%min!=0)
    {
        tmp=max;
        max=min;
        min=tmp%min;
    }
    gcd=min;
    return gcd;
}
int main()
{
    int n,i,j,G;
    while(scanf("%d",&n) && n!=0)
    {
        G=0;
        for(i=1;i<n;i++)
          for(j=i+1;j<=n;j++)
            {

                G+=GCD(i,j);
            }
        printf("%d\n",G);
    }
    return 0;
}
