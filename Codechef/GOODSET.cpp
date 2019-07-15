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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, vis[550], c = 0;
    int ans[102];
    mem(vis, 0);
    f(k, 0, 99)
    {
        //cout << k << ": ";
        f(i, 1, 500)
        {
            if(!vis[i])
            {
               // cout << i << "\n";
                ans[k] = i;
                vis[i] = 1;
                f(j, 0, k-1)
                    vis[i+ans[j]] = 1;
                break;
            }
        }
        //cout << ans[k] << ", ";
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout << ans[0];
        f(i, 1, n-1)
        {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}


