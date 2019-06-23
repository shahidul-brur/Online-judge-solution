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
int a[1000005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a, a+n);
    for(i=0, j=1;i<n;i++)
    {
        if(a[i]>=j)
            j++;
    }
    cout << j << "\n";
    return 0;
}
