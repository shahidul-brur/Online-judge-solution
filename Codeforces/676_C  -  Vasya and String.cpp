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
int pa, pb, now, ca, cb, sa, sb, mx;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, k, n, a[100005], b[100005];
    string s;
    cin>>n>>k;
    cin>>s;
    a[0] = b[0] = -1;
    for(now=0;now<n;now++)
    {
        //cout << now << "\n";
        // make bbbb....
        if(s[now]=='a')
        {
            a[++sa] = now;
            if(ca>=k)
            {
                pa++;
                ca--;
            }
            ca++;
        }
        //make aaaaa...
        else
        {
            b[++sb] = now;
            
            if(cb>=k)
            {
                pb++;
                cb--;
            }
            cb++;
        }
        
        //cout << "  a => " << b[pb] << " - " << now << " = " << now - b[pb] << "\n";
        //cout << "  b => " << a[pa] << " - " << now << " = " << now - a[pa] << "\n";
        mx = max(mx, now - a[pa]);
        mx = max(mx, now - b[pb]);
    }
    
    cout << mx << "\n";
    return 0;
}
