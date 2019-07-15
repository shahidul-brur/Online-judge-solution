
/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |                                   |
|                                   |
\*==================================*/

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
#define N 100000
int f[4][30];
int ff[4][30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    ll a, b, c, d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        ll cnt = 0LL;
        for(int i=a;i<=b;i++)
        {
            if(i<c)
                cnt+=(d-c+1);
            else if(i==c)
                cnt+=(d-c);
            else if(i>c && i<d) cnt+=(d-i);
        }
        cout << cnt << "\n";
    }
    return 0;
}

