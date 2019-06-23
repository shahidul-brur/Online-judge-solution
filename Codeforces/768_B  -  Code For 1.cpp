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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
#define per             pair<ll, pair<ll, ll> > 
ll n, l, r, p;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n>>l>>r)
    {
        if(n==0)
        {
            cout << "0\n";
        }
        else if(n==1)
        {
            if(l<=1 && r>=1)
                cout << "1\n";
            else cout << "0\n";
        }
        else
        {
            p = 0LL;
            ll inc = 1LL;
            ll x = n/2;
            while(x>0)
            {
                p+=inc;
                inc*=2*1LL;
                x/=2;
            }
            ll tot = p*2*1LL + 1;
            
            queue<per > q;
            q.push(mp(n, mp(1, tot)));
            ll ans = 0LL;
            while(!q.empty())
            {
                per fro = q.front(); q.pop();
                ll num = fro.first;
                
                ll b = fro.second.first;
                ll e = fro.second.second;
                ll pos = (b+e)/2;
                //cout << pos << "..\n";
                if(pos>=l && pos<=r)
                    ans+=(num%2);
                ll d = num/2;
                if(num==0)
                    break;
                if(pos<=l)
                {
                    q.push(mp(d, mp(pos+1, e)));
                }
                else if(pos>=r)
                {
                    q.push(mp(d, mp(b, pos-1)));
                }
                else 
                {
                    q.push(mp(d, mp(pos+1, e)));
                    q.push(mp(d, mp(b, pos-1)));
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

