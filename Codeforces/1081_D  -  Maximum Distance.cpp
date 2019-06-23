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
#include<stdio.h>
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
const int LOGN = 16;
vi g[maxn];
vi c[maxn];
int par[maxn], nodes[maxn];
bool sp[maxn];
int findPar(int u)
{
	return (par[u]==u?u:(par[u]=findPar(par[u])));
}
struct edge{
	int u, v, w;
	bool operator< (const edge &o) const{
		return w<o.w;
	}
}e[maxn];
int n,m,ans;
void unite(int eid){
	int u=findPar(e[eid].u);
	int v=findPar(e[eid].v);
	if(u==v) return;
	if(nodes[u]<nodes[v]){
		par[u] = v;
		nodes[v]+=nodes[u];
	}
	else{
		par[v] = u;
		nodes[u]+=nodes[v];
	}
	if(sp[u] && sp[v]) ans = max(ans, e[eid].w);
	if(sp[u]) sp[v] = 1;
	if(sp[v]) sp[u] = 1;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
	scanf("%d %d %d", &n, &m, &k);
	f1(i,k){
		int u; scanf("%d", &u);
		sp[u]=1;
	}
	f0(i,m) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	sort(e, e+m);
	f1(i,n) par[i]=i, nodes[i]=1;
	f0(i,m) unite(i);
	f1(i,k)
		printf("%d ", ans);
    return 0;
}
