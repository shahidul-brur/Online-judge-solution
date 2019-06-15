//Accepted

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000
bool prime[46500];
vector<ll> p;
int sz;
ll mx, mn, b1, b2, s1, s2;

void sieve(ll n)
{
    prime[0] = prime[1] = 1;
    ll r = sqrt(n);
    p.pb(2);
    for(ll i=3;i<=n;i+=2)
    {
        if(!prime[i])
        {
            p.pb(i);
            for(ll j=i+i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
void segSieve(ll a, ll b)
{
    if(a<=1)
        a=2;
    ll r = sqrt(b);
    bool mark[1000005];
    mem(mark, 0);
    for(int i=0;i<sz && p[i]<=r;i++)
    {
        ll j = p[i]*p[i];
        if(j<a)
            j = ((a+p[i]-1)/p[i])*p[i];
        for(;j<=b;j+=p[i])
            mark[j-a] = 1;
    }

    mx = -1, mn = 10000000;
    ll pre, i;
    for(i=a;i<=b;i++)
    {
        if(mark[i-a]==0)
        {
            pre = i;
            break;
        }
    }

    for(i=i+1;i<=b;i++)
    {
        if(mark[i-a]==0)
        {
            if(i-pre>mx)
            {
                b1=pre;
                b2=i;
                mx = i-pre;
            }
            if(i-pre<mn)
            {
                s1=pre;
                s2=i;
                mn = i-pre;
            }
            pre = i;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll a, b;

    sieve(46400);
    sz = p.size();
    while(cin>>a>>b)
    {
        segSieve(a, b);
        if(mx==-1 && mn==10000000)
            cout << "There are no adjacent primes.\n";
        else
        {
            cout << s1 << "," << s2 << " are closest, " << b1 << "," << b2 << " are most distant.\n";
        }
    }
    return 0;
}

