/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
map<ll, ll> cost;
void increase(ll v, ll u, ll w)
{
    while(v!=u)
    {
        cost[v]+=w;
        v/=2;
        if(u>v)
            swap(u, v);
    }
}
ll query(ll v, ll u)
{
    ll sum = 0LL;
    while(v!=u)
    {
        sum+=cost[v];
        v/=2;
        if(u>v)
            swap(u, v);
    }
    return sum;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    ll u, v, w;
    cin>>q;
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            cin>>v>>u>>w;
            if(u>v)
            swap(u, v);
            increase(v, u, w);
            
        }
        else
        {
            cin>>v>>u;
            if(u>v)
            swap(u, v);
            cout << query(v, u) << "\n";
        }
    }
    return 0;
}


