//Accepted

#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
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
int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};
// --------------   template ends  ------------------------
bool vis[15][20], empt[20];
char g[15][20];
bool valid(int r, int c);
int cal(int r, int c);
void fire(int r, int c);
void fillEmptyCell();
void fillEmptyCol();
int cnt();
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int test, cas, i, j, r, c, point;
    cin>>test;
    F(cas, 1, test)
    {
        F(i, 0, 9)
            cin>>g[i];
        point = 0;
        if(cas>1)
            cout << "\n";
        cout << "Game " << cas << ":\n\n";
        
        int mov = 1;
        while(1)
        {
            int mx = 0;
            mem(vis, 0);
            for(j=0;j<15;j++)
            {
                for(i=9;i>=0;i--)
                {
                    if(!vis[i][j] && g[i][j]!='.')
                    {
                        int now = cal(i, j);
                        if(now>mx)
                        {
                            mx = now;
                            r = i;
                            c = j;
                        }
                    }
                }
            }
            if(mx==0)
            {
                point+=1000;
                break;
            }
            else if(mx==1)  break;
            else
            {
                char col = g[r][c];
                cout << "Move " << mov++ << " at (" << 10-r << "," << c+1 << "): removed "<< mx << " balls of color " << col << ", got " << (mx-2)*(mx-2)<<" points.\n";
                point+=(mx-2)*(mx-2);
                mem(vis, 0);
                fire(r, c);
                fillEmptyCell();
                fillEmptyCol();
            }
        }
        int rem = cnt();
        cout << "Final score: " << point << ", with " << rem << " balls remaining.\n";
    }
    return 0;
}
bool valid(int r, int c)
{
    if(r<0 || c<0 || r>9 || c>14)
        return 0;
    return 1;
}
int cal(int r, int c)
{
    //cout << r << ", " << c << ":\n";
    vis[r][c] = 1;
    int v = 1;
    F(i, 0, 3)
    {
        int nr = r+x[i];
        int nc = c+y[i];
        if(valid(nr, nc) && g[nr][nc]!='.' && g[r][c]==g[nr][nc] && !vis[nr][nc])
        {
            int now = cal(nr, nc);
            v+=now;
        }
    }
    return v;
}
void fire(int r, int c)
{
    vis[r][c] = 1;
    char ch = g[r][c];
    //g[r][c] = '.';
    F(i, 0, 3)
    {
        int nr = r+x[i];
        int nc = c+y[i];
        if(valid(nr, nc) && g[nr][nc]==ch && !vis[nr][nc])
            fire(nr, nc);
    }
}
void fillEmptyCell()
{
    F(j, 0, 14)
    {
        for(int i=9;i>=1;i--)
        {
            if(vis[i][j])
            {
                if(vis[i-1][j]==0)
                {
                    g[i][j] = g[i-1][j];
                    vis[i-1][j] = 1;
                    vis[i][j] = 0;
                }
                else
                {
                    int k = i-1;
                    while(k>=0 && vis[k][j]==1)
                        k--;
                    if(k>=0)
                    {
                        g[i][j] = g[k][j];
                        vis[k][j] = 1;
                        vis[i][j] = 0;
                    }
                }
                
            }
        }
        for(int i=9;i>=0;i--)
        {
            if(vis[i][j])
            {
                g[i][j] = '.';
            }
        }
    }
}
bool isEmptyCol(int c)
{
    for(int i=0;i<10;i++)
        if(g[i][c]!='.')
            return 0;
    return 1;
}
void fillEmptyCol()
{
    int j=0;
    for(;j<14;j++)
    {
        int emp = 0;
        if(isEmptyCol(j))
        {
            int k=j+1;
            while(isEmptyCol(k))
            {
                k++;
                if(k>=15)
                    break;
            }
            if(k<15)
            {
                for(int i=0;i<10;i++)
                {
                    g[i][j] = g[i][k];
                    g[i][k] = '.';
                }
            }
        }
    }
}
int cnt()
{
    int c = 0;
    F(i, 0, 9)
    {
        F(j, 0, 14)
        {
            if(g[i][j]!= '.')
                c++;
        }
    }
    return c;
}
