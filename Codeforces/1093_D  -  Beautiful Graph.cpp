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
const int MOD = 998244353;
const int maxn = (int)3e5+5;
const int LOGN = 20;
vi g[maxn];
int odd, tot;
int col[maxn];
bool vis[maxn];
bool ok;
void dfs(int u, int c){
    vis[u] = 1;
    col[u] = c;
    odd+=c%2;
    ++tot;
    for(int v:g[u]){
        if(vis[v] == 1){
            if(col[v]==col[u]){
                ok=0;
                return ;
            }
        }
        else{
            dfs(v, 1-c);
        }
    }
}
ll p2[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    p2[0] = 1LL;
    f1(i,300001) p2[i] = (p2[i-1] * 2LL)%MOD;
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        f1(i,m){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        f1(i,n) vis[i] = 0;
        ll ans = 1;
        f1(i,n) if(vis[i]==0){
            ok=1;
            odd=0;
            tot = 0;
            dfs(i,0);
            if(ok){
                ans *=(p2[odd] + p2[tot-odd])%MOD;
                ans %=MOD;
            }
            else{
                ans = 0LL;
                break;
            }
        }
        cout << ans << "\n";
        f1(i,n) g[i].clear();
    }
    return 0;
}
