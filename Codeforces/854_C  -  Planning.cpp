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
const int MX = 300005;
int cost[MX];
int ans[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin>>n>>k)
    {
        f(i, 1, n) cin>>cost[i];
        priority_queue< ii, vector<ii>> pq;
        f(i, 1, k+1)
        {
            pq.push(mp(cost[i], i));
        }
        int i = k+1;
        ll w = 0LL;
        
        while(!pq.empty())
        {
            ii cur = pq.top();
            int cst = cur.ff;
            int id = cur.ss;
            ans[id] = i;
            w+= 1LL*cst*1LL*(i - id);
            pq.pop();
            i++;
            if(i<=n)
            {
                pq.push(mp(cost[i], i));
            }
        }
        cout << w << "\n";
        cout << ans[1];
        f(j, 2, n)
        {
            cout << " " << ans[j];
        }
        cout << "\n";
    }
    return 0;
}

