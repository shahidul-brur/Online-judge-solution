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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a[100005], mx, n;
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>a[i];
        
    }
    mx = 1;
    int cnt=1;
    F(i, 1, n-1)
    {
        cin>>a[i];
        if(a[i]>a[i-1])
            cnt++;
        else cnt=1;
        mx = max(cnt, mx);
    }
    cout << mx << "\n";
    return 0;
}

