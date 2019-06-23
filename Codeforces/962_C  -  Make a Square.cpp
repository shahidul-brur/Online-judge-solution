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
map<int, bool> isSq;
set<int> nums;
string s;
int len;
void fn(int n, int pos)
{
	int cur = n*10 + s[pos] - '0';
	nums.insert(cur);
	if(pos==len-1) return;
	fn(n, pos+1);
	fn(cur, pos+1);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r = sqrt(2000000000);
	f(i, 1, r)
	{
		isSq[i*i] = 1;
	}
	cin>>s;
	
	if(isSq.find(atoi(s.c_str())) != isSq.end())
	{
		cout << "0\n";
		return 0;
	}
	len = s.length();
	for(int i = 0;i<len;i++)
	{
		if(s[i] == '0') continue;
		fn(0, i);
	}
	for(auto it = nums.rbegin();it!=nums.rend();it++)
	{
		if(isSq.find(*it) != isSq.end())
		{
			int siz = 0;
			int tp = *it;
			while(tp>0)
			{
				siz++;
				tp/=10;
			}
			cout << len - siz << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}