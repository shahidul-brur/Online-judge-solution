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
bool st[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u[100005], v[100005], w[100005];
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        st[x] = 1;
    }
    if(k==0)
    {
        cout << "-1\n";
        return 0;
    }
    int mini = 1000000005;
    int f=0;
    for(int i=1;i<=m;i++)
    {
        if(st[u[i]]==0 && st[v[i]]==1 || st[u[i]]==1 && st[v[i]]==0)
        {
            f= 1;
            mini = min(mini, w[i]);
        }
    }
    if(f)
    cout <<mini << "\n";
    else cout << "-1\n";
    return 0;
}


