/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               100002
#define inf             1e9
//int p[N], siz[N], cnt[N];
bool pr[N+5];
vi prime;
void sieve()
{
    pr[0] = pr[1] = 1;
    prime.pb(2);
    for(int i = 2;i<=N;i+=2)
    {
        //p[i] = 2;
        pr[i] = 1;
    }
    for(int i = 3;i<=N;i+=2)
    {
        
        if(pr[i]==0)
        {
            prime.pb(i);
            for(int j = i+i;j<=N;j+=i)
            {
                /*
                if(p[j]==0)
                    p[j] = i;
                */
                pr[j] = 1;
            }
        }
    }
}
/*
int fp(int u)
{
    if(p[u]==u)
        return u;
    return p[u] = fp(p[u]);
}
void make(int u, int v)
{
    int a = fp(u);
    int b = fp(v);
    
    if(a!=b)
    {
        if(a<b)
        {
            p[b] = a;
            siz[a]++;
        }
        else
        {
            p[a] = b;
            siz[b]++;
        }
    }
}
*/
ll h[N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    //cout << 
    int pm = prime.size();// << "\n";
    //cout << pm << "\n";
    int x, n;
    while(cin>>n)
    {
        if(n==1)
        {
            cout << "1\n";
            return 0;
        }
        ll mx = 1LL;
        rep(i, n)
        {
            cin>>x;
            h[x]++;
            //cnt[p[x]]++;
            //cout << p[x] << " " << cnt[p[x]] << "\n";
            //mx = max(mx, cnt[p[x]]);
        }
        for(int i = 0;i<pm;i++)
        {
            x = prime[i];
            ll c=0LL;
            for(int j = x;j<=N;j+=x)
            {
                c+=h[j];
            }
            mx = max(mx, c);
        }
        cout << mx << "\n";
    }
    return 0;
}

