#include<stdio.h>
int main()
{
    long long int gcd(int i, int j);
    long long int t, g, l,a,b,i,j,max;
    scanf("%lld",&t);
    while(t--)
    {
        a=0;
        b=0;
        scanf("%lld %lld",&g,&l);
        if(g>l)
            max=g;
        else max=l;
        for(i=1;i<=max;i++)
        {
            for(j=i+1;j<=max;j++)
            {
                if(gcd(i,j)==g && i*j==l*g)
                {
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        if(a==0 && b==0)
            printf("-1\n");
        else printf("%lld %lld\n",a,b);
    }

}
long long int gcd(i, j)
{
    int min, k,gc;
    if(i<j) min=i;
    else min=j;
    for(k=min;k>=1;k--)
    {
        if(i%k==0 && j%k==0)
        {
            gc=k;
            break;
        }
    }
    return gc;
}
