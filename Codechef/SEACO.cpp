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
ll ara[MX];
struct q
{
    int lft, rgt, typ;
    ll cnt;
}query[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        f(i, 0, n+1) ara[i] = 0LL;
        f(i, 0, q+1) query[i].cnt = 0LL;
        
        f(i, 1, q)
        {
            int tp;
            cin>>query[i].typ>>query[i].lft>>query[i].rgt;
        }
        query[q].cnt = 1LL;
        F(i, q, 1)
        {
            query[i].cnt=(query[i].cnt%mod + query[i+1].cnt%mod)%mod;
            if(query[i].typ==2)
                query[query[i].lft-1].cnt=(query[query[i].lft-1].cnt%mod + mod
                                        - query[i].cnt%mod)%mod,
                query[query[i].rgt].cnt=(query[query[i].rgt].cnt%mod 
                                        + query[i].cnt%mod)%mod;
            else
                ara[query[i].lft]=(ara[query[i].lft]%mod + query[i].cnt%mod)%mod,
                ara[query[i].rgt+1]=(ara[query[i].rgt+1]%mod + mod - query[i].cnt%mod)%mod;
        }
        f(i, 1, n)
        {
            ara[i]=(ara[i]%mod+ara[i-1]%mod)%mod;
            if(i>1)
                cout << " ";
            cout << ara[i];
        }
        cout << "\n";
    }
    return 0;
}
