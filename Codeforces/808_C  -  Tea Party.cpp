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
const int MX = 105;
int n, tot, a[MX], c[MX];
ii cp[MX];
int main()
{
 //   freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n>>tot)
    {
        f(i, 1, n)
        {
            cin>>c[i];
            cp[i].ff = c[i];
            cp[i].ss = i;
        }
        sort(cp+1, cp+n+1);
        bool imp = 0;
        F(i, n, 1)
        {
            if(tot<(cp[i].ff+1)/2)
            {
                imp = 1;
                break;
            }
            a[cp[i].ss] = (cp[i].ff+1)/2;
            tot-=(cp[i].ff+1)/2;
        }
        if(imp) 
        {
            cout << "-1\n";
            continue;
        }
        
        F(i, n, 1)
        {
            if(tot==0) break;
            int rem = cp[i].ff - a[cp[i].ss];
            if(tot>=rem)
            {
                tot-=rem;
                a[cp[i].ss] = cp[i].ff;
            }
            else
            {
                a[cp[i].ss] += tot;
                tot = 0;
                break;
            }
        }
        f(i, 1, n)
        {
            if(i>1)
                cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}

