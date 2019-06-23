#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9
#define FI freopen("in.txt","r",stdin)

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 100000
#define INF INT_MAX
#define mod 1000000007

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL bigmod(LL b,LL p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;
    my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

LL ara[Max],L[Max],n,bra[Max],N,cnt[Max];
//LL par[Max];

LL LIS()
{
    LL i,j;
    L[1] = 1;
    for(i=2;i<=N;i++)
    {
        L[i] = 1;
        for(j=1;j<i;j++)
        {
            if(ara[i] >= ara[j] && L[i] <= L[j])
            {
                L[i] = L[j] + 1;
                //par[i] = j;
            }
        }
    }
    LL mx = 0;
    //LL idx;
    for(i=1;i<=N;i++)
    {
        if(L[i] > mx)
        {
            mx = L[i];
            //idx = i;
        }
    }
    return mx;
}

int main()
{
    //FI;
    LL i,j,t;
    sll(n,t);
    rep(i,n)
    {
        sl(bra[i]);
        cnt[ bra[i] ]++;
    }
    LL d = min(n,t);
    N = n * d;
    Rep(j,d)
    {
        rep(i,n)
        {
            ara[j*n+i] = bra[i];
            //printf("%lld ",bra[i]);
        }
    }
    LL my = LIS();
    if(t > d)
    {
        LL mx = 0;
        rep(i,n)
        {
            if(cnt[ bra[i] ] > mx)mx = cnt[ bra[i] ];
        }
        my += (t - d) * mx;
    }
    pl(my);NL;
    return 0;
}
