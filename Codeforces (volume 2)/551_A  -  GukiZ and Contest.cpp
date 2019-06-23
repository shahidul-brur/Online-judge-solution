#include <bits/stdc++.h>
using namespace std;
int a[2002], b[2002];
int bs(int key, int f, int L)
{
    int mid, ans=-1;
    while(f<=L)
    {
        mid=(f+L)/2;
        if(key==a[mid])
        {
            ans=mid;
            f=mid+1;
        }
        else if(key<a[mid])
            L=mid-1;
        else if(key>a[mid]) f=mid+1;
    }
    return ans;
}
int main()
{
    //freopen("a.txt", "r", stdin);
    int n, i, j, cnt, ran[2002], p;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        b[i]=a[i];
    }
    sort(a, a+n);
    for(i=0;i<n;i++)
    {
        p=bs(b[i], 0, n);
        if(i>0)
            printf(" ");
        printf("%d", n-p);
    }
    printf("\n");
    return 0;
}