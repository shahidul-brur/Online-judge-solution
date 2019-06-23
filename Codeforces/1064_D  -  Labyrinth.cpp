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
char s[2005][2005];
int vis[2005][2005][2];
int n, m, r, c, x, y;
void bfs(int rr, int cc)
{
    queue<pair<ii, ii> > q;
    vis[rr][cc][0]=0;
    vis[rr][cc][1]=0;
    q.push(mp(mp(rr,cc), mp(0,0)));
    while(!q.empty())
    {
        pair<ii, ii> u = q.front(); q.pop();
        rr = u.ff.ff, cc=u.ff.ss;
        int lft = u.ss.ff, rgt=u.ss.ss;
        if(rr>0 && s[rr-1][cc]!='*' && (lft<vis[rr-1][cc][0] || rgt<vis[rr-1][cc][1])){ // up
            vis[rr-1][cc][0] = min(lft,vis[rr-1][cc][0]);
            vis[rr-1][cc][1] = min(rgt,vis[rr-1][cc][1]);
            q.push(mp(mp(rr-1,cc), mp(lft,rgt)));
        }
        if(rr<n-1 && s[rr+1][cc]!='*' && (lft<vis[rr+1][cc][0] || rgt<vis[rr+1][cc][1])){ // down
            vis[rr+1][cc][0] = min(lft,vis[rr+1][cc][0]);
            vis[rr+1][cc][1] = min(rgt,vis[rr+1][cc][1]);
            q.push(mp(mp(rr+1,cc), mp(lft,rgt)));
        }
        
        if(cc<m-1 && s[rr][cc+1]!='*' && (lft<vis[rr][cc+1][0] || rgt+1<vis[rr][cc+1][1]) && rgt<y){ // right
            vis[rr][cc+1][0] = min(lft,vis[rr][cc+1][0]);
            vis[rr][cc+1][1] = min(rgt+1,vis[rr][cc+1][1]);
            q.push(mp(mp(rr,cc+1), mp(lft,rgt+1)));
        }
        if(cc>0 && s[rr][cc-1]!='*' && (lft+1<vis[rr][cc-1][0] || rgt<vis[rr][cc-1][1]) && lft<x){ // left
            vis[rr][cc-1][0] = min(lft+1,vis[rr][cc-1][0]);
            vis[rr][cc-1][1] = min(rgt,vis[rr][cc-1][1]);
            q.push(mp(mp(rr,cc-1), mp(lft+1,rgt)));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>n>>m>>r>>c>>x>>y;
    --r;--c;
    f0(i,n) cin>>s[i];
    f0(i,n) f0(j,m)
        vis[i][j][0] = vis[i][j][1] = INT_MAX;
    bfs(r,c);
    int cnt = 0;
    f0(i,n) f0(j,m) if(vis[i][j][0]!=INT_MAX || vis[i][j][1]!=INT_MAX) cnt++;
    cout << cnt;
    return 0;
}

