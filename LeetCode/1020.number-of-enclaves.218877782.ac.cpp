#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = 30002;
const int LOGN = 20;
int r, c, g[505][505];
void dfs(int rr, int cc)
{
    if(rr<0 || rr>=r || cc<0 || cc>=c || g[rr][cc]==0){
        return;
    }
    g[rr][cc]=0;
    f0(i,4)
    {
        int nr = rr+dx4[i];
        int nc = cc+dy4[i];
        dfs(nr,nc);
    }
}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        r = A.size();
        c = A[0].size();
        f0(i,r) f0(j,c) g[i][j] = A[i][j];
        
        f0(i,r) 
        {
            if(g[i][0]==1) dfs(i,0);
            if(g[i][c-1]==1) dfs(i,c-1);
        }
        
        f0(i,c) 
        {
            if(g[0][i]==1) dfs(0,i);
            if(g[r-1][i]==1) dfs(r-1,i);
        }
        
        int cnt = 0;
        f0(i,r) f0(j,c) cnt+=g[i][j];
        return cnt;
    }
};
