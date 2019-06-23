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
    ll a, b, c;
    while(cin>>a>>b>>c)
    {
        if(a==b && b==c)
        {
            cout << "0\n";
        }
        else
        {
            ll cnt = 0LL;
            if(a>=b && a>=c)
            {
                if(b<a)
                    cnt=a-1 - b;
                if(c<a)
                    cnt+=a-1 - c;
            }
            else if(b>=a && b>=c)
            {
                if(a<b)
                    cnt=b-1 - a;
                if(c<b)
                    cnt+=b-1 - c;
            }
            else
            {
                if(a<c)
                    cnt=c-1 - a;
                if(b<c)
                    cnt+=c-1 - b;
            }
            cout << cnt << "\n";
        }
            
    }
    return 0;
}
