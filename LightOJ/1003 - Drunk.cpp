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
const int maxn = (int)1e4+5;
const int LOGN = 20;
map<string, int> maap;
vi adj[maxn];
int vis[maxn];
bool cycle(int u, int p)
{
    vis[u] = 1;
    bool cyc = 0;
    int s = adj[u].size();
    f0(i,s)
    {
        int v=adj[u][i];
        if(v==p || vis[v]==1)
            cyc = 1;
        else if(!vis[v])
            cyc |=cycle(v, u);
    }
    vis[u] = 2;
    return cyc;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    f1(cas,t)
    {
        maap.clear();
        int m;
        scanf("%d", &m);
        char s[12];
        int cnt=0;
        f1(i,m)
        {
            scanf("%s", s);
            string w1=string(s);
            if(maap.find(w1)==maap.end())
                maap[w1]=++cnt;
            scanf("%s", s);
            string w2=string(s);
            if(maap.find(w2)==maap.end())
                maap[w2]=++cnt;
            adj[maap[w1]].pb(maap[w2]); // w1 before w2
        }
        bool yes = 1;
        
        f1(i,cnt) vis[i]=0;
        f1(i,cnt)
        {
            if(vis[i]) continue;
            if(cycle(i, i))
            {
                yes = 0;
                break;
            }
        }
        printf("Case %d: ", cas);
        if(yes)
            printf("Yes\n");
        else printf("No\n");
        f1(i,cnt) adj[i].clear();
    }
    return 0;
}

