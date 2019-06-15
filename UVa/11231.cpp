#include <stdio.h>
int main()
{
    freopen("11231.txt", "r", stdin);
    long int n, m, c, row, col, total, rSum, cSum;
    while(scanf("%ld %ld %ld", &n,&m,&c)!=EOF)
    {
        if(n==0 && m==0 && c==0)
            break;

        if(n%2==0)
        {
            if(c==1)
                row=(n-6)/2;
            else
                row=(n-8)/2;
        }
        else if(n%2==1)
            row=(n-7)/2;


        if(m%2==0)
        {
            if(c==1)
                col=(m-8)/2;
            else
                col=(m-7)/2;
        }
        else
        {
            if(c==1)
                col=(m-9)/2;
            else
                col=(m-7)/2;
        }
        rSum=(m-7)*(m-7);
        cSum=(n-7)*(n-7);
        total=rSum+cSum;
        printf("%ld\n",total);
    }
    return 0;
}
