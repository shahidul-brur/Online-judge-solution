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


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	while(cin>>n>>m)
	{
		getchar();
		vector<string> col[m+1];
		f(i, 1, n)
		{
			char s[85];
			gets(s);
			string w;
			int col_id = 0;
			int l = strlen(s);
			for(int j = 0;j<=l;j++)
			{
				char ch = s[j];
				if(ch==',' || j==l)
				{
					col[++col_id].pb(w);
					w.clear();
				}
				else
					w+=ch;
			}
		}
		bool yes = 1;
		int r1, r2, c1, c2;
		f(i, 1, m-1)
		{
			if(yes==0)
				break;
			f(j, i+1, m)
			{
				
				if(yes==0)
					break;

				map<pair<string, string>, int> found_row;
				f(k, 0, n-1)
				{
					pair<string, string> cur = mp(col[i][k], col[j][k]);
					if(found_row.find(cur) == found_row.end())
						found_row[cur] = k+1;
					else
					{
						r1 = found_row[cur];
						r2 = k+1;
						c1 = i;
						c2 = j;
						yes = 0;
						break;
					}
				}
			}
		}
		if(yes)
			cout << "YES\n";
		else 
		{
			cout << "NO\n";
			cout << r1 << " " << r2 << "\n";
			cout << c1 << " " << c2 << "\n";
		}
	}
	return 0;
}

