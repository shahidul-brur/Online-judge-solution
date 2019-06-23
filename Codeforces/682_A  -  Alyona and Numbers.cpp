#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(a, b) for(i=a;i<=b;i++)
#define Fr(b, a) for(i=b;i>=a;i--)
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
    ll n, m, i, j, mx, d, cnt, k;
    while(cin>>n>>m)
    {
        cnt = 0;
        for(i=1;i<=n;i++)
        {
            for(k=1;k<=m;k++)
            {
                if((i+k)%5==0)
                {
                    cnt++;
                    break;
                }
            }
            for(j=m;j>k;j--)
            {
                if((i+j)%5==0)
                    break;
            }
            
            cnt+=(j-k)/5;
        }
        cout << cnt << "\n";
    }
    return 0;
}
