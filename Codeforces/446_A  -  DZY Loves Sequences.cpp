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
const int MAX = 100002;
int arr[MAX], n, lft[MAX], rgt[MAX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	if(n==1)
	{
		cout << "1\n";
		return 0;
	}
	f(i, 1, n) 
	{
		cin>>arr[i];
		lft[i] = 1;
		if(i>1 && arr[i]>arr[i-1])
			lft[i] = 1 + lft[i-1];
	}
	F(i, n, 1)
	{
		rgt[i] = 1;
		if(i<n && arr[i]<arr[i+1])
			rgt[i] = 1 + rgt[i+1];
	}
	int ans = 1;
	
	f(i, 1, n)
	{
		
		if(arr[i+1] - arr[i-1]>=2)
			ans = max(ans, lft[i-1] + 1 + rgt[i+1]);
		else
			ans = max(ans, 1+max(lft[i-1], rgt[i+1]));
	}
	cout << ans << "\n";
	return 0;
}


