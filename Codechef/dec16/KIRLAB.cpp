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
#define N               10000005
#define inf             1e9
vi  primDiv[N];
bool prime[N];
ll par[N], root[100005];
void sieve()
{
    ll n = 10000000;
    for(ll i=2;i<=n;i+=2)
        primDiv[i].pb(2);
    for(ll i=3;i<=n;i+=2)
    {
        if(prime[i]==0)
        {
            //cout << i << "\n";
            primDiv[i].pb(i);
            for(ll j=i*i;j<=n;j+=2*i)
            {
                prime[j]=1;
                primDiv[j].pb(i);
            }
        }
    }
}
void makeUnion(ll x, ll y)
{
    ll a = root[x];
    ll b = root[y];
    if(a<b)
        root[x] = b;
    else root[y] = a;
}
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, cas,n, a;
    sieve();
    cin>>t;
    rep(cas, t)
    {
        cin>>n;
        mem(par, 0);
        rep1(i, n)
        {
            cin>>a;
            root[i] = i;
            int s = primDiv[a].sz;
            rep(j, s)
            {
                int p = primDiv[a][j];
                if(par[p]!=0)
                    makeUnion(root[i], par[p]);
                par[p] = root[i];
            }
        }
        int cnt = 0;
        rep1(i, n)
            if(root[i]==i)
                cnt++;
        cout << cnt << "\n";
        
    }
    return 0;
}

