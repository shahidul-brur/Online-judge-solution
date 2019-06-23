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
    int a[10], f[500], i;
    while(cin>>a[0])
    {
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        mem(f, 0);
        int sum = 0;
        for(i=0;i<5;i++)
        {
            sum+=a[i];
            f[a[i]]++;
        }
        
        int mx = 0;
        for(i=0;i<5;i++)
        {
            if(f[a[i]]==2)
            {
                mx = max(mx, 2*a[i]);
            }
            else if(f[a[i]]>=3)
            {
                mx = max(mx, 3*a[i]);
            }
        }
        cout << sum - mx << "\n";
        fflush(stdout);
    }
    return 0;
}

