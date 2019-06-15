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
bool prime[10000005];
vector<ll> p;
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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n, i, j;

    sieve(10000001);
    int sz = p.size();

    while(cin>>n)
    {
        if(n==0)
            break;
        n = llabs(n);
        ll mx = -1;

        ll cnt =0;
        if(n>1)
        {
            for(i=0;i<sz && p[i]*p[i]<=n;i++)
            {
                if(n%p[i]==0)
                {
                    cnt++;
                    mx = p[i];
                    while(n%p[i]==0)
                    {
                        n/=p[i];
                    }
                }
            }
            if(n>1) //means n is prime !
                mx = n, cnt++;
            if(cnt<=1)
                mx=-1;
        }
        cout << mx << "\n";
    }
    return 0;
}
