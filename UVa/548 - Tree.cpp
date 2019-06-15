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
int I() {int x; scanf("%d", &x); return x;}
ll LL() {ll x; scanf("%lld", &x); return x;}
double D() {double x; scanf("%lf", &x); return x;}

//              0123456789
const int MOD = 1000000007;
const int MX  = 100002;
const int INF = 2147483640;

char line[MX];
vi in, post;
int root, siz;
struct node{
	int lft, rgt;
}tree[MX];
int pos_in[MX];
int mini, ans;
int build(int li, int ri, int lp, int rp, int cost)
{
	if(li>ri || lp>rp) return -1;
	int node = post[rp];
	if(li==ri)
	{
		cost+=node;
		if(cost<mini || (cost==mini && in[li]<ans))
		{

			mini = cost;
			ans = in[li];
		}
		return node;
	}
	int pi = pos_in[node];
	tree[node].lft = build(li, pi-1, lp, lp+pi-1-li, cost+node);
	tree[node].rgt = build(pi+1, ri, lp+pi-li, rp-1, cost+node);
	return node;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	while(gets(line))
	{
		in.clear();
		post.clear();
		stringstream temp(line);
		int x;
		while(temp>>x) in.pb(x);
		gets(line);
		stringstream temp2(line);
		while(temp2>>x) post.pb(x);
		siz = post.sz;
		for(int i=0;i<siz;i++)
			pos_in[in[i]] = i;
		mini = INF;
		ans = INF;
		root = build(0, siz-1, 0, siz-1, 0);
		cout << ans << "\n";
	}
	return 0;
}

