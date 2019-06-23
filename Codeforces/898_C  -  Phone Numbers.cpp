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
map<string, int> nameId;
string f_name[100];
set<string> phone_num[1000];
vector<string> ans[1000];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int id = 0;
	f(i, 1, n)
	{
		string name;
		cin>>name;
		if(nameId.find(name) == nameId.end())
		{
			nameId[name] = ++id;
			f_name[id] = name;
		}
		int num;
		cin>>num;
		int cur = nameId[name];
		f(j, 1, num)
		{
			string ph;
			cin>>ph;
			phone_num[cur].insert(ph);
		}
	}
	cout << id << "\n";
	for(int i = 1;i<=id;i++)
	{
		for(auto now:phone_num[i])
		{
			bool ok = 1;
			//cout << now << " -> \n====\n";
			for(auto ph:phone_num[i])
			{
				if(now==ph)
					continue;
				int ln = ph.length();
				string suf = "";
				
				for(int k = ln-1;k>=0;k--)
				{
					suf+=ph[k];
					//cout << suf << ", ";
					string ekhon = suf;
					reverse(all(ekhon));
					if(ekhon == now)
					{
						ok = 0;
						break;
					}
				}
			}
			//cout << "\n======\n";
			if(ok)
				ans[i].pb(now);
		}
		int len = ans[i].size();
		cout << f_name[i] << " " << len;
		for(auto p:ans[i])
			cout << " " << p;
		cout << "\n";
	}
	return 0;
}

