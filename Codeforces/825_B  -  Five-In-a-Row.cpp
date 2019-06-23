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
char s[12][12];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    f(i, 0, 9)
        cin>>s[i];
    f(i, 0, 9)
    {
        f(j, 0, 9)
        {
            int x = 0, emp=0;
            f(k, 0, 4)
            {
                if(j+k>=10)
                    break;
                if(s[i][j+k]=='X')
                    x++;
                else if(s[i][j+k]=='.')
                    emp++;
            }
            if(x==4 && emp==1)
            {
                cout << "YES\n";
                return 0;
            }
            x = emp = 0;
            f(k, 0, 4)
            {
                if(i+k>=10 || j+k>=10)
                    break;
                if(s[i+k][j+k]=='X')
                    x++;
                else if(s[i+k][j+k]=='.')
                    emp++;
            }
            if(x==4 && emp==1)
            {
                cout << "YES\n";
                return 0;
            }
            x = emp = 0;
            f(k, 0, 4)
            {
                if(i-k<0 || j+k>=10)
                    break;
                if(s[i-k][j+k]=='X')
                    x++;
                else if(s[i-k][j+k]=='.')
                    emp++;
            }
            if(x==4 && emp==1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    f(j, 0, 9)
    {
        
        f(i, 0, 9)
        {
            int x = 0, emp=0;
            f(k, i, i+4)
            {
                if(s[k][j]=='X')
                    x++;
                else if(s[k][j]=='.')
                    emp++;
            }
            if(x==4 && emp==1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}


