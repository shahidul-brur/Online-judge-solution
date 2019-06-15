//Accepted

#include<stdio.h>
int main()
{
    long long int a,b,c,d,l,count,i;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l)&&(a!=0||b!=0||c!=0||d!=0||l!=0))
    {
        count=0;
        for(i=0;i<=l;i++)
        {
            if((a*i*i+b*i+c)%d==0)
                count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
