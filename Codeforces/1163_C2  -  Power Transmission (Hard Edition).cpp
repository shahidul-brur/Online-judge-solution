/*==============================================*\
ID:          shahidul_brur

Name:     Md. Shahidul Islam
Study:      CSE, BRUR
Address:  Rangpur, Bangladesh

 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English)
\*===============================================*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
ll x[maxn], y[maxn];
map<pair<ll, ll> , ll> mm;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    
    set<pair<pair<ll, ll>, ll> > line;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll a = y[i]-y[j];
            ll b = x[j]-x[i];
            ll c = (y[j]-y[i])*x[i] + (x[i]-x[j])*y[i];
            ll g = __gcd(abs(a), abs(b));
            g = __gcd(g, abs(c));
            a/=g;
            b/=g;
            c/=g;
            if(a<0)
            {
                a*=-1;
                b*=-1;
                c*=-1;
            }
            if(a==0 && b<0){
                b*=-1;
                c*=-1;
            }
            line.insert(mp(mp(a,b),c));
        }
    }
    vector<pair<pair<ll, ll>, ll> > v;
    for(auto x:line) {
        v.pb(x);
        mm[x.ff]++;
    }
    int s = v.size();
    ll cnt = 0LL, bad = 0LL;
    for(int i=0;i<s;i++){
        ll a1 = v[i].ff.ff;
        ll b1 = v[i].ff.ss;
        ll c1 = v[i].ss;
        ll t = mm[mp(a1,b1)];
        cnt+=s-t;
    }
    cout << cnt/2;
    return 0;
}
