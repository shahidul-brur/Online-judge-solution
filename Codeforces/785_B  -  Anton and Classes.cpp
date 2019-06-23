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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
#define N               200005
int l1[N], r1[N], l2[N], r2[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin>>n)
    {
        rep0(i, n)
        {
            cin>>r1[i]>>l2[i];
        }
        cin>>m;
        rep0(i, m)
        {
            cin>>r2[i]>>l1[i];
        }
        sort(l1, l1+m);
        sort(r2, r2+m);
        
        sort(l2, l2+n);
        sort(r1, r1+n);
        int ans = 0;
        if(r1[n-1]>l1[0])
            ans = max(ans, r1[n-1]-l1[0]);
        if(r2[m-1]>l2[0])
            ans = max(ans, r2[m-1]-l2[0]);
        
        cout << ans << "\n";
    }
    return 0;
}


