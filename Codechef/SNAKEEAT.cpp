/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MX = 100005;
int a[MX], n;
ll sum[MX];

int cal(int x, int last)
{
    if(last==0)
        return 0;
    int diff = a[n-1] - x;
    int l = 0, r = last;
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(mid==0)
        {
            l = mid+1;
            continue;
        }
        
        ll need = (sum[last] - sum[mid-1]) - 1LL*diff*(last - mid + 1);
        if(mid>=need)
        {
            ans = last-mid+1;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, q, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i = 0; i< n; i++)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        sum[0] = 1LL*a[n-1] - a[0];
        for(int i = 1; i< n; i++)
            sum[i] = 1LL*sum[i-1] + 1LL*(a[n-1] - a[i]);
        
        while(q--)
        {
            cin>>x;
            int cnt = 0;
            int idx = lower_bound(a, a+n, x) - a;
            cnt=(n-idx);
            cnt+=cal(x, idx-1);
            cout << cnt << "\n";
        }
    }
    return 0;
}
