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
using namespace std;

#define ll	   long long
#define ull	  unsinged long long
#define vi	   vector<int>
#define vll	  vector<ll>
#define ii	   pair<int, int>
#define vii	  vector<pair<int, int> >
#define vs	   vector<string>
#define vd	   vector<double>
#define mii	   map<int, int>
#define mli	   map<ll, int>
#define msi	   map<string, int>

#define pb			  push_back
#define debug(x)		cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, a, b)	  for(int i=(a);i>=(b);i--)
#define pi			  acos(-1.0)
#define eps			 1e-6
#define mem(a, b)	   memset(a, b, sizeof(a))
#define mod			 1000000007
#define inf			 1e9
//			 0123456789
const int MX = 200005;
int arr[MX];
vector<int> sq;
vector<int> nsq;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, zero = 0;
	cin>>n;
	f(i, 1, n)
	{
		cin>>arr[i];
		int root = sqrt(arr[i]);
		if(arr[i]==0)
			zero++;
		if(root * root == arr[i])
			sq.pb(arr[i]);
		else nsq.pb(arr[i]);
	}
	int sq_n = sq.size();
	int nsq_n = nsq.size();
	if(sq_n>nsq_n)
	{
		int need = sq_n - n/2;
		if(sq_n - zero>=need)
			cout << sq_n - n/2 << "\n";
		else
		{
			int holo = sq_n - zero;
			int aro = (need - holo)*2;
			cout << holo + aro << "\n";
		}
	}
	else if(sq_n == nsq_n){
		cout << "0\n";
	}
	else
	{
		vector<int> mov;
		for(int a:nsq)
		{
			int r = sqrt(a);
			int s = r*r;
			int s2 = (r+1)*(r+1);
			int m = min(abs(a-s), abs(s2-a));
			mov.pb(m);
		}
		sort(all(mov));
		int need = nsq_n - n/2;
		ll cnt = 0LL;
		f(i, 0, need-1)
		{
			cnt += 1LL*mov[i];
		}
		cout << cnt << "\n";
	}
	return 0;
}

