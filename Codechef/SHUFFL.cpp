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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m, x, y;
        cin>>m>>x>>y;
        vi v;
        f(i, 1, m) v.pb(i);
        int s = v.size();
        while(s>2){
            vi tem;
            int idx = ((s/2)*x/y);
            for(int i = 0, p = 0;i<s;i+=2, p++){
                if(p!=idx)
                    tem.pb(v[i]);
            }
            for(int i = 1, p=0;i<s;i+=2, p++){
                if(p!=idx)
                    tem.pb(v[i]);
            }
            v.clear();
            v = tem;
            s = v.size();
        }
        int ans  = v[0];
        f(i, 1, s-1){
            ans^=v[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

