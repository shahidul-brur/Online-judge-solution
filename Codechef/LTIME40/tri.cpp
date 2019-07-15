
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
typedef vector<long long> vll;
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
vll v[N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll i, j, r;
    while(cin>>r)
    {
        int n=0;
        bool f=1;
        for(ll i=1;i<=r+700;i++)
        {
            for(ll j=i;j<=r+700;j++)
            {
                for(ll k=j;k<=r+700;k++)
                {
                    ll sum = i+j+k;
                    if((sum-2*i)*(sum-2*j)*(sum-2*k) == 4*sum*r*r)
                    {
                        
                        v[n].pb(i);
                        v[n].pb(j);
                        v[n].pb(k);
                        n++;
                    }
                }
            }
        }
        cout << n << "\n";
        for(int i=0;i<n;i++)
        {
            cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n";
            v[i].clear();
        }
    }
    return 0;
}
