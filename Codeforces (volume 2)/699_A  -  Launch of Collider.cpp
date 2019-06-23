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
    ll i, n, m, p, last;
    char ch[200005];
    cin>>n;
    cin>>ch;
    m=1000000000;
    last = -1;
    for(i=0;i<n;i++)
    {
        cin >> p;
        if(ch[i]=='R')
        {
            last = p;
        }
        else if(last>=0)
            m = min(m, (p-last+1)/2);
    }
    if(m==1000000000)
        cout << "-1\n";
    else cout << m << "\n";
    return 0;
}

