/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
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
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define N               10005
#define inf             1e9
int n, m, a, b, c;
map<string, int> maap1, maap2;
//vector<string> s1, s2;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    string s;
    rep(i, n)
    {
        cin>>s;
        //s1.pb(s);
        if(maap1[s]==0)
            maap1[s] = ++a;
    }
    rep(i, m)
    {
        cin>>s;
        //s2.pb(s);
        if(maap2[s]==0)
            maap2[s] = ++b;
        if(maap1[s]!=0)
            c++;
    }
    a-=c;
    b-=c;
    a+=(c%2);
    if(a>b)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

