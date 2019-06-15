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
//             0123456789
const int MX = 1000005;
int z[MX];
int Z_Algo(string s)
{
    int n = s.length();
    z[0] = 0;
    for(int i = 1, l  = 0, r = 0;i<n;i++)
    {
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        else z[i] = 0;
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if(n%i==0 && i+z[i]==n)
            return i;
        if(i+z[i]-1>r) l = i, r = i+z[i]-1;
    }
    return n;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cout << Z_Algo(s) << "\n";
        if(t>0)
            cout << "\n";
    }
    return 0;
}

