#include<bits/stdc++.h>
using namespace std;

const int MX = 30002, LOG = 20;
int parent[LOG+2][MX+5]; // 2^k th parent of a node
int ara[2*MX+5]; // array of Euler path
int n; // total nodes
int siz; // size of Euler path array
int cost[MX+5]; // cost of a node
int pos[MX+5]; // starting position of a node in Euler array
int posEnd[MX+5]; // Ending position of a node in Euler array
int level[MX+5]; // level or depth of node in tree
int tree[4*MX+5]; // segment tree
vector<int> g[MX+5]; // adjacency graph
void dfs(int u, int par, int depth)
{
    ara[siz] = cost[u]; pos[u] = siz; siz++;
    parent[0][u] = par;
    level[u] = depth;
    int s = g[u].size();
    for ( int i = 0; i < s ; i++ )
    {
        int v = g[u][i];
        if(v!=par) 
            dfs(v, u, depth+1);
    }
    ara[siz] = -cost[u];
    posEnd[u] = siz;
    siz++;
}

void build() //call once after input
{  // build the tree
  for (int i = siz - 1; i >= 1; --i) 
    tree[i] = tree[i<<1] + tree[(i<<1)|1];
}

void update(int p, int value) 
{  // set value at position p
  for (tree[p += siz] = value; p > 1; p >>= 1)
    tree[p>>1] =  tree[p] + tree[p^1];
}

int query(int l, int r) 
{  // sum on interval [l, r)
  int res = 0;
  for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) 
  {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}

void preprocess() // LCA preprocess
{
	for (int i = 1; i < LOG; i++)
        for (int j = 0; j <n ; j++)
            parent[i][j] = parent[i-1][parent[i-1][j]];
}

int lca(int p, int q)
{
    if (level[p] < level[q])
          swap(p, q);
    int h = level[p] - level[q];
    for (int i = 0; i < LOG; i++)
        if (h & (1<<i))
            p = parent[i][p];
   if (p == q)
          return p;
    for (int i = LOG-1; i >= 0; i--)
        if (parent[i][q] != parent[i][p])
            q = parent[i][q], p = parent[i][p];
    return parent[0][p];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", " w", stdout);
    int t;
    scanf("%d", &t);
    for ( int cas = 1; cas <= t; cas++ )
    {
        scanf("%d", &n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d", &cost[i]);
        
        for( int i = 1 ; i < n ; i++ )
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        siz = 0;
        dfs(0, 0, 0);
        preprocess();
        for( int i = 0 ; i < siz ; i++ )
            tree[i+siz] = ara[i];
        build();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", cas);
        while(q--)
        {
            int tp;
            scanf("%d", &tp);
            if( tp == 1 )
            {
                int node, val;
                scanf("%d %d", &node, &val);
                cost[node] = val;
                update(pos[node], val);
                update(posEnd[node], -val);
            }
            else 
            {
                int u, v;
                scanf("%d %d", &u, &v);
                int lc = lca(u, v);
                int qu = query(pos[0], pos[u]+1);
                int qv = query(pos[0], pos[v]+1);
                int qlc = query(pos[0], pos[lc]+1);
                int ans = qu + qv - 2*qlc + cost[lc];
                printf("%d\n", ans);
            }
        }
        for( int i = 0 ; i < n ; i++ )
            g[i].clear();
    }
    return 0;
}
