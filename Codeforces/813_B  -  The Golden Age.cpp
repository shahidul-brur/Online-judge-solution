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
vector< long long> un;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
     long long x, y, l, r, a;
    vector< long long> p, q;
    cin>>x>>y>>l>>r;
    p.pb(1LL);
    q.pb(1LL);
     long long b=1LL;
    while(b<=r)
    {
        if(b>r/x)
            break;
        b *=x;
        p.pb(b);
    }
    b=1LL;
    while(b<=r)
    {
        if(b>r/y)
            break;
        b *=y;
        q.pb(b);
    }
    
    for(int i = 0;i<p.size();i++)
    {
        for(int j = 0;j<q.size();j++)
        {
            if(q[j]+p[i]>r)
                break;
            //cout << b+e << "\n";
            if(p[i]+q[j]>=l && p[i]+q[j]<=r)
                un.pb(p[i]+q[j]);
        }
    }
    sort(all(un));
     long long ans = 0LL;
    int s = un.size();
    f(i, 0, s-2)
    {
        //cout << un[i] << " " << un[i+1] << "\n";
        if(un[i+1]-un[i]-1>ans)
            ans = un[i+1]-un[i]-1;
    }
    
    if(s>0)
    {
        if(r-un[s-1]>ans)
            ans = r-un[s-1];
        if(un[0]-l>ans)
            ans = un[0]-l;
    }
    if(s==0)
        ans = r-l+1;
    cout << ans << "\n";
    return 0;
}
