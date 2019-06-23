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
#define all(a) a.begin(), a.end()
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
    int i, j;
    int n, cnt, mx, d;
    char s[105][105];
    scanf("%d %d", &n, &d);
    for(i=0;i<d;i++)
    {
        scanf("%s", s[i]);
    }
    mx = 0, cnt=0;
    for(i=0;i<d;i++)
    {
        bool f = 0;
        for(j=0;j<n; j++)
        {
            if(s[i][j]=='0')
            {
                f=1;
                break;
            }
        }
        
        if(f==1)
        {
            cnt++;
            mx = max(mx, cnt);
        }
        else cnt = 0;
    }
    cout << mx << "\n";
    return 0;
}
