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
const int MX = 100000;
int ans[MX+5];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	string L, R;
	L = "({[<";
	R = ")}]>";
	f(cas, 1, t)
	{
		string seq;
		cin>>seq;
		int n = seq.length();
		int invalid  = n+1;
		ans[n] = ans[n+1] = 0;
		stack<int> stk[4];
		F(i, n-1, 0)
		{
			f(j, 0, 3)
			{
				if(R[j]==seq[i])
				{
					ans[i] = 0;
					stk[j].push(i);
				}
				else if(L[j]==seq[i])
				{
					if(stk[j].empty())
					{
						ans[i] = 0;
						invalid = i;
						continue;
					}
					int pos = stk[j].top();
					stk[j].pop();
					int ok = 1;
					if(invalid<=pos)
						ok = 0;
					for(int k = 0;ok && k<4;k++)
						if(k!=j && !stk[k].empty() && stk[k].top()<=pos)
							ok = 0;
					if(!ok)
						ans[i] = 0, invalid = i;
					else ans[i] = ans[pos+1] + pos - i + 1;
				}
			}
		}
		cout << "Case " << cas << ":\n";
		f(i, 0, n-1)
		{
			cout << ans[i] << "\n";
		}
	}
	return 0;
}

