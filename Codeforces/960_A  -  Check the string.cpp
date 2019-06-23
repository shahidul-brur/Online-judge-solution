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
bool tes(string s)
{
	int n  = s.length();
	int i = 0;
	while(i<n && s[i]=='a') i++;
	for(;i<n;i++)
	{
		if(s[i]=='a')
			return 0;
		if(s[i]=='c')
			break;
	}
	for(;i<n;i++)
	{
		if(s[i]=='b' || s[i]=='a')
			return 0;
	}
	return 1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int n;
	cin>>s;
	n = s.length();
	int a=0, b=0, c = 0;
	f(i, 0, n-1)
		if(s[i]=='a') a++;
		else if(s[i]=='b') b++;
		else if(s[i]=='c') c++;
	if(tes(s)==0 || a==0 || b==0 || c==0)
	{
		cout << "NO\n";
		return 0;
	}
	if(c==a || c==b)
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}


