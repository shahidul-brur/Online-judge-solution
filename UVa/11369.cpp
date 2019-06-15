//Accepted

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("11369.txt", "r", stdin);
    int t, n, i, j, k, price[20005], total, tmp;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d", &price[j]);
        sort(price, price+n);
        total=0;
        for(j=n-3;j>=0;j-=3)
            total+=price[j];
        printf("%d\n",total);
    }
    return 0;
}
