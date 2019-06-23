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
#define N 1000000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll tot, s, n;
    vector<ll> p;
    while(cin>>n>>s)
    {
        F(i, 0, n-1)
        {
            ll x;
            cin>>x;
            p.pb(x);
        }
        sort(all(p));
        if(p[n-1]<s)
            tot = llabs(s-p[n-1]) + llabs(p[n-1] - p[1]);
        else
        for(int i=0;i<n;i++)
        {

            if(p[i]==s)
            {
                if(i==0)
                    tot = llabs(p[0] - p[n-2]);
                else if(i==n-1)
                    tot = llabs(p[1] - p[n-1]);
                else
                {
                    tot = llabs(p[0]-p[i])+ llabs(p[0] - p[n-2]);
                    tot = min(tot, llabs(p[1]-p[i])+ llabs(p[1] - p[n-1]));

                    tot = min(tot, llabs(p[i] - p[n-2])+llabs(p[n-2] - p[0]));
                    tot = min(tot, llabs(p[i] - p[n-1])+llabs(p[n-1] - p[1]));
                }
                break;
            }
            else if(p[i]>s)
            {
                if(i==0)
                {
                    tot = llabs(s-p[0]) + llabs(p[n-2] - p[0]);
                }
                else
                {
                    tot = llabs(s-p[i])+ llabs(p[n-2] - p[i]) + llabs(p[0] - p[n-2]);
                    tot = min(tot, llabs(s-p[i])+ llabs(p[n-1] - p[i]) + llabs(p[1] - p[n-1]));

                    tot = min(tot, llabs(s-p[i])+ llabs(p[0] - p[i]) + llabs(p[0] - p[n-2]));
                    tot = min(tot, llabs(s-p[i])+ llabs(p[1] - p[i]) + llabs(p[1] - p[n-1]));

                    tot = min(tot, llabs(s-p[i-1])+ llabs(p[0] - p[i-1]) + llabs(p[0] - p[n-2]));
                    tot = min(tot, llabs(s-p[i-1])+ llabs(p[1] - p[i-1]) + llabs(p[1] - p[n-1]));

                    tot = min(tot, llabs(s-p[i-1])+ llabs(p[n-2] - p[i-1]) + llabs(p[0] - p[n-2]));
                    tot = min(tot, llabs(s-p[i-1])+ llabs(p[n-1] - p[i-1]) + llabs(p[1] - p[n-1]));
                }
                break;
            }
        }
        if(n==1)
         tot =0;
        cout << tot << "\n";
        p.clear();
    }
    return 0;
}