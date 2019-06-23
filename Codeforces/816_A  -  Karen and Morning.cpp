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
int rev(int num)
{
    int r = num%10;
    num/=10;
    return r * 10 + num;
}
bool isPal(int minute)
{
    int h = minute/60;
    int m = minute%60;
    if(h%24==0)
        h = 0;
    if(m==rev(h))
        return 1;
    return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h, m, cur, tim;
    while(scanf("%d:%d", &h, &m)!=EOF)
    {
        if(h==0 && m==0)
        {
            cout << "0\n";
            continue;
        }
        tim = h*60 + m;
        cur = tim;
        int ans = 0;
        while(!isPal(cur))
        {
            ans++;
            cur++;
        }
        cout << ans << "\n";
    }
    return 0;
}
