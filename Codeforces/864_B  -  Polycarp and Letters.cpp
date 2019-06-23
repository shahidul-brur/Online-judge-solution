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
const int MX = 100000;
string s;
int n;
bool vis[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n>>s)
    {
        mem(vis, 0);
        int cnt = 0, v = 1;
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            if(isupper(s[i]))
            {
                cnt = 0;
                mem(vis, 0);
//                if(v==0)
//                {
//                    mem(vis, 0);
//                    v = 1;
//                }
                continue;
            }
            if(islower(s[i]) && !vis[s[i] - 'a'])
            {
                cnt++;
                vis[s[i] - 'a'] = 1;
                maxi = max(maxi, cnt);
                //cout << i << " " << maxi << "\n";
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}

