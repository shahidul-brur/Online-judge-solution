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
int a[1026];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, x, num;
	cin>>n>>k>>x;
	f(i, 1, n)
	{
		cin>>num;
		a[num]++;
	}
	f(i, 1, k)
	{
		int c = 1;
		vi inc(1025, 0);
		f(j, 0, 1023)
		{
			if(a[j]==0) continue;
			int cnt;
			//cout << i << ": " << j << " => " << a[j] << "\n";
			if(c==1)
			{
				cnt = (a[j]+1)/2;
			}
			else 
			{
				cnt = a[j]/2;
			}
			//cout << cnt << " ";
			c+=a[j];
			c%=2;
			a[j]-=cnt;
			int val = j^x;
			inc[val]+=cnt;
			//cout << a[j] << ", " << val << "\n";
		}
		f(j, 0, 1023)
			a[j]+=inc[j];
	}
	F(i, 1023, 0) if(a[i]>0) {cout << i << " "; break;}
	f(i, 0, 1023) if(a[i]>0) {cout << i << "\n"; break;}
	return 0;
}


