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
const int MAX = 1000005;
ll p, x, y;
int isTshirt(int s)
{
    if(s<y)
        return 0;
    int pt = (s/50)%475;
    f(i, 1, 25)
    {
        pt = (pt * 96 + 42) % 475;
        if(26 + pt==p)
            return 1;
    }
    return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(cin>>p>>x>>y)
    {
        int ts = isTshirt(x);
        if(ts && x>=y)
            cout << "0\n";
        else
        {
            ll ans = -1;
            for(int i = 1;i<=10000000;i++)
            {
                if(isTshirt(x-i*50))
                {
                    ans = 0;
                    break; 
                }
            }
            if(ans == 0)
            {
                cout << "0\n";
                
            }
            else
            {
                for(int i = 1;i<=10000000;i++)
                    if(isTshirt(x+i*50) || isTshirt(x-i*50))
                    {
                        ans = (i*50 + 50)/100;
                        break; 
                    }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}

