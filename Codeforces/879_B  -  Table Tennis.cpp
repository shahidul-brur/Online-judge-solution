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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
//             0123456789
const int MX = 100000;
int ini[505];
int cnt[505];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll k;
    int mx = 0;
    cin>>n>>k;
    f(i, 1, n)
    {
        cin>>ini[i];
        mx = max(mx, ini[i]);
    }
    
    int p = ini[1];
    f(i, 2, n)
    {
        if(ini[i]==mx)
        {
            cout << mx << "\n";
            return 0;
        }
        if(p>ini[i])
        {
            cnt[p]++;
        }
        else
        {
            p = ini[i];
            cnt[p]++;
        }
        if(cnt[p]==k)
        {
            cout << p << "\n";
            return 0;
        }
    }
    cout << mx << "\n";
    return 0;
}

