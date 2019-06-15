#include <bits/stdc++.h>
using namespace std;
int visited[102][102], even, odd, grid[102][102], R, C, M, N;
int X[]={-1, -1, 1, 1};
int Y[]={-1, 1, -1, 1};
vector< pair<int, int> > v;
bool valid(int x, int y)
{
    if(x>=0 && x<R && y>=0 && y<C)
    {
        if(grid[x][y]==0)
            return true;
        else return false;
    }
    else return false;
}
bool took(pair<int, int> p)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==p)
            return true;
    }
    return false;

}
void GO(int x, int y)
{
    pair<int, int> p;
    int r, c, cnt=0, taken;
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        r=X[i]*M + x;
        c=Y[i]*N + y;
        if(valid(r, c))
        {
            p=make_pair(r, c);
            if(!took(p))
            {
                cnt++;
                v.push_back(p);
            }
        }
        r=X[i]*N + x;
        c=Y[i]*M + y;
        if(valid(r, c))
        {
            p=make_pair(r, c);
            if(!took(p))
            {
                cnt++;
                v.push_back(p);
            }
        }
    }
    v.resize(0);
    for(int i=0;i<4;i++)
    {
        r=X[i]*M + x;
        c=Y[i]*N + y;
        if(valid(r, c))
        {
            if(visited[r][c]==0)
                GO(r, c);
        }
        r=X[i]*N + x;
        c=Y[i]*M + y;
        if(valid(r, c))
        {
            if(visited[r][c]==0)
                GO(r, c);
        }
    }
    if(cnt%2==0)
        even++;
    else odd++;
}
int main()
{
    freopen("11906.txt", "r", stdin);
    int t, cas, w, x, y, i, j;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>R>>C>>M>>N>>w;
        memset(grid, 0, sizeof(grid));
        memset(visited, 0, sizeof(visited));
        for(i=1;i<=w;i++)
        {
            cin>>x>>y;
            grid[x][y]=1;
        }
        odd=even=0;
        GO(0, 0);
        printf("Case %d: %d %d\n", cas, even, odd);
    }
    return 0;
}
