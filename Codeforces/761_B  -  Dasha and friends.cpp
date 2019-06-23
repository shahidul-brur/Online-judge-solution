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
int a[200], b[200], pa[200], pb[200];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, n, x;
    while(cin>>n>>l)
    {
        mem(a, 0);
        mem(b, 0);
        rep(i, n)
            cin>>x, a[x] = 1, pa[i] = x;
        rep(i, n)
            cin>>x, b[x] = 1, pb[i] = x;
        bool posi = 0;
        for(int p = 0;p<=l;p++)
        {
            int cnt1=0, cnt2 = 0, nxt;
            bool vis1[200], vis2[200];
            mem(vis1, 0);
            mem(vis2, 0);
            rep(i, n)
            {
                x = pb[i];
                nxt = x - p;
                if(nxt<0)
                    nxt+=l;
                if(a[nxt]==1 && vis1[nxt]==0)
                {
                    cnt1++;
                    vis1[nxt] = 1;
                }
                
                nxt = x + p;
                if(nxt>=l)
                    nxt-=l;
                if(a[nxt]==1 && vis2[nxt]==0)
                {
                    cnt2++;
                    vis2[nxt] = 1;
                }
            }
            if(cnt1==n || cnt2==n)
            {
                posi = 1;
                break;
            }
        }
        if(posi)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

