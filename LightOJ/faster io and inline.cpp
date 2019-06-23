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
const int maxn = 205;
const int maxe = 10005;
const int LOGN = 20;
int src, snk, nEdge, n;
int dist[maxn], last_edge[maxn], pre_edge[maxe], to[maxe];
int capa[maxe], flow[maxe], tem_last_edge[maxn];
inline void read(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;
    while((c<'0' | c>'9') && c != '-')
        c = getchar();
    if(c=='-') {
        neg=1, c=getchar();
    }
    while(c>='0' && c<='9') {
        x = (x<<1) + (x<<3) + c - 48;
        c = getchar();
    }
    if(neg) 
        x=-x;
}
inline void add_edge()
{
    int u, v, c;
    read(u);
    read(v);
    read(c);
    if(u==v) return;
    flow[nEdge] = 0, capa[nEdge] = c, to[nEdge] = v, pre_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;
    flow[nEdge] = 0, capa[nEdge] = c, to[nEdge] = u, pre_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;
}
int max_flow;
int q[maxn];
inline bool bfs()
{
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    int q_siz = 0, q_front = 0;
    q[q_siz++] = src;
    while(q_front<q_siz){
        int u = q[q_front++];
        for(int e = last_edge[u];e>=0;e = pre_edge[e]){
            int v = to[e];
            if(dist[v] == -1 && flow[e] < capa[e]){
                dist[v] = dist[u] + 1;
                q[q_siz++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}
inline int dfs(int u, int flw){
    if(u==snk) return flw;
    for(int &e = tem_last_edge[u];e>=0;e = pre_edge[e]){
        int v = to[e];
        if(dist[v] == dist[u] + 1 && flow[e]<capa[e]){
            int cur_flow = dfs(v, min(flw, capa[e]-flow[e]));
            if(cur_flow>0){
                flow[e]+=cur_flow;
                flow[e^1]-=cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}
inline void dinic()
{
    max_flow = 0;
    while(bfs()){
        for(int i = 1;i<=n;i++)  tem_last_edge[i] = last_edge[i];
        while(1){
            int cur_flow = dfs(src, INT_MAX);
            if(cur_flow==0) break;
            max_flow+=cur_flow;
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, e;
    read(t);
    f1(cas,t)
    {
        read(n);
        read(src);
        read(snk);
        read(e);
        memset(last_edge, -1, sizeof(last_edge));
        nEdge = 0;
        
        f1(i,e) add_edge();
        dinic();
        printf("Case %d: %d\n", cas, max_flow);
    }
    return 0;
}
