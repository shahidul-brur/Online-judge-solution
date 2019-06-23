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
const int maxn = (int)3e5+5;
const int LOGN = 20;
ll a[maxn];
ll b[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,m;
    cin>>n;
    ll sa = 0;
    f1(i,n) cin>>a[i], sa+=a[i];
    cin>>m;
    ll sb = 0;
    f1(i,m) cin>>b[i], sb+=b[i];
    if(sa!=sb)
    {
        cout << "-1\n";
        return 0;
    }
    int cnt = 0;
    int pa = 1, pb = 1;
    ll ca,cb;
    while(1)
    {
        if(pa> n || pb>m) break;
        if(a[pa]==b[pb])
        {
           // cout << pa << " " << pb << " " << a[pa] << " #\n";
            cnt++;
            pa++;
            pb++;
            continue;
        }
        ll ca = a[pa], cb = b[pb];
        ++pa;
        ++pb;
        while(ca != cb)
        {
            while(ca<cb && pa<=n)
            {
                ca+=a[pa];
                ++pa;
            }
            
            while(cb<ca && pb<=m)
            {
                cb+=b[pb];
                ++pb;
            }
        }
        ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}


