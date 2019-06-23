/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, k) for(int i=0;i<k;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 210
#define inf 1e9
int l[1005], r[1005], u[1005], d[1005];
int s[1005][1005];
bool fc[1005], fr[1005];
int main()
{
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    
    cin>>n>>m;
    rep(i, n)
        rep(j, m)
            cin>>s[i][j];
    rep(i, n)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]==1)
            {
                l[i] = j;
                fr[i] = 1;
                break;
            }
        }
        for(int j=m-1;j>=0;j--)
        {
            if(s[i][j]==1)
            {
                r[i] = j;
                fr[i] = 1;
                break;
            }
        }
        //cout << l[i] << "," << r[i] << "\n";
    }
    rep(j, m)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i][j]==1)
            {
                u[j] = i;
                fc[j] = 1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i][j]==1)
            {
                d[j] = i;
                fc[j] = 1;
                break;
            }
        }
       // cout << u[j] << "," << d[j] << "\n";
    }
    int cnt = 0;
    rep(i, n)
    {
        for(int j=0;j<m;j++)
        {
            //cout << s[i][j];
            if(s[i][j]==0)
            {
                //cout << "\#";
                //cout << i << " " << j << " => ";
                if(fr[i]!=0 && j>l[i])
                {
                   // cout << "l, ";
                    cnt++;
                }
                if(fr[i]!=0 && j<r[i])
                {
                    cnt++;
                    //cout << "r, ";
                }
                if(fc[j]!=0 && i<d[j])
                {
                    cnt++;
                    //cout << "u, ";
                }
                if(fc[j]!=0 && i>u[j])
                {
                    cnt++;
                    //cout << "d, ";
                }
                //cout << "\n";
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
