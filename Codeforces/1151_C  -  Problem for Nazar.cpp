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
ll p2(ll a, ll p)
{
    if(p==0) return 1LL;
    ll ret = p2(a,p/2);
    ret = (ret*ret) % MOD;
    if(p%2==1) ret = (ret*1LL*a) % MOD;
    return ret;
}
ll cal(ll t)
{
    t<<=1LL;
    ll ret = (1LL<<t)-1;
    ret/=3LL;
    return ret;
}
ll solve(ll n)
{
    if(n==0)
        return 0LL;
    if(n==1) 
        return 1LL;
    ll po,pe,p=0LL;
    while((1LL<<(p+1))-1<=n) p++;
    ll rem = n-((1LL<<p)-1);
    pe = p/2;
    po= p-pe;
    ll pot = cal(po);
    if(p%2==0) pot = pot+rem;
    ll pet = n-pot;
    pet%=MOD;
    pot%=MOD;
    //cout << p << ": " << pot << " " << pet << "\n";
    ll odd = (pot*pot)%MOD;
    ll even = (pet*(pet+1))%MOD;
    return (odd+even)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll l, r, odd=0LL, even=0LL;
    cin>>l>>r;
    ll res = solve(r);
    //cout << res << " -> ";
    res -= solve(l-1);
    if(res<0) res+=MOD;
    cout << res;
    return 0;
}
