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
    int n;
    cin>>n;
    int yes = 1;
    int p[5];
    p[0] = 1;
    p[1] = 2;
    f(i, 1, n)
    {
        int x;
        cin>>x;
        if(x!=p[0] && x!=p[1])
        {
            cout << "NO\n";
            return 0;
        }
        if(p[0]==x)
        {
            f(j, 1, 3)
            {
                if(j!=p[0] && j!=p[1])
                {
                    p[1] = j;
                    break;
                }
            }
        }
        else
        {
            f(j, 1, 3)
            {
                if(j!=p[0] && j!=p[1])
                {
                    p[0] = j;
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}

