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
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, c, pre, cnt;
    while(cin>>n>>c)
    {
        cnt= 1;
        cin>>pre;
        F(i, 1, n-1)
        {
            cin>>t;
            if(t-pre<=c)
                cnt++;
            else cnt=1;
            pre = t;
        }
        cout << cnt << "\n";
    }
    return 0;
}

