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
const int MX = 2502;
bool ase[MX][MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k, len, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        f(i, 0, n-1)
        {
            cin>>len;
            mem(ase[i], 0);
            f(j, 0, len-1)
            {
                cin>>x;
                ase[i][x] = 1;
            }
        }
        
        int ans =  0;
        f(i, 0, n-2)
        {
            f(j, i+1, n-1)
            {
                bool yes = 1;
                f(l, 1, k)
                {
                    if(ase[i][l] == 0 && ase[j][l]==0)
                    {
                        yes = 0;
                        break;
                    }
                        
                }
                if(yes)
                    ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

