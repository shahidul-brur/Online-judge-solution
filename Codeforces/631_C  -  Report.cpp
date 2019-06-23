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
int a[maxn], b[maxn], t[maxn], ind[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    f1(i,n) cin>>a[i];
    f1(i,m){
    	int typ, r;
    	cin>>typ>>r;
    	t[r] = typ;
    	ind[r] = i;
    }
    if(n==1 || m==0){
    	f1(i,n) cout << a[i] << " ";
    	return 0;
    }
    int i = n;
	while(i>=1 && t[i]==0) b[i] = a[i], i--;
	if(i>1){
		sort(a+1, a+1+i);
		int idx = i, lft = 1, rgt=i;
		int last = ind[i];
	    while(i>=1){
	    	int typ = t[i];
	    	while(1){
	    		if(typ==1) b[idx--] = a[rgt--];
	    		else b[idx--] = a[lft++];
	    		i--;
	    		if(rgt<lft || i==0 || (ind[i]>last && t[i]!=0)) break;
	    	}
	    	last = ind[i];
	    }
	}
	sort(a+1, a+1+n);
    f1(i,n) cout << b[i] << " ";
    return 0;
}
