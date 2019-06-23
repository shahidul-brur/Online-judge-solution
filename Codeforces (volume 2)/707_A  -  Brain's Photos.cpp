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
    int col = 0;
    int n, m, i, j;
    char c;
    while(cin>>n>>m)
    {
        col=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>c;
            if(c=='M' || c=='Y' || c=='C')
                col =1;
        }
    if(col) cout << "#Color\n";
    else cout << "#Black&White\n";
    }
    return 0;
}

