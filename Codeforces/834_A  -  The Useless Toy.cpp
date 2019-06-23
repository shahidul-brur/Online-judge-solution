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
map<char, int> maap;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    char s, e;
    int n;
    maap['^'] = 0;
    maap['>'] = 1;
    maap['v'] = 2;
    maap['<'] = 3;
    while(cin>>s>>e)
    {
        cin>>n;
//        cout << s << " " << e << " " << n << "\n";
        int p[6]; // up = 0, r = 1, d = 2, left = 3
        int q[6]; // up = 0, r = 1, d = 2, left = 3
        p[0] = maap[s];
        q[0] = maap[s];
        
        n %=4; 
        int lst = maap[e];
        // cw, ccw
        f(i, 1, 3)
        {
            p[i] = (p[i-1]+1) % 4;
            q[i] = (q[i-1]+4-1) % 4;
        }
        
        if((lst != p[n] && lst != q[n]) || (lst == p[n] && lst == q[n]))
            cout << "undefined\n";
        else
        {
            if(lst==p[n])
                cout << "cw\n";
            else cout << "ccw\n";
        }
    }
    return 0;
}


