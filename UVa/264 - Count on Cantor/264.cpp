//Accepted

#include <stdio.h>
#define M 10000000
int cantorU[M+1], cantorD[M+1];
int main()
{
    //freopen("264.txt", "r", stdin);
    int n, i, j, d=1, p=1;

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
    while(scanf("%d", &n)!=EOF)
    {
        printf("TERM %d IS %d/%d\n", n, cantorU[n], cantorD[n]);
    }
    return 0;
}
