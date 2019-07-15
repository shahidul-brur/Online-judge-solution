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
const int MX = 1000002;
int val[MX][2]; // 0 min, 1 max
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        f(i, 1, n)
        {
            int m;
            cin>>m;
            cin>>val[i][0];
            val[i][1] = val[i][0];
            f(j, 1, m-1)
            {
                int x;
                cin>>x;
                val[i][0] = min(val[i][0], x);
                val[i][1] = max(val[i][1], x);
            }
        }
        ll w1=0, w2 = 0;
        f(i, 1, n-1)
        {
            w1+=1LL*abs(val[i][0] - val[i+1][1])*i;
            w2+=1LL*abs(val[i][1] - val[i+1][0])*i;
        }
        cout << max(w1, w2) << "\n";
    }
    return 0;
}

