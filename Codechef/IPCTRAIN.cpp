/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100002;
const int MOD = 1000000007;
const int INF = (int)1e9;
struct person
{
    int came, sadness, lecture;
}p[MX];
vi v[MX];
int d;
ll solve()
{
    ll sum = 0LL;
    priority_queue<pii> pq;
    f(i, 1, d)
    {
        int siz = v[i].sz;
        f(j, 0, siz-1)
        {
            int idx = v[i][j];
            pq.push({p[idx].sadness, -p[idx].lecture});
        }
        v[i].clear();
        if(pq.empty())
            continue;
        pii cur = pq.top();
        pq.pop();
        if(cur.ss==-1)
            sum+=cur.ff;
        else pq.push({cur.ff, cur.ss+1});
    }
    return sum;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        
        ll tot = 0LL;
        f(i, 1, n)
        {
            cin>>p[i].came>>p[i].lecture>>p[i].sadness;
            tot+=p[i].sadness;
            if(d-p[i].came+1<p[i].lecture)
                continue;
            v[p[i].came].pb(i);
        }
        ll sum = solve();
        cout << tot - sum << "\n";
    }
    return 0;
}


