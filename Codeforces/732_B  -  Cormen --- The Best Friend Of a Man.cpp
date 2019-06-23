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
    int n, k, a[5005], b[5005], cnt;
    //string s, t;
    while(cin>>n>>k)
    {
        F(i, 1, n)
            cin>>a[i];
        cnt = 0;
        b[1] = a[1];
        F(i, 2, n)
        {
            if(a[i]+b[i-1]<k)
            {
                int add = k-(a[i]+b[i-1]);
                cnt+=add;
                b[i] = k-b[i-1];
            }
            else b[i] = a[i];
        }
        cout << cnt << "\n";
        cout << b[1];
        F(i, 2, n)
        {
            cout << " " << b[i];
        }
        cout << "\n";
    }
    return 0;
}
