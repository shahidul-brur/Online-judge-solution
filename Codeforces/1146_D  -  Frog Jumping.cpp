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
const int maxn = (int)1e6+5;
const int LOGN = 20;
bool vis[maxn];
ll a,b,n;
ll cnt[maxn];
int last,mxx, m;

void add(int pos, int val) { // go up
    while(pos<=last){
        cnt[pos]+=val;
        pos +=(pos & -pos);
    }
}

ll query(int pos){ // go down
    ll ret = 0;
    while(pos>0){
        ret+=cnt[pos];
        pos -=(pos&-pos);
    }
    return ret;
}
void dfs(int u)
{
    if(u<=0 || u>mxx || vis[u]) return;
    //cout << u << ", ";
    add(u,+1);
    vis[u]=1;
    dfs(u+a);
    dfs(u-b);
}
ll solve(ll mx)
{
    ll up = ((b+a-1)/a)*1LL*a;
    if(up>mx) n = a;
    else n = __gcd(a,b);
    ll d = mx/n;
    ll to = d*n;
    ll t=(mx-to+1)*1LL*(d+1);
    t+=(d*1LL*(d+1)/2)*n;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int m,a,b;
    cin>>m>>a>>b;
    last = min(1000000,m);
    //cout << last << ": ";
    vis[0]=1;
    ll t = 1LL;
    f1(i,last)
    {
        mxx=i;
        if(i>=a && vis[i-a] && !vis[i]){
//            cout << i << ":\n=====\n";
            dfs(i);
//            cout << "\n";
        }
        //cout << i << "\n";
        ll cur = query(i);
        t+=cur+1;
//        cout << i << " = " << query(i)+1 << "\n";
    }
    if(m<=last){
        cout << t;
        return 0;
    }
//    ll up = ((b+a-1)/a)*a;
//    if(up>m) n = a;
//    else n = __gcd(a,b);
//    
//    ll pd = last/n;
//    ll d = m/n;
//    ll to = d*n;
//    //cout << d << " " << t << "\n";
//    t+=(m-to+1)*1LL*(d+1);
//    t+=(d*1LL*(d+1)/2)*n;
    t+=solve(m) - solve(last);
    cout << t;
    return 0;
}
