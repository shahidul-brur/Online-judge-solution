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
string tar;
ll dp[25][4][2]; // 0->less, 1->equal
ll cal(int p, int nonz, int eq)
{
    if(p==tar.length()) return 1;
    if(dp[p][nonz][eq]!=-1) return dp[p][nonz][eq];
    ll cur = cal(p+1, nonz, (tar[p]=='0' && eq==1));
    if(eq)
    {
        if(nonz<3 && tar[p]> '0')
        {
            if(tar[p]> '1')
                cur += (tar[p]- '0' - 1) * cal(p+1, nonz+1, 0);
            cur += cal(p+1, nonz+1, 1);
        }
    }
    else
    {
        if(nonz<3)
        {
            cur += 9 * cal(p+1, nonz+1, 0);
        }
    }
    dp[p][nonz][eq] = cur;
    //cout << p << " " << nonz << " " << eq << ": ";
    //cout << cur << "\n";
    return cur;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int q;
    cin>>q;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        --l;
        tar = to_string(l);
        ll lft;
        memset(dp, -1, sizeof(dp));
        lft = cal(0, 0, 1);
        tar = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll rgt = cal(0, 0, 1);
        cout << rgt - lft << "\n";
    }
    return 0;
}


