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
    int i, j, l;
    char s[100005];
    cin>>s;
    l = strlen(s);
    cout << s;
    for(i=l-1;i>=0;i--)
    {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}

