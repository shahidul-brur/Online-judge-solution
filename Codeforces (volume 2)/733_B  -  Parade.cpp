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
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, l[100005], r[100005], L, R, cnt, ans;
    while(cin>>n)
    {
        L=0;
        R=0;
        F(i, 1, n)
        {
            cin>>l[i]>>r[i];
            L+=l[i];
            R+=r[i];
        }
        cnt = abs(L-R);
        ans = 0;
        F(i, 1, n)
        {
            int now = abs((L-l[i]+r[i]) - (R-r[i]+l[i]));
            if(now > cnt)
            {
                ans = i;
                cnt = now;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
