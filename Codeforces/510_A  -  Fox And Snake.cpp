/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |                                   |
|                                   |
\*=================================*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, m;
    char s[55][55];
    while(cin>>n>>m)
    {
        int p = 1;
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
                for(j=0;j<m;j++)
                {
                    s[i][j] = '#';
                }
            else if(p==1)
            {
                p=0;
                for(j=0;j<m-1;j++)
                {
                    s[i][j] = '.';
                }
                s[i][m-1] = '#';
            }
            else
            {
                s[i][0] = '#';
                for(j=1;j<m;j++)
                {
                    s[i][j] = '.';
                }
                p=1;
            }
            s[i][m] = '\0';
            cout << s[i] << "\n";
        }
    }
    return 0;
}

