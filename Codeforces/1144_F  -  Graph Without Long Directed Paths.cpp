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
int m, dir[maxn];
vector<pair<int, ii> > g[maxn];
vector <int> edge[maxn];
int color[maxn], visited[maxn], n, bicolor;
void doColor()
{
    mem(visited, 0);
    mem(color, -1);
    queue<int> q;
    q.push(1);
    color[1] = 0;
    visited[1] = 1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0; i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(color[v]!=-1 && color[u]==color[v])
            {
                bicolor=0;
                break;
            }
            if(visited[v]==0)
            {
                color[v]=1-color[u];
                visited[v]=1;
                q.push(v);
            }
        }
        if(bicolor==0)
            break;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int u, v;
    cin>>n>>m;
    f1(i,m)
    {
        cin>>u>>v;
        g[u].pb({v,{i,0}});
        g[v].pb({u,{i,1}});
        edge[u].pb(v);
        edge[v].pb(u);
    }
    bicolor=1;
    doColor();
    if(bicolor==0){
        cout << "NO\n";
        return 0;
    }
    mem(dir,-1);
    f1(i,n)
    {
        //cout << color[i] << "\n";
        for(auto e:g[i]){
            if(dir[e.ss.ff]==-1){
                if(e.ss.ss==0)
                    dir[e.ss.ff] = color[i];
                else dir[e.ss.ff] = color[e.ff];
            }
        }
    }
    cout << "YES\n";
    f1(i,m) cout << dir[i];
    return 0;
}