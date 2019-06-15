#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[105][105];
ll matrix[105][105];

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++)
    {
        int N, M, money;
        scanf("%d %d %d", &N, &M, &money);
        
        sum[0][0] = 0LL;
        for(int i=1;i<=N;i++)
        {
            ll col_sum = 0LL;
            for(int j=1;j<=M;j++)
            {
                scanf("%lld", &matrix[i][j]);
                col_sum+=matrix[i][j];
                sum[i][j] = sum[i-1][j] + col_sum;
            }
        }
        
        int maxi=0;
        ll cost=0LL;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int k=i;k<=N;k++)
                {
                    for(int l=j;l<=N;l++)
                    {
                        ll price = sum[i+k-1][j+l-1]
                         - sum[i-1][j+l-1] - sum[i+k-1][j-1] + sum[i-1][j-1];
                        if(price>money || k*l<maxi)
                            continue;
                        if(k*l>maxi)
                            maxi = k*l, cost = price;
                        else if(k*l==maxi)
                            cost = min(cost, price);
                    }
                }
            }
        }
        printf("Case #%d: %d %lld\n", cas, maxi, cost);
    }
    return 0;
}
