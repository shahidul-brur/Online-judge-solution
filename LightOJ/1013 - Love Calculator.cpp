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
ll dp[32][32][32];
int lcs, cas, xl, yl;
int vis[32][32][32];
char x[35], y[35];
int cal_lcs()
{
    int L[32][32];
    for (int i=0; i<=xl; i++)
        for (int j=0; j<=yl; j++)
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (x[i-1] == y[j-1])  L[i][j] = L[i-1][j-1] + 1;
            else  L[i][j] = max(L[i-1][j], L[i][j-1]);
    return L[xl][yl];
}
ll cal_ans(int p1, int p2, int l)
{
    if(p1==xl || p2==yl){
        if(l==lcs)
            return 1;
        return 0;
    }
    if(vis[p1][p2][l]==cas)
        return dp[p1][p2][l];
    vis[p1][p2][l] = cas;
    ll cur = 0;
    if(x[p1]==y[p2])
        cur = cal_ans(p1+1, p2+1, l+1);
    else
        cur = cal_ans(p1+1, p2, l) + cal_ans(p1, p2+1, l);
    dp[p1][p2][l] = cur;
    return cur;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s%s",x,y);
        xl=strlen(x);
        yl=strlen(y);
        lcs = cal_lcs();
        ll ans = cal_ans(0,0,0);
        printf("Case %d: %d %lld\n",cas, xl+yl-lcs, ans);
    }
    return 0;
}
