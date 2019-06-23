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
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, b, a) for(int i=b;i>=a;i--)
#define sq(a) (a)*(a)
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
    //ios_base::sync_with_stdio(false);
    ll a[10], t1, t2;
    cin>>a[2]>>a[3]>>a[5]>>a[6];
    ll mini = a[2];
    if(a[5]<mini)
        mini = a[5];
    if(a[6]<mini)
        mini = a[6];
        
    t1 = mini;
    
    a[2]-=mini;
    a[5]-=mini;
    a[6]-=mini;
    
    mini = a[2];
    mini = min(a[2], a[3]);
    
    t2 = mini;
    ll sum = t1*256 + 32*t2;
    cout << sum << "\n";
    return 0;
}

