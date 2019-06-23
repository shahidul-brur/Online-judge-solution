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
int p2[2000005];
int cp2[2000005];
//int rp2[2000005];
//int crp2[2000005];
int one[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    p2[0] = cp2[0] = 1;
    f1(i,200000) 
    {
        p2[i] = (p2[i-1]*1LL*2)%MOD;
        cp2[i] = (cp2[i-1] + p2[i])%MOD;
//        rp2[i] = (p2[i] + MOD - 1)%MOD;
//        crp2[i] = (crp2[i-1] + rp2[i])%MOD;
    }
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    f0(i,n)
    {
        one[i+1] = one[i] + s[i] - '0';
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int onn = (one[r] + MOD - one[l-1])%MOD;
        --onn;
        ll ans = cp2[onn];
        int of = (r-l+1) - (onn+1);
        --of;
        ll ext = cp2[onn] * 1LL * cp2[of];
        ext%=MOD;
        ans = (ans+ext)%MOD;
        cout << ans << "\n";
    }
    return 0;
}


