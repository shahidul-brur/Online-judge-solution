/************************************************************
* Problem:   
* Link:                                                     
* Verdict:  Accepted 
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
int button[12], dis[10002], current, target, b;
int bfs()
{
    if(current==target)
        return 0;
    queue<int> q;
    dis[current]=0;
    q.push(current);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0;i<b;i++)
        {
            int v = (u + button[i])%10000;
            if(dis[v]==-1)
            {
                dis[v] = dis[u] + 1;
                if(v==target)
                    return dis[v];
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    fast;
    in;
    //out;
    int i, ans, cas=1;
    while(cin>>current>>target>>b)
    {
        if(current ==0 && target==0 && b==0)
            break;
        for(i=0;i<b;i++)
        {
            cin>>button[i];
        }
        for(i=0;i<=10000;i++)
            dis[i]=-1;
        ans = bfs();
        
        if(ans==-1)
            cout<< "Case " << cas++ << ": Permanently Locked" << "\n";
        else cout<< "Case " << cas++ << ": " << ans << "\n";
    }
    return 0;
}