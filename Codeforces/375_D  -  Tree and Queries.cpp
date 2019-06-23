/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MX  = 100000;
const int INF = 2147483647;
int color[MX+5];
int siz[MX+5];
vi g[MX+5];
vector<pair<int, int> > queries[MX+5];
int freq[MX+5], ans[MX+5], n;
bool isBig[MX+5];
ll BIT[MX+5]; 
void update(int pos, int val) // go up
{
    if(val==0 || pos<=0) return;
    while(pos<=MX)
    {
        BIT[pos]+=val;
        pos +=(pos & -pos);
    }
}
int query(int pos) // go down
{
    if(pos<=0) return 0;
    ll sum = 0;
    while(pos>0)
    {
        sum+=BIT[pos];
        pos -=(pos&-pos);
    }
    return sum;
}

void dfs(int u, int p)
{
    siz[u] = 1;
	for(int v:g[u]) if(v!=p) dfs(v, u), siz[u]+=siz[v];
}
void add(int u, int p, int val)
{
    update(freq[color[u]], -1);
    freq[color[u]]+=val;
    update(freq[color[u]], +1);
    for(int v:g[u]){
        if(v!=p && !isBig[v]) add(v, u, val);
    }
}
void solve(int u, int p, bool big)
{
    //cout << u  << " starts \n";
    int mx_sz = -1, bigChild = -1;
    for(int v:g[u]){
        if(v!=p && siz[v]>mx_sz) mx_sz = siz[v], bigChild = v;
    }
    for(int v:g[u]){
        if(v!=p && v!=bigChild) solve(v, u, 0);
    }
    if(bigChild != -1) isBig[bigChild] = 1, solve(bigChild, u, 1);
    add(u, p, 1);
    for(ii q:queries[u]){
        ll cnt = query(MX) - query(q.ff-1);
        ans[q.ss] = cnt;
    }
    if(bigChild != -1) isBig[bigChild] = 0;
    if(!big)
        add(u, p, -1);
   // cout << u << " ends \n";
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin>>n>>q;
	f(i, 1, n) cin>>color[i];
	f(i, 1, n-1){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i, 0, q-1){
		int v, k;
		cin>>v>>k;
		queries[v].pb({k, i});
	}
	dfs(1, 0);
	solve(1, 0, 0);
	//cout << "end\n";
	f(i, 0, q-1)
		cout << ans[i] << "\n";
	return 0;
}


