#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

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
    int t, n, i, j;
    char s[1005][10];
    while(cin>>n)
    {
        F(i, 0, n-1) cin>>s[i];
        int y=0;
        
        F(i, 0, n-1)
        {
            if(s[i][0] == 'O' && s[i][1]=='O')
            {
                s[i][0] = '+';
                s[i][1] = '+';
                y=1;
                break;
            }
            else if(s[i][3] == 'O' && s[i][4]=='O')
            {
                s[i][3] = '+';
                s[i][4] = '+';
                y=1;
                break;
            }
        }
        if(y==1)
        {
            cout << "YES\n";
            F(i, 0, n-1)
                cout << s[i] << "\n";
        }
        else cout << "NO\n";
        
    }
    return 0;
}

