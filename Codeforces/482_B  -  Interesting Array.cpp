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
int bit[MAX][32];
int arr[MAX][32];
int cum[MAX][32];
int l[MAX], r[MAX], q[MAX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	f(i, 1, m)
	{
		cin>>l[i]>>r[i]>>q[i];
		for(int j = 0;j<=30;j++){
			if(q[i] & (1<<j)){
				arr[l[i]][j]+=1;
				arr[r[i]+1][j]-=1;
			}
		}
	}
	f(i, 1, n)
	{
		//cout << i << " :\n========\n";
		f(j, 0, 30)
		{
			arr[i][j]+=arr[i-1][j];
			if(arr[i][j]>0) bit[i][j] = 1;
			cum[i][j] = bit[i][j] + cum[i-1][j];
			//cout << j << " => " << bit[i][j] << " " << cum[i][j] << "\n";
		}
	}
	bool ok = 1;
	f(i, 1, m)
	{
		//cout << i << ":\n=====\n";
		f(j, 0, 3)
		{
			int b = (q[i] & (1<<j))>0;
			//cout << j << ", " << b << ": " << r[i] - l[i] + 1 << " " << cum[r[i]][j] << " #\n";
			if(b == 0 && cum[r[i]][j] - cum[l[i]-1][j]== r[i] - l[i] + 1)
			{
				ok = 0;
				break;
			}
			else if( b == 1  && cum[r[i]][j] - cum[l[i]-1][j] != r[i] - l[i] + 1)
			{
				ok = 0;
				break;
			}
		}
		if(!ok) break;
	}
	if(!ok) cout << "NO\n";
	else
	{
		cout << "YES\n";
		f(i, 1, n)
		{
			int cur = 0;
			f(j, 0, 30)
			{
				if(bit[i][j]==1)
					cur += (1<<j);
			}
			cout << cur << " ";
		}
	}
	return 0;
}


