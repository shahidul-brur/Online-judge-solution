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
ll sum[105], n, m, maxi;
int main()
{
    int l, r;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i];
        sum[i] += sum[i-1];
    }
    
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        if(sum[r] - sum[l-1]>0)
            maxi += (sum[r] - sum[l-1]);
    }
    cout << maxi << "\n";
    return 0;
}
