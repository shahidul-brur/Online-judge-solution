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
const int MX = 10005;
const int bsiz = 105;
int n,a[MX], tb;
vi block[110];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m;
    cin>>n>>m;
    tb = n/bsiz;
    f(i, 0, n-1)
    {
        cin>>a[i];
        block[i/bsiz].pb(a[i]);
    }
    f(i, 0, tb-1)
    {
        sort(all(block[i]));
    }
    while(m--)
    {
        int l, r, x;
        cin>>l>>r>>x;
        --l;
        --r;
        --x;
        int lb = l/bsiz;
        int rb = r/bsiz;
        int leq = 0;
        if(lb==rb)
        {
            f(i, l, r)
            {
                if(a[i]<=a[x])
                    leq++;
            }
        }
        else
        {
            for(int i = l;i<(lb+1)*bsiz;i++)
                if(a[i]<=a[x])
                    leq++;
            for(int i=rb*bsiz;i<=r;i++)
                if(a[i]<=a[x])
                    leq++;
            for(int i = lb+1;i<rb;i++)
            {
                leq+=(upper_bound(all(block[i]), a[x]) - block[i].begin());
            }
        }
        if(leq==x-l+1)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
