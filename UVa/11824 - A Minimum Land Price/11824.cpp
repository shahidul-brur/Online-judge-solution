//Accepted
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define eps 1e-8
int main()
{
    freopen("11824.txt", "r", stdin);
    long int t, i, sum, p, j, n, k, price[500];
    scanf("%ld", &t);
    while(t--)
    {
        i=0;
        while(scanf("%ld",&p)!=EOF)
        {
            if(p==0)
                break;
            price[i++]=p;
        }
        n=i;
        sum=0;
        sort(price, price+n);
        for(i=n-1, j=1;i>=0;i--)
        {
            sum+=2*pow(price[i], j) + eps;
            j++;
            if(sum>5000000)
                break;
        }
        if(sum>5000000)
            printf("Too expensive\n");
        else
            printf("%ld\n",sum);
    }
    return 0;
}
