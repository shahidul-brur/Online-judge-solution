#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
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
    int n, i, j, z=0, a;
    cin>>n;
    F(i, 1, n)
    {
        cin>>a;
        if(a==0)
            z++;
    }
    if(n==1)
    {
        if(a==1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else 
    {
        if(z==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

