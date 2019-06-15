#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int t,n,ans;
    scanf("%llu",&t);
    while(t-->0)
    {
        scanf("%llu",&n);
        ans=(sqrt(8*n+1)-1)/2;
        printf("%llu\n",ans);
    }
    return 0;
}
