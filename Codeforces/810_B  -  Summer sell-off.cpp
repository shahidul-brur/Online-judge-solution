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
int p[MX], c[MX], ext[MX], n, f;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll cnt;
    while(cin>>n>>f)
    {
        cnt = 0LL;
        f(i, 0, n-1)
        {
            cin>>p[i]>>c[i];
            cnt+=min(1LL*p[i], 1LL*c[i]);
            ext[i] = min(2LL*p[i], 1LL*c[i]) - min(1LL*p[i], 1LL*c[i]);
        }
        sort(ext, ext+n);
        for(int i = n-1, j = 1;i>=0 && j<=f;i--, j++)
        {
            cnt+= 1LL * ext[i];
        }
        cout << cnt << "\n";
    }
    return 0;
}

