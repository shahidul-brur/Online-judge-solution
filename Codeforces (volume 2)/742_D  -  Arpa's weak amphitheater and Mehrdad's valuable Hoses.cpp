/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1005
#define inf             1e9
int root[N];
ll bsum[N], wsum[N], wt[N], b[N], mw, dp[N][N];
vi group, memb[N];
int n, m, s;
int findRoot(int x)
{
    if(root[x]==x)
        return x;
    return root[x] = findRoot(root[x]);
}
void make(int x, int y)
{
    int rx = findRoot(x);
    int ry = findRoot(y);
    if(rx<ry)
    {
        root[rx] = root[ry] = rx;
        bsum[rx]+=bsum[ry];
        wsum[rx]+=wsum[ry];
    }
    else if(rx>ry)
    {
        root[rx] = root[ry] = ry;
        bsum[ry]+=bsum[rx];
        wsum[ry]+=wsum[rx];
    }
}
ll cnt(int pp, ll wgt)
{
    if(pp>=s)
        return 0LL;
    if(dp[pp][wgt]!=-1)
        return dp[pp][wgt];
    int p = group[pp]; // p is group leader of p'th group
    ll  mx;
    mx = 0LL;
    int siz = memb[p].size();
    if(wgt+wsum[p]<=mw)
        mx = max(mx, bsum[p] + cnt(pp + 1, wgt + wsum[p])); // try to invite whole group
    rep(i, siz)
    {
        int per = memb[p][i];
        if(wgt+wt[per]<=mw) // try to invite each member of group
        {
            mx = max(mx, b[per] + cnt(pp + 1,wgt + wt[per]));
        }
    }
    mx = max(mx, cnt(pp+1, wgt)); // don't invite anyone in this group
    return dp[pp][wgt] = mx;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y;
    cin>>n>>m>>mw;
    mem(dp, -1);
    rep1(i, n)
    {
        cin>>wt[i];
        wsum[i] = wt[i];
        root[i] = i;
    }
    rep1(i, n)
    {
        cin>>bsum[i];
        b[i] = bsum[i];
    }
    rep1(i, m)
    {
        cin>>x>>y;
        make(x, y);
    }
    
    rep1(i, n)
    {
        root[i] = findRoot(i);
    }

    rep1(i, n)
    {
        if(root[i]==i)
        {
            group.pb(i); // who are group leader
        }
        memb[root[i]].pb(i); // push each member to the leader's group
    }
    
    s = group.size(); // how many groups
    ll ans = cnt(0, 0); 
    cout << ans << "\n";
    return 0;
}

