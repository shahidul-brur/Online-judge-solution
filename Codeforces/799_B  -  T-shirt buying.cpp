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
const int MX = 200005;
int bac[MX], fron[MX], pric[MX], n, m;
int b[5];
bool sold[MX];
vii pr[4];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n)
    {
        f(i, 1, n) cin>>pric[i];
        f(i, 1, n) cin>>bac[i];
        f(i, 1, n) cin>>fron[i];
        f(i, 1, n)
        {
            pr[bac[i]].pb(mp(pric[i], i));
            pr[fron[i]].pb(mp(pric[i], i));
        }
        f(i, 1, 3)
        {
            sort(all(pr[i]));
//            cout << i << ": ";
//            f(j, 0, pr[i].sz-1)
//                cout << pr[i][j].ff << " ";
//            cout << "\n";
        }
        
        cin>>m;
        mem(b, 0);
        mem(sold, 0);
        f(q, 1, m)
        {
            int fav;
            cin>>fav;
            int s = pr[fav].sz;
            int ans = -1;
            if(b[fav]>=s)
            {
                if(q>1) cout << " ";
                cout << "-1\n";
                continue;
            }
            f(i, b[fav], s-1)
            {
                if(sold[pr[fav][i].ss]==0)
                {
                    ans = pr[fav][i].ff;
                    sold[pr[fav][i].ss] = 1;
                    b[fav] = i+1;
                    break;
                }
            }
            if(ans==-1)
                b[fav] = s;
            if(q>1) cout << " ";
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}

