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
const int maxn = 1505;
const int LOGN = 20;
ll inv1[maxn], pwr1[maxn], h1[maxn];
ll inv2[maxn], pwr2[maxn], h2[maxn];
ll mod1 = (int)1e9+7, base1=31;
ll mod2 = (int)1e9+9, base2=29;
ll mod_pow(ll b, ll p, ll mod){
	if(p==-1) p = mod-2;
	ll ret = 1;
	while(p>0){
		if(p&1){
			ret*=b;
			if(ret>mod) ret%=mod;
		}
		b*=b;
		if(b>mod) b%=mod;
		p>>=1;
	}
	return ret;
}
string s, g;
int cnt[maxn], k, n;
bool good[26];
ll get_sub1(int l, int r){
	ll ret = h1[r] - h1[l-1];
	if(ret<0) ret+=mod1;
	ret*=inv1[l-1];
	if(ret>mod1) ret%=mod1;
	return ret;
}
ll get_sub2(int l, int r){
	ll ret = h2[r] - h2[l-1];
	if(ret<0) ret+=mod2;
	ret*=inv2[l-1];
	if(ret>mod2) ret%=mod2;
	return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s>>g;
    n = s.size();
    s= "#"+s;
    cin>>k;
    f0(i,26) good[i] = g[i]-'0';
    f1(i,n){
    	cnt[i] = cnt[i-1] + !good[s[i]-'a'];
    }
    pwr1[0] = pwr2[0] = inv1[0] = inv2[0] = 1;
    ll I1 = mod_pow(base1, -1, mod1);
    ll I2 = mod_pow(base2, -1, mod2);
    f1(i,n){
    	pwr1[i] = pwr1[i-1]*base1;
    	pwr2[i] = pwr2[i-1]*base2;

    	inv1[i] = inv1[i-1]*I1;
    	inv2[i] = inv2[i-1]*I2;

    	if(pwr1[i]>mod1) pwr1[i]%=mod1;
    	if(inv1[i]>mod1) inv1[i]%=mod1;
    	if(pwr2[i]>mod2) pwr2[i]%=mod2;
    	if(inv2[i]>mod2) inv2[i]%=mod2;
    } 
    f1(i,n){
    	h1[i] = h1[i-1] + pwr1[i-1]*(s[i]-'a'+1);
    	//cout << i << " : " << h1[i] << "\n";
    	if(h1[i]>mod1) h1[i]%=mod1;
    	h2[i] = h2[i-1] + pwr2[i-1]*(s[i]-'a'+1);
    	if(h2[i]>mod2) h2[i]%=mod2;
    }
    set<pair<ll, ll> > st;
    f1(i,n){
    	f2(j,i,n){
    		if(cnt[j]-cnt[i-1]>k) {
    			continue;
    		}
    		ll hs1 = get_sub1(i,j);
    		ll hs2 = get_sub2(i,j);
    		//cout << i << "->" << j << ": ";
    		//cout << hs1 << " " << hs2 << "\n";
    		st.insert(mp(hs1, hs2));
    	}
    }
    cout << st.size();
    return 0;
}
