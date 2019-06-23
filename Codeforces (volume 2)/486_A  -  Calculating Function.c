#include<stdio.h>
int main()
{
    long long int n, ans, odd, even;
    scanf("%lld",&n);
    even=(n/2)*(n/2+1);
    if(n%2==1)
        n++;
    n=n/2;
    odd=n*n;
    ans=even-odd;
    printf("%lld\n",ans);
    return 0;
}