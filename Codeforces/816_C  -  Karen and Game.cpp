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
const int MX = 105;
int a[MX][MX], n, m, cnt;
int r[MX], c[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n>>m)
    {
        f(i, 1, n)
            f(j, 1, m)
                cin>>a[i][j];
                
        if(n<=m)
        {
            f(i, 1, n)
            {
                int mini = 10000;
                f(j, 1, m)
                {
                    mini  = min(mini, a[i][j]);
                }
                cnt+=mini;
                r[i] = mini;
                f(j, 1, m)
                {
                    a[i][j]-=mini;
                }
            }
            
            
            f(j, 1, m)
            {
                int mini = 10000;
                f(i, 1, n)
                {
                    mini  = min(mini, a[i][j]);
                }
                cnt+=mini;
                c[j] = mini;
                f(i, 1, n)
                {
                    a[i][j]-=mini;
                }
            }
            
            
            bool valid = 1;
            
            f(i, 1, n)
            {
                if(!valid)
                    break;
                f(j, 1, m)
                {
                    if(a[i][j]!=0)
                    {   
                        valid = 0;
                        break;
                    }
                }
            }
            
            
            if(!valid)
            {
                cout << "-1\n";
                continue;
            }
            
            
            cout << cnt << "\n";
            f(i, 1, n)
            {
                f(j, 1, r[i])
                    cout << "row " << i << "\n";
            }
            f(j, 1, m)
            {
                f(i, 1, c[j])
                    cout << "col " << j << "\n";
            }
        }
        else
        {
            f(j, 1, m)
            {
                int mini = 10000;
                f(i, 1, n)
                {
                    mini  = min(mini, a[i][j]);
                }
                cnt+=mini;
                c[j] = mini;
                f(i, 1, n)
                {
                    a[i][j]-=mini;
                }
            }
            
            f(i, 1, n)
            {
                int mini = 10000;
                f(j, 1, m)
                {
                    mini  = min(mini, a[i][j]);
                }
                cnt+=mini;
                r[i] = mini;
                f(j, 1, m)
                {
                    a[i][j]-=mini;
                }
            }
            
            bool valid = 1;
            
            f(i, 1, n)
            {
                if(!valid)
                    break;
                f(j, 1, m)
                {
                    if(a[i][j]!=0)
                    {   
                        valid = 0;
                        break;
                    }
                }
            }
            
            
            if(!valid)
            {
                cout << "-1\n";
                continue;
            }
            
            
            cout << cnt << "\n";
            f(i, 1, n)
            {
                f(j, 1, r[i])
                    cout << "row " << i << "\n";
            }
            f(j, 1, m)
            {
                f(i, 1, c[j])
                    cout << "col " << j << "\n";
            }
        }
    }
    return 0;
}

