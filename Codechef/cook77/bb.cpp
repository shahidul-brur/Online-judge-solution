#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
 
#define rep(i,x,y) for(i=x;i<=y;i++)
#define _rep(i,x,y) for(i=x;i>=y;i--)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
#define ALL(x,S) for(x=S.begin();x!=S.end();x++)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second
#define upmin(x,y) x=min(x,y)
#define upmax(x,y) x=max(x,y)
 
typedef long long ll;
typedef long double real;
void read(int&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}
 
const int dep=20;
const int D=dep*100010;
int T,n,i,j,K,l,p,a[100010],sum[100010];
 
int ch[D][2],s[D],tot,ro,zz;ll ans;
 
void ins(int&i,int d,int key)
{
    if(i==0)
        i=++tot,s[i]=ch[i][0]=ch[i][1]=0;
    
    s[i]++;
    if(d>=0)
    if(key<<d&1)
        ins(ch[i][1],d-1,key);
    else 
        ins(ch[i][0],d-1,key);
}
 
int find(int i,int d,int k)
{
    if(i==0)return 0;
    if(k<0)return 0;
    if((1<<(d+1))-1>=k)return s[i];
    return find(ch[i][0],d-1,k-((zz>>d&1)<<d))+find(ch[i][1],d-1,k-(((zz>>d&1)^1)<<d));
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    for(read(T);T;T--)
    {
        read(n);read(K);K--;
        rep(i,1,n)
            read(a[i]);
        rep(i,1,n)
            sum[i]=sum[i-1]^a[i];
        
        tot=0;
        ro=0;
        ins(ro,dep,0);
        ans=0;
        rep(i,1,n)
        {
            zz=sum[i];
            ans+=find(ro,dep,K);
            ins(ro,dep,zz);
        }
        cout<<ans<<endl;
    }
    return 0;
}
