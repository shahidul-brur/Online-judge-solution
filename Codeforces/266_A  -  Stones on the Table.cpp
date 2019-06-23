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
    int n, cnt=0;
    string s;
    cin>>n;
    cin>>s;
    F(i, 0, n-2)
    {
        int j;
        for(j=i+1;j<n;j++)
        {
            if(s[j]==s[i])
                cnt++;
            else break;
        }
        i=j-1;
    }
    cout << cnt << "\n";
    return 0;
}

