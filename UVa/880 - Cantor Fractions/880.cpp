#include <stdio.h>
#define M 99999999
long long int cantorU[M+1], cantorD[M+1];
int main()
{
    freopen("880.txt", "r", stdin);
    long long int n, i, j, d=1, p=1;

    while(p<=M)
    {
        for(i=1, j=d;i<=d;i++, j--)
        {
            cantorU[p]=j;
            cantorD[p]=i;
            p++;
            if(p>M)
                break;
        }
        d++;
        for(i=d, j=1;j<=d;i--, j++)
        {
            cantorU[p]=j;
            cantorD[p]=i;
            p++;
            if(p>M)
                break;
        }
        d++;
    }
    while(scanf("%lld", &n)!=EOF)
    {
        printf("%lld/%lld\n", cantorU[n], cantorD[n]);
    }
    return 0;
}
