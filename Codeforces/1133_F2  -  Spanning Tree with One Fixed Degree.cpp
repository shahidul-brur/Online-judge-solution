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
const int LOGN = 20;
int par[maxn];
vii edge_without_1, edge_with_1, ans, remain;
int find_par(int u){
    return par[u] = (par[u]==u?u:find_par(par[u]));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, d;
    cin>>n>>m>>d;
    f1(i,m){
        int u, v;
        cin>>u>>v;
        if(u==1 || v==1) edge_with_1.pb(mp(u,v));
        else edge_without_1.pb(mp(u,v));
    }
    if(edge_with_1.size()<d){
        cout << "NO\n";
        return 0;
    }
    f1(i,n) par[i]=i;
    for(ii p:edge_without_1) par[find_par(p.ff)] = find_par(p.ss);
    int req = 0;
    for(ii p:edge_with_1){
        int p1 = find_par(p.ff), p2 = find_par(p.ss);
        if(p1!=p2)
            ++req, ans.pb(p), par[p1] = p2;
        else remain.pb(p);
    }
    if(req>d){
        cout << "NO\n";
        return 0;
    }
    f0(i,d-req) ans.pb(remain[i]);
    f1(i,n) par[i]=i;
    for(ii p:ans) par[find_par(p.ff)] = find_par(p.ss);
    for(ii p:edge_without_1){
        int p1 = find_par(p.ff), p2 = find_par(p.ss);
        if(p1!=p2) ans.pb(p), par[p1] = p2;
    }
    cout << "YES\n";
    for(ii p:ans) cout << p.ff << " " << p.ss << "\n";
    return 0;
}
