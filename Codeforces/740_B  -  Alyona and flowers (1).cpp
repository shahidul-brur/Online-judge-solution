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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, k) for(int i=0;i<k;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 210
#define inf 1e9
ll f[105], sum[105], a[106], n, m, maxi;
vi seg;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r;
    while(cin>>n>>m)
    {
        a[0] = sum[0] = 0LL;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i] = sum[i-1] + a[i];
        }
        maxi = 0LL;
        for(int i=1;i<=m;i++)
        {
            cin>>l>>r;
            for(int j=l;j<=r;j++)
            {
                f[j]++;
            }
            ll sm = sum[r] - sum[l-1];
            seg.pb(sm);
            maxi = max(maxi, sm);
        }
        int sz = seg.size();
        
        ll sm = 0LL;
        for(int i=0;i<sz;i++)
        {
            if(seg[i]>0)
                sm+=seg[i];
        }
        maxi = max(maxi, sm);
        cout << maxi << "\n";
        seg.clear();
    }
    return 0;
}



