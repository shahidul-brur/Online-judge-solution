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
ll a[MX];
multiset<ll> s, s1;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        s.clear();
        ll tot=0LL, req;
        f(i, 1, n)
        {
            cin>>a[i];
            tot+=a[i];
            s.insert(a[i]);
            s1.insert(a[i]);
        }
        if(tot%2==1 || n==1)
            cout << "NO\n";
        else
        {
            req = (ll)tot/2LL;
            bool pos = 0;
            tot = 0LL;
            if(s.find(req)!=s.end())
                pos = 1;
            f(i, 1, n)
            {
                if(pos==1)
                    break;
                tot+=a[i];
                if(tot>req)
                    break;
                if(tot==req)
                {
                    pos = 1;
                    break;
                }
                multiset<ll>::iterator it = s.find(a[i]);
                if(it!=s.end())
                    s.erase(it);
                if(s.find(req-tot)!=s.end())
                {
                    pos = 1;
                    break;
                }
            }
            
            /* rev */
            tot = 0LL;
            if(s1.find(req)!=s1.end())
                pos = 1;
            F(i, n, 1)
            {
                if(pos==1)
                    break;
                tot+=a[i];
                if(tot>req)
                    break;
                if(tot==req)
                {
                    pos = 1;
                    break;
                }
                multiset<ll>::iterator it = s1.find(a[i]);
                if(it!=s1.end())
                    s1.erase(it);
                if(s1.find(req-tot)!=s1.end())
                {
                    pos = 1;
                    break;
                }
            }
            if(pos==1)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}


