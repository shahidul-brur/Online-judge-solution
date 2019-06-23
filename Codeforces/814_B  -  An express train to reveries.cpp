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
const int MX = 1005;
int a[MX], b[MX], ans[MX];
int fa[MX], fb[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        mem(fa, 0);
        mem(fb, 0);
        f(i, 1, n)
        {
            cin>>a[i];
            fa[a[i]]++;
        }
        f(i, 1, n)
        {
            cin>>b[i];
            fb[b[i]]++;
        }
        vi p1, p2;
        int v1, v2;
        f(i, 1, n)
        {
            if(fa[a[i]]>1)
                p1.pb(i);
            if(fb[b[i]]>1)
                p2.pb(i);
            if(fa[i]==0)
                v1 = i;
            if(fb[i]==0)
                v2 = i;
        }
        if(p2.sz==2)
        {
            f(i, 1, n)
            {
                if(fb[b[i]]==1)
                    ans[i] = b[i];
            }
            int x = p2[0];
            int y = p2[1];
            if(a[y]==v2 || b[x]==a[x])
            {
                ans[x] = b[x];
                ans[y] = v2;
            }
            else
            {
                ans[x] = v2;
                ans[y] = b[y];
            }
        }
        else
        {
            f(i, 1, n)
            {
                if(fa[a[i]]==1)
                    ans[i] = a[i];
            }
            int x = p1[0];
            int y = p1[1];
            if(v1==b[y] || b[x]==a[x])
            {
                ans[x] = a[x];
                ans[y] = v1;
            }
            else
            {
                ans[x] = v1;
                ans[y] = a[y];
            }
        }
        cout << ans[1];
        f(i, 2, n)
        {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}

