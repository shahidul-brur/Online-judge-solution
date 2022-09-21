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
int a[55];
vi g[52];
bool vis[52];
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    cnt++;
    for(int v:g[u]) if(!vis[v]) dfs(v);
}
bool ase[52];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        mem(vis,0);
        cin>>n;
        int lst = 0;
        f1(i,n) {
            cin>>a[i];
            if(a[i]==47) lst++;
        }
        
        f1(i,n-1)f2(j,i+1,n) if(__gcd(a[i], a[j])==1){
            g[i].pb(j);
            g[j].pb(i);
        }
        cnt = 0;
        dfs(1);
        
        if(cnt==n){
            cout << "0\n";
        }
        else{
            cout << "1\n";
            if(lst==n) a[1]= 2;
            else a[1] = 47;
        }
        f1(i,n) {
            if(i>1) cout << " ";
            cout << a[i];
        }
        cout << "\n";
        f1(i,n) g[i].clear();
    }
    return 0;
}