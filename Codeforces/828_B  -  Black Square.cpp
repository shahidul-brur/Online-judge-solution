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
char s[105][105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, up, dwn, lft, rgt;
    while(cin>>n>>m)
    {
        f(i, 0, n-1)
            cin>>s[i];
        int b = 0;
        lft = m+5;
        rgt = -1;
        up = n+5;
        dwn = -1;
        f(i, 0, n-1)
        {
            f(j, 0, m-1)
            {
                if(s[i][j]=='B')
                {
                    b++;
                    lft = min(lft,j);
                    rgt = max(rgt, j);
                    up = min(up, i);
                    dwn = max(dwn, i);
                }
            }
        }
        if(b==0)
            cout << "1\n";
        else
        {
            int sq = max(dwn-up+1, rgt-lft+1);
            if(sq>min(n,m))
                cout << "-1\n";
            else cout << sq*sq-b << "\n";
        }
    }
    return 0;
}


