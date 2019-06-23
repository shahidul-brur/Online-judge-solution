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
    string s;
    int n, y=0;
    cin>>s;
    n = s.size();
    F(i, 0, n-1)
    {
        int c = 0;
        F(j, i, n-1)
        {
            if(s[j]==s[i])
                c++;
            else break;
        }
        if(c>=7)
        {
            y=1;
            break;
        }
        
    }
    if(y==1)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
