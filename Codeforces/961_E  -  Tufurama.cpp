/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 200005;
vector<int> tree[4*MAX];
int arr[MAX], n;

void build(int node, int l, int r) { 
    if(l == r) { 
        tree[node].push_back(arr[l]); 
        return; 
    }
    int mid = (l + r)/2;
    int left = node * 2;
    int right = node * 2 + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    merge(all(tree[left]), all(tree[right]), back_inserter(tree[node])); 
}

//how many numbers are less than k in the range [l, r]
int query(int node, int l, int r, int i, int j, int k){ 
    if(i > r || l > j) 
        return 0;
    if(i <= l && r <= j) 
        return lower_bound(all(tree[node]), k) - tree[node].begin();
    int mid = (l + r)/2;
    int left = node * 2;
    int right = node * 2 + 1;
    return query(left, l, mid, i, j, k) + query(right, mid+1, r, i, j, k);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	f(i, 1, n) cin>>arr[i];
	build(1, 1, n);
	ll ans = 0;
	f(i, 2, n)
	{
		int upto = min(arr[i], i-1);
		int les = query(1, 1, n, 1, upto, i);
		ans = ans + (upto - les);
	}
	cout << ans << "\n";
	return 0;
}
