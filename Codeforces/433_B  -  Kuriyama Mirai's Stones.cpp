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
ll a[MX], s[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    f(i,1, n)
    {
        cin>>a[i];
        s[i] = a[i];
    }
    sort(s+1, s+n+1);
    a[0] = s[0] = 0LL;
    f(i,1,n)
    {
        a[i] +=a[i-1]; 
        s[i] +=s[i-1]; 
    }
    int q;
    cin>>q;
    while(q--)
    {
        int t, l, r;
        cin>>t>>l>>r;
        if(t==1) cout << a[r] - a[l-1] << "\n";
        else cout << s[r] - s[l-1] << "\n";
    }
    return 0;
}

