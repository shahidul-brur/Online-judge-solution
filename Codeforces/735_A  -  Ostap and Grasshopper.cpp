/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, k) for(int i=0;i<k;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 1000005
#define inf 1e9
string s;
bool vis[200];
int n, k;
bool bfs(int b, int e)
{
    queue<int> q;
    q.push(b);
    mem(vis, 0);
    vis[b] = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        //cout << u << ":\n-----\n";
        int v1 = u+k;
        int v2 = u-k;
       // cout << v1 << " " << v2 << "\n";
        if(v1>=0 && v1<n && !vis[v1] && s[v1]!='#')
        {
            vis[v1] = 1;
            if(v1==e)
                return 1;
            q.push(v1);
        }
        if(v2>=0 && v2<n && !vis[v2] && s[v2]!='#')
        {
            vis[v2] = 1;
            if(v2==e)
                return 1;
            q.push(v2);
        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int b, e;
    while(cin>>n>>k)
    {
        cin>>s;
        rep(i, n)
        {
            if(s[i]=='G')
                b= i;
            else if(s[i]=='T')
                e = i;
        }
        if(bfs(b, e))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}



