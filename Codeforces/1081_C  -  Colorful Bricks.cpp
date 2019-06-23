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
const int MOD = 998244353 ;
const int maxn = 2003;
const int LOGN = 20;
ll dp[maxn][maxn];
int n, m, k;
ll po[maxn][maxn];
ll cal(int pos, int rem){
    if(rem==0){
        return 1LL;
    }
    if(n-pos+1==rem){
        if(m>1)
            return po[m-1][n-pos+1];
        return 0LL;
    }
    if(pos==n)
    {
        if(rem==1){
            return m-1;
        }
        else if(rem>1){
            return 0LL;
        }
        return 1LL;
    }
    
    ll &ret = dp[pos][rem];
    if(ret!=-1) return ret;
    if(rem==0){
        ret = cal(pos+1, rem);
    }
    else if(rem>0){
        ret = cal(pos+1, rem);
        ll ext = ((m-1)*cal(pos+1, rem-1))%MOD;
        ret = (ret + ext)%MOD;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f1(i,2000)
    {
        po[i][0] = 1LL;
        f1(j, 2000)
        {
            po[i][j] = (po[i][j-1] * i) % MOD;
        }
    }
    cin>>n>>m>>k;
    if(k==0){
        cout << m << "\n";
        return 0;
    }
    mem(dp,-1);
    ll rec = cal(2, k);
    ll ans = (m * rec)%MOD;
    cout << ans << "\n";
    return 0;
}
