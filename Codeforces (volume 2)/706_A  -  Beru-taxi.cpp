#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define mp make_pair
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
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
double a, b;
double sq(double x)
{
    return ((x)*(x));
}
double dis(double x, double y)
{
    return sqrt(sq(a-x) + sq(b-y));
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double x, y, v, d, m;
    int i, n;
    while(cin>>a>>b)
    {
        cin>>n;
        m = 1000000000.0;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y>>v;
            d = dis(x, y);
            m = min(d/v, m);
        }
        printf("%lf", m);
    }
    return 0;
}