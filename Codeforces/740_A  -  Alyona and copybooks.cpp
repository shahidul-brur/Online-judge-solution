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
ll ans;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a, b, c, n, req;
    while(cin>>n>>a>>b>>c){
    if(n%4==0)
        cout << "0\n";
    else
    {
        req = 4 - n%4;
        
        if(req==1)
        {
            ans = a;
            ans = min(ans, b+c);
            ans = min(ans, 3*c);
        }
        else if(req==2)
        {
            ans = 2*a;
            ans = min(ans, b);
            ans = min(ans, 2*c);
        }
        else if(req==3)
        {
            ans = 3*a;
            ans = min(ans, c);
            ans = min(ans, b+a);
        }
        cout << ans << "\n";
    }
    }
    return 0;
}



