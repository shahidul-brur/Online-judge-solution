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
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, cnt;
    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;
        a = min(a, b);
        b = max(a, b);
        
        int r = sqrt(a);
        cnt = 1;
        
        f(i, 2, r)
        {
            if(a%i==0 && b%i==0)
            {
                a/=i, b/=i, cnt++;
                int c = a/i;
                if(c!=i && b%c==0)
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}


