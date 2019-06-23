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
const int MX = 1000010;
bool is_composite[MX];
int sp[MX];
vector<ii> facts;
void Sieve(){
	for (int i = 2; i < MX; i += 2)
        sp[i] = 2; // even numbers have smallest prime factor 2
	for (ll i = 3; i < MX; i += 2){
		if (is_composite[i]) continue;
        sp[i] = i; // prime number itself its smallest prime factor
        for (ll j = i; (j*i) < MX; j += 2){
            if (!is_composite[j*i]){
                is_composite[j*i] = true;
                sp[j*i] = i;
            }
        }
	}
}

void factorize(int n) // log n
{
    while(n>1){
        int tem = n, pw = 0;
        while(tem%sp[n]==0)
            tem/=sp[n], ++pw;
        facts.push_back(mp(sp[n], pw));
        n = tem;
    }
}
int p2(int n)
{
    int x = 1;
    while(x<n)
        x*=2;
    return x;
}
bool isP2(int n)
{
    if(n==1) return 0;
    int x = 1;
    while(x<n)
        x*=2;
    return x==n;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    Sieve();
    int n;
    cin>>n;
    factorize(n);
    int s = facts.size();
    int cnt = 0, mxp = 0, ans = 1;
    f0(i,s) mxp = max(mxp, facts[i].ss);
    if(!isP2(mxp)) cnt = 1;
    f0(i,s)
    {
        if(mxp!=facts[i].ss) cnt = 1;
        ans *= facts[i].ff;
    }
    mxp = p2(mxp);
    if(mxp==1){
        cout << ans << " 0\n";
        return 0; 
    }
    while(mxp>1){
        cnt++;
        mxp/=2;
    }
    cout << ans << " " << cnt << "\n";
    return 0;
}
