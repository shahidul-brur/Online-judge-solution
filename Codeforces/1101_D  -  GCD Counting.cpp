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
const int LOGN = 20, N = 200000;
bool composite[maxn];
vi primeFactor[maxn];
int sp[maxn];
void sieve(){
    for (int i = 2; i<=N; i += 2)
        sp[i] = 2;
    for(int i=3;i<=N;i+=2) if(!composite[i]){
        sp[i]=i;
        if(i*1LL*i>N) continue;
        for(int j=i*i;j<=N;j+=2*i) if(!sp[j])
            sp[j] = i, composite[j]=1;
    }
}
int a[maxn], n;
bool vis[maxn];
vi g[maxn];
ii farthestNode(int u, int p, int d, int prime){
    vis[u] = 1;
    ii farthest = mp(d,u);
    for(int v:g[u]) if(v!=p && a[v]%prime==0){
        ii cur = farthestNode(v, u, d+1, prime);
        farthest = max(farthest, cur);
    }
    return farthest;
}

int cal(int u){
    int cur = 0;
    for(int pf:primeFactor[u]){
        ii farthest = farthestNode(u,0,1,pf);
        farthest = farthestNode(farthest.ss,0,1,pf);
        cur = max(cur, farthest.ff);
    }
    return cur;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        int n = a[i];
        while(n>1){
            int pf = sp[n];
            primeFactor[i].pb(pf);
            while(n % pf == 0) n/=pf;
        }
    }
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i])
            ans = max(ans, cal(i));
    }
    cout << ans;
    return 0;
}