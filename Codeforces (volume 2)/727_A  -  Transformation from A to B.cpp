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
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
map<ll, ll> id;
ll d[200005];
ll par[200005], n;
ll bfs(ll u, ll v)
{
    queue<ll> q;
    q.push(u);
    d[id[u]] = 1;
    ll k = 0;
    while(!q.empty())
    {
//        k++;
//        if(k>10)
//            break;
        ll fr = q.front(); q.pop();
       // cout << fr << ":-> ";
        ll nxt = 2*fr;
        //cout << nxt << ", ";
        if(nxt<=v && !id[nxt])
        {
            id[nxt] = n++;
            d[id[nxt]] = d[id[fr]]+1;
            par[id[nxt]] = fr;
            if(nxt==v)
                return d[id[nxt]];
            q.push(nxt);
        }
        nxt = 10*fr+1;
        //cout << nxt << "\n";
        if(nxt<=v && !id[nxt])
        {
            id[nxt] = n++;
            d[id[nxt]] = d[id[fr]]+1;
            par[id[nxt]] = id[fr];
            par[id[nxt]] = fr;
            if(nxt==v)
                return d[id[nxt]];
            q.push(nxt);
        }
    }
    return -1;
    
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a, b;
    while(cin>>a>>b)
   {
        id[a] = 1;
        n = 2;
        ll dis=bfs(a, b);
        
        if(dis==-1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << dis << "\n";
            vi v;
            v.pb(b);
            while(1)
            {
                ll p = par[id[b]];
               // cout << p <<"\n";
                v.pb(p);
                if(p==a)
                    break;
                b = p;
            }
            Fr(i, dis-1, 0)
                cout << v[i] << " ";
        }
        
        id.clear();
   }
    return 0;
}


