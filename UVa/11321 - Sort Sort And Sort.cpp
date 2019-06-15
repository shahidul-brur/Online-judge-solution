//Accepted

#include <bits/stdc++.h>
using namespace std;
int M;
int cmp(int a, int b)
{
    int m1, m2, s=0;
    m1=a%M;
    m2=b%M;
   if(m1>m2)
     return 1;

    else if(m1==m2)
    {
        if(a%2==0 && b%2!=0)
        {
            s=1;
        }
        else if(a%2==0 && b%2==0)
        {
            if(a>b)
                s=1;
        }
        else if(a%2!=0 && b%2!=0)
        {
            if(a<b)
                s = 1;
        }
    }
    return s;
}
int main()
{
    freopen("11321.txt", "r", stdin);
    int n, n1, i, a[10002], temp,j;
    while(scanf("%d %d", &n, &M)!=EOF)
    {
        if(n==0 && M==0)
        {
            printf("%d %d\n", n, M);
            break;
        }
        for(i=0;i<n;i++)
            scanf("%d", &a[i]);

        sort(a, a+n, cmp);

        printf("%d %d\n", n, M);
        for(i=n-1;i>=0;i--)
            printf("%d\n", a[i]);
    }
    return 0;
}
