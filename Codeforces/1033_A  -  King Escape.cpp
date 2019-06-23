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
bool vis[1005][1005];
int n;
int ax, ay, bx, by, cx, cy;
void dfs(int x, int y)
{
    vis[x][y] = 1;
    f0(i,8)
    {
        int xx = x+dx8[i];
        int yy = y+dy8[i];
        if(xx<1 || xx>n || yy<1 || yy>n || vis[xx][yy]) continue;
        dfs(xx,yy);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    f1(i,n)
    {
        vis[i][ay] = 1;
        vis[ax][i] = 1;
    }
    int j = 1;
    fr(i,ax-1,1)
    {
        if(ay+j<=n && ay+j>=1)
            vis[i][ay+j] = 1;
        if(ay-j<=n&& ay-j>=1)
            vis[i][ay-j] = 1;
        j++;
    }
    j = 1;
    f2(i,ax+1,n)
    {
        if(ay+j<=n && ay+j>=1)
            vis[i][ay+j] = 1;
        if(ay-j<=n&& ay-j>=1)
            vis[i][ay-j] = 1;
        j++;
    }
    dfs(bx, by);
    if(vis[cx][cy])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}


