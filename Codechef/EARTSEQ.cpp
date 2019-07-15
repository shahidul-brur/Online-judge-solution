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
vi primes;
int a[50002];
bool comp[1000002];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    primes.pb(2);
    for(int i=3;;i+=2){
    	if(comp[i]) continue;
    	primes.pb(i);
    	if(primes.size()==50000) {
    		break;
    	}
    	for(ll j = i*1LL*i;j<=1000000;j+=2*i)
    		comp[j]=1;
    }
    int idx = 1;
    a[0] = 2;
    while(1){
    	if(primes[idx]*1LL*primes[idx-1]>1e9) break;
    	a[idx] = primes[idx]*primes[idx-1];
    	++idx;
    }
    cout << a[idx-1];
    /*int i = 0, j = 1, k = 2;
    while(idx<50000){
    	int p0 = primes[i], p1 = primes[j], p2 = primes[k];
    	int c0 = p0, c1 = p1, c2 = p2;
    	while(1){
    		int b0 = p0, b1 = p1, b2 = p2;
    		while(1){
    			a[idx++] = b0*c1;
    			a[idx++] = b1*c2;
    			a[idx++] = b2*c0;
    			b0*=p0;
    			b1*=p1;
    			b2*=p2;
    			if(b0*1LL*c1>500000000 || b1*1LL*c2>500000000 || b2*1LL*c0>500000000)
    				break;
    		}
    		c0*=p0;
    		c1*=p1;
    		c2*=p2;
    		if(c0*1LL*b2>500000000 || c1*1LL*b0>500000000 || c2*1LL*b1>500000000) 
    			break;
    	}

    }*/
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	a[0] = primes[0] * primes[n-1];
    	f0(i,n){
    		if(i>0) cout << " ";
    		cout << a[i];
    	}
    	cout << "\n";
    }
    return 0;
}
