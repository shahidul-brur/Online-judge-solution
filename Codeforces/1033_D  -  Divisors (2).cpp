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
const ll MOD = 998244353;
const int maxn = (int)2e5+5;
const int LOGN = 20;
ll a[505];
map<ll, ll> cnt;
ll BS(ll x)
{
    ll lo = 2, hi = min(x, 1000000LL);
    while(lo<=hi)
    {
        ll m = (lo+hi)/2;
        if(m*m*m==x)
            return m;
        if(m*m*m>x)
            hi = m-1;
        else lo = m+1;
    }
    return 0;
}
long long my_sqrt(long long x) {
  assert(x > 0);
  long long y = (long long) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return -1;
}

long long my_crt(long long x) {
  assert(x > 0);
  long long y = (long long) (powl((long double) x, 1.0 / 3.0) + 0.5);
  while (y * y * y < x) {
    y++;
  }
  while (y * y * y > x) {
    y--;
  }
  if (y * y * y == x) {
    return y;
  }
  return -1;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    f1(i,n)
    {
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    set<ll> div;
    //sieve();
    ll ans = 1;
    f1(i,n){
        ll x = a[i];
        //cout << x << "\n=======\n";
        ll r = my_sqrt(x);
        ll rr =  -1;
        if(r>0)
            rr = my_sqrt(r);
        ll r3 = my_crt(x);
        //cout << r << ", " << rr << ", " << r3 << "\n";
        if(rr>0){
            //cout << " sq : " << r << "\n";
            cnt[rr]+=4;
            div.insert(rr);
            x = 1;
        }
        else if(r>0){
            //cout << " p4 : " << rr << "\n";
            cnt[r]+=2;
            div.insert(r);
            x = 1;
        }
        else if(r3>0){
            //cout << " cube : " << r3 << "\n";
            cnt[r3]+=3;
            x = 1;
            div.insert(r3);
        }
        else 
        {
            f1(j,n){
                ll y = a[j];
                if(y==x) continue;
                ll g = __gcd(x,y);
                if(g>1){
                    ll d2 = x/g;
                    //cout<< "common divisor with " << y << ": " << g << ", " << d2 << " * \n";
                    div.insert(g);
                    div.insert(d2);
                    cnt[g]++;
                    cnt[d2]++;
                    x = 1;
                    break;
                }
            }
        }
        if(x>1){
            //cout << "distinct !\n";
            int c = 1;
            while(i+1<=n && a[i+1]==a[i]){
                c++;
                i++;
            }
            ans = (ans*(c+1)*(c+1))%MOD;
        }
    }
    for(ll d:div)
    {
        //cout<< d << " :: " << cnt[d] << "\n";
        ans = (ans * (cnt[d]+1))%MOD;
    }
    cout<< ans;
    fflush(stdout);
    return 0;
}



