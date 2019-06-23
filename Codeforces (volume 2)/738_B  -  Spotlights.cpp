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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, i, j;
    
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>s[i][j];
    
    //Calculate left and right boundary for each row
    for(i=1;i<=n;i++)
    {
        //Calculate left
        for(j=1;j<=m;j++)
            if(s[i][j]==1)
            {
                l[i] = j;
                break;
            }
        
        //Calculate right
        for(int j=m;j>=1;j--)
            if(s[i][j]==1)
            {
                r[i] = j;
                break;
            }
    }
    
    //Calculate up and down boundary for each column
    for(int j=1;j<=m;j++)
    {
        //Calculate up
        for(int i=1;i<=n;i++)
            if(s[i][j]==1)
            {
                u[j] = i;
                break;
            }
        
        //Calculate up
        for(int i=n;i>=1;i--)
            if(s[i][j]==1)
            {
                d[j] = i;
                break;
            }
    }
    
    //Calculate ans for each cell
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==0)
            {
                if(l[i]!=0 && j>l[i])
                    cnt++;
                if(r[i]!=0 && j<r[i])
                    cnt++;
                if(d[j]!=0 && i<d[j])
                    cnt++;
                if(u[j]!=0 && i>u[j])
                    cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
