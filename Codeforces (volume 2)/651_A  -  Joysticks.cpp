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
    int t, n, i, j,a,b;
    while(cin>>a>>b)
    {
        int ans = 0;
        while(a>0 && b>0)
        {
            if(a<=b)
            {
                a++;
                b-=2;
            }
            else
            {
                b++;
                a-=2;
            }
            if(a<0 || b<0)
                break;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

