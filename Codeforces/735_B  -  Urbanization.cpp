/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, k) for(int i=0;i<k;i++)
#define ll long long

ll sum1, sum2, a[100009];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, n1, n2, small, big;
    scanf("%d %d %d", &n, &n1, &n2);
    
    if(n2<n1)
    {
        small = n2;
        big = n1;
    }
    else
    {
        small = n1;
        big = n2;
    }
        for(int i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        sort(a, a+n);
        
        sum1 = sum2 = 0LL;
        int i, j;
        for(i=n-1, j=1;j<=small;j++, i--)
        {
            sum1+=a[i];
        }
        for(j=1;j<=big;j++, i--)
        {
            sum2+=a[i];
        }
        double a1 = (double)sum1/small;
        double a2 = (double)sum2/big;
        
        printf("%lf\n", a1+a2);
    return 0;
}

