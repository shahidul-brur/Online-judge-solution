#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int a[100002], n;
int binarySearch(int from, int key)
{
    int mid, left=from, right=n-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(key==a[mid])
            return mid;
        else if(key>a[mid])
            left=mid+1;
        else right=mid-1;
    }
    return -1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int k, i, p, ans;
    unsigned long long v;
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            v=(unsigned long long)a[i]*k;

            if(v<=a[n-1])
            {
                p=binarySearch(i+1, v);
                if(p!=-1)
                {
                    a[p]=-1;
                }
            }
        }
    }
    ans=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}