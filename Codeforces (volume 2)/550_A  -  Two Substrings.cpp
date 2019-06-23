#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t, n, i, j;
    string s;
    cin>>s;
    int l = s.length();
    F(i, 0, l-2)
    {
        if(s[i]=='A' && s[i+1]=='B')
        {
            F(j, i+2, l-2)
            {
                if(s[j]=='B' && s[j+1]=='A')
                {
                    cout << "YES\n";
                    return 0;
                }
            }
            break;
        }
    }
    F(i, 0, l-2)
    {
        if(s[i]=='B' && s[i+1]=='A')
        {
            F(j, i+2, l-2)
            {
                if(s[j]=='A' && s[j+1]=='B')
                {
                    cout << "YES\n";
                    return 0;
                }
            }
            break;
        }
    }
    cout << "NO\n";
    return 0;
}

