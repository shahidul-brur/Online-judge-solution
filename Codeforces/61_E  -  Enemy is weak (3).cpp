#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)

#define SZ(x) (int)x.size()
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}
vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return w < p.w;   }
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=reset(N,pos);return N=Set(N,pos);}
void pbit(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}

int fx[]={0,0,1,-1,1,-1,1,-1};
int fy[]={-1,1,0,0,-1,-1,1,1};

#define mx 1000100
struct tree
{
	i64 s,f;
	tree(){s=0; f=0;}
	tree(i64 _s,i64 _f)
	{
		s=_s;
		f=_f;
	}
	
}m[mx*3];

void update(int node,int b,int e,int idx,i64 val)
{
	if(idx<b or idx>e) return;
	if(b==e)
	{
		m[node].f=1;
		m[node].s=val;
		return;
	}
	int Left=node<<1;
	int Right=Left+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,idx,val);
	update(Right,mid+1,e,idx,val);
	m[node].f=m[Left].f+m[Right].f;
	m[node].s=m[Left].s+m[Right].s;
}
tree query(int node,int b,int e,int i,int j)
{
	if(b>j or e<i) return tree(0,0);
	if(b>=i and e<=j)
	{
		
		return tree(m[node].s,m[node].f);
	}
	int Left=node<<1;
	int Right=Left+1;
	int mid=(b+e)>>1;
	tree p1=query(Left,b,mid,i,j);
	tree p2=query(Right,mid+1,e,i,j);
	
	return tree(p1.s+p2.s,p1.f+p2.f);
}
int a[mx],b[mx];
map<i64,i64>mp;
int main()
{
    //freopen("in.txt", "r", stdin);
	i64 n;
	while(cin>>n)
	{
	    memset(m, 0, sizeof m);
	    repl(i,n)
        {
            sdi(a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        
        i64 num=0;
        repl(i,n)
        {
            if(mp.find(b[i])==mp.end())
            mp[b[i]]=++num;
        }
        
        i64 ans=0;
        for(int i=n;i>=1;i--)
        {
            i64 x=mp[a[i]];
            
            tree get=query(1,1,num,1,x-1);
            ans+=get.s;
            update(1,1,num,x,get.f);
            
        }
        cout<<ans<<endl;
        mp.clear();
	}
}
