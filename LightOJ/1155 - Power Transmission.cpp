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
using namespace std;
typedef long long ll;
const int maxn = 100005, maxe = 100005;
int flow[maxe], cape[maxe], pre[maxe], to[maxe], Q[maxn], from[maxe];
int dist[maxn], last[maxn], capn[maxn], tmp_last[maxn], rgt[maxn];
int nNode, nEdge, src, snk;
inline void add(int u, int v, int c){
    flow[nEdge]=0, from[nEdge]=u, cape[nEdge]=c, to[nEdge]=v, pre[nEdge]=last[u], last[u]=nEdge++;
    flow[nEdge]=0, from[nEdge]=v, cape[nEdge]=0, to[nEdge]=u, pre[nEdge]=last[v], last[v]=nEdge++;
}
bool bfs(){
    memset(dist, -1, sizeof(dist));
    int qs=0, qe=0;
    dist[src]=0;
    Q[qe++] = src;
    while(qs<qe) {
        int u=Q[qs++];
        for(int e=last[u];e>=0;e=pre[e]) {
            int v=to[e];
            if(flow[e]<cape[e] && dist[v]==-1){
                dist[v] = dist[u]+1;
                Q[qe++]=v;
            }
        }
    }
    return dist[snk]!=-1;
}
int dfs(int u, int flw) {
    if(u==snk) return flw;
    for(int &e=tmp_last[u];e>=0;e=pre[e]) {
        int v = to[e];
        if(dist[v] == dist[u]+1 && flow[e]<cape[e]) {
            int send = min(flw, cape[e]-flow[e]);
            int cur = dfs(v, send);
            if(cur>0){
                flow[e]+=cur;
                flow[e^1]-=cur;
                return cur;
            }
        }
    }
    return 0;
}
ll dinic()
{
    ll mx_flow=0;
    while(bfs()){
        ll p=mx_flow;
        for(int i=0;i<=nNode;i++) tmp_last[i]=last[i];
        while(1){
            int cur = dfs(src, INT_MAX);
            if(cur==0) break;
            mx_flow+=(ll)cur;
        }
    }
    return mx_flow;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); // cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t,edge, n;
    src = 0;
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        memset(last, -1, sizeof(last));
        nEdge = 0;
        scanf("%d", &n);
        nNode = n;
        capn[snk] = INT_MAX;
        capn[src] = INT_MAX;
        for(int i = 1;i<=n;i++) {
            scanf("%d", &capn[i]);
            rgt[i] = ++nNode;
            add(i, rgt[i], capn[i]);
        }
        scanf("%d", &edge);
        for(int i = 0;i<edge;i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            add(rgt[u],v,c);
        }
        int starting, ending;
        snk = ++nNode;
        scanf("%d %d", &starting, &ending);
        for(int i=0;i<starting;i++) {
            int u;
            scanf("%d", &u);
            add(0, u, INT_MAX);
        }
        for(int i=0;i<ending;i++) {
            int u;
            scanf("%d", &u);
            add(rgt[u], snk, INT_MAX);
        }
//        for(int e = 0;e<nEdge;e+=2){
//             cout << e << " : " << from[e] << " to " << to[e] << " -> " << cape[e] << "\n";
//        }
        printf("Case %d: %lld\n", cas, dinic());
    }
    return 0;
}
