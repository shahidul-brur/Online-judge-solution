#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define mp make_pair
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long

// ---------------- typedef ------------------------------
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

// --------------   template ends  ------------------------

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n, m, k, i, j, d, x, dep;
    char t;
    while(cin>>n>>x)
    {
        dep=0;
        for(i=0;i<n;i++)
        {
            cin>>t>>d;
            if(t=='-')
            {
                if(x>=d)
                    x-=d;
                else dep++;
            }
            else x+=d;
        }
        cout << x << " " << dep << "\n";
    }
    return 0;
}

