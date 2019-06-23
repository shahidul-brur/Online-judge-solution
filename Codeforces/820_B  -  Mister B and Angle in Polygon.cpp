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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, a;
    while(cin>>n>>a)
    {
        long double angles = (n-2)*180.0;
        long double theta = (1.0*angles)/(n*1.0);
        long double part = (1.0*theta)/((n-2)*1.0);
        //cout << part << "#\n";
        int x=1, y=2, z, zz;
        int i = 1;
        long double mini = 1000000.0;
        for(zz = n;zz>=3;zz--)
        {
            long double cur = part*i;
            //cout << cur << "\n";
            if(fabs(a-cur)<mini)
            {
                mini = fabs(a-cur);
                z = zz;
            }
            i++;
        }
        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}

