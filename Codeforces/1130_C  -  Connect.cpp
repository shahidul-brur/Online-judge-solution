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
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1,-1, 0, 0};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
char s[55][55];
int n, r1, c1, r2, c2;
vii v[2];
bool vis[55][55], ok;
void dfs(int tp, int r, int c){
    if(tp==0 && r==r2 && c==c2) ok=1; 
    vis[r][c] = 1;
    v[tp].pb(mp(r,c));
    f0(i,4){
        int nr = r+dx4[i];
        int nc = c+dy4[i];
        // cout << r << " " << c << " => ";
        // cout << nr << " " << nc << "\n";
        if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && s[nr][nc]=='0'){
            // cout << r << " " << c << " => ";
            // cout << nr << " " << nc << "\n";
            dfs(tp, nr, nc);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--; r2--;
    c1--; c2--;

    f0(i,n) cin>>s[i];
    ok=0;
    dfs(0, r1,c1);
    dfs(1, r2,c2);
    if(ok){
        cout << "0";
        return 0;
    }
    ll ans = LLONG_MAX;
    for(ii p1:v[0]){
        //cout << p1.ff << " " << p1.ss << "\n";
        for(ii p2:v[1]){
            //cout << "     -> " <<  p2.ff << " " << p2.ss << "\n";
            ll cur = (p1.ff-p2.ff)*1LL*(p1.ff-p2.ff) + (p1.ss-p2.ss)*1LL*(p1.ss-p2.ss);
            ans = min(ans, cur);
        }
    }
    cout << ans;
    return 0;
}
