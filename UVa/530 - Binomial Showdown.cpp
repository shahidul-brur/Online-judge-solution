//Accepted

#include<stdio.h>
long gcd(long a, long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
void divBygcd(long &a,long &b)
{
    long g=gcd(a,b);
    a/=g;
    b/=g;
}
long C(long n, long k)
{
    long nm=1, dn=1,i,mul,div;
    if(k>n/2)
        k=n-k;
    for(i=k;i>0;i--)
    {
        mul=n-k+i;
        div=i;
        divBygcd(mul,div);
        divBygcd(mul,dn);
        divBygcd(nm,div);
        dn*=div;
        nm*=mul;
    }
    return nm/dn;
}
int main()
{
    freopen("530.txt", "r", stdin);
    long n,k,ans;
    while(scanf("%ld %ld",&n,&k)==2)
    {
        if(n==0 && k==0)
            break;
        if(k==1)
            ans=n;
        else if(k==n)
            ans=1;
        else
            ans=C(n,k);
        printf("%ld\n",ans);
    }
    return 0;
}
