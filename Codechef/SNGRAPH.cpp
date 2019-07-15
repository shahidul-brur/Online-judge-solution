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

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 100005;
//vi g[MX];
int deg[MX], cnt[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, u, v;
    ll tot;
    cin>>t;
    while(t--)
    {
        mem(deg, 0);
        mem(cnt, 0);
        cin>>n>>m;
        while(m--)
        {
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            //cout << u << ", " << v << ": " << deg[u] << ", " << deg[v] << "\n";
        }
        
        f(i, 1, n)
        {
            cnt[deg[i]]++;
        }
        
        tot = 0LL;
        f(i, 0, n-1)
        {
            //cout << cnt[i] << " : ";
            if(tot<n-1)
                tot+=cnt[i];
            if(tot>n-1)
                tot = n-1;
            if(i>0)
                cout << " ";
            cout << tot;
            //cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

