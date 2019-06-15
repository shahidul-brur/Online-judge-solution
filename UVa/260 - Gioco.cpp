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
#define N 205
int x[] = {0, 0, 1, -1, 1};
int y[] = {1, -1, 0, 0, 1};
int R, C;
char g[N][N];
bool vis[N][N];
bool valid(int r, int c)
{
    if(r<0 || c<0 || r>=R || c>=C)
        return 0;
    if(vis[r][c])
        return 0;
    return 1;
}
bool dfsB(int r, int c)
{
    vis[r][c] = 1;
    bool f=0;
    for(int i=0;i<5;i++)
    {
        int rx = r+x[i];
        int cy = c+y[i];
        if(valid(rx, cy) && g[rx][cy]=='b')
        {
            if(rx==R-1)
                return 1;
            f = dfsB(rx, cy);
            if(f==1)
                break;
        }
    }
    return f;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, cas=1;
    while(cin>>R)
    {
        if(R==0)
            break;
        C = R;
        for(int i=0;i<R;i++)
        {
            cin>>g[i];
        }
        bool B=0;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<C;i++)
        {
            if(g[0][i]=='b')
            {
                B = dfsB(0, i);
            }
            if(B==1)
                break;
        }
        cout << cas++ << " ";
        if(B)
            cout << "B\n";
        else cout << "W\n";
    }
    return 0;
}

