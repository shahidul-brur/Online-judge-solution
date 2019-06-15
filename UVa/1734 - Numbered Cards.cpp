/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
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
#define N 100000
#define mod 1000000007
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, cas;
    int cnt[12], ans;
    cin>>t;
    F(cas, 1, t)
    {
        cin>>n;
        int to = n%10;
        int x = n/10;
        F(i, 0, 9)
        {
            cnt[i] = x;
        }
        F(i, 1, to)
        {
            cnt[i]++;
        }

        ans = 1;

        d = min(10, n);
        F(i, 1, d)
        {

        }
    }
    return 0;
}
