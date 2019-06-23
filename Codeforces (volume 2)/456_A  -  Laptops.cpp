#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(i, a, b) for(i=a;i<=b;i++)
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
    int n, i, h=0, a,b;
    vii v;
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>a>>b;
        v.pb(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    
    F(i, 1, n-1)
    {
        if(v[i].second<v[i-1].second)
            h=1;
    }
    if(h)
        cout << "Happy Alex\n";
    else cout << "Poor Alex\n";
    return 0;
}
