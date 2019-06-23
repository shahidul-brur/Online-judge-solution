/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |                                   |
|                                   |
\*=================================*/

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
#define mod 1000000007
#define N 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, a[105];
    char s[105][105];
    cin>>n;
    F(i, 1, n)
        cin>>a[i];
    getchar();
    bool y=1;
    F(i, 1, n)
    {
        gets(s[i]);
        int l = strlen(s[i]);
        int v = 0;
        F(j, 0, l-1)
        {
            if(s[i][j]=='a' || s[i][j]=='e' || s[i][j]=='i' || s[i][j]=='o' || s[i][j]=='u' || s[i][j]=='y')
                v++;
        }
        if(v!=a[i])
            y=0;
    }
    if(y)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

