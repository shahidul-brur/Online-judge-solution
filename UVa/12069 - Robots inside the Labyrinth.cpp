/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int maxn = 1005;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
struct Rec{
    int x[2], y[2];
}rec[maxn];
struct Query{
    int x[2], y[2];
}qu[maxn];
struct Data{
    int val, index, typ, side;
    bool operator < (const Data &other) const {
        return val < other.val;
    }
};
int mx, my;
int dis[maxn][maxn]; 
bool grid[maxn][maxn];
bool vis[maxn][maxn];

void explore(int sx, int sy, int d){
    int tmp = sx-1;
    while(tmp>=0 && !vis[tmp][sy]) dis[tmp][sy] = d, vis[tmp][sy] = 1,q.push(make_pair(tmp--, sy));
    tmp=sx+1;
    while(tmp<=mx+1 && !vis[tmp][sy]) dis[tmp][sy] = d, vis[tmp][sy] = 1, q.push(make_pair(tmp++, sy));
    tmp=sy-1;
    while(tmp>=0 && !vis[sx][tmp]) dis[sx][tmp] = d, vis[sx][tmp] = 1, q.push(make_pair(sx, tmp--));
    tmp=sy+1;
    while(tmp<=my+1 && !vis[sx][tmp]) dis[sx][tmp] = d, vis[sx][tmp] = 1, q.push(make_pair(sx, tmp++));
}
int bfs(int sx, int sy, int ex, int ey){
    queue<ii> q;
    if(grid[sx][sy]==1 || grid[ex][ey]==1) return -1;
    if(sx==ey && sy==ey) return 0;
    for(int i=0;i<=mx+1;i++)
        for(int j=0;j<=my+1;j++) 
            vis[i][j]=grid[i][j]; // rectangle cell are kept visited
    dis[sx][sy] = 0, vis[sx][sy] = 1;
    explore(sx, sy, 0);
    while(!q.empty()){
        sx=q.front().first;
        sy=q.front().second;
        q.pop();
        explore(sx, sy, dis[sx][sy]+1);
    }
    if(vis[ex][ey])
        return dis[ex][ey];
    return -1;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("in2.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, q;
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d", &n);
        vector<Data> px, py;
        for(int i=0;i<n;i++) {
            int xl, xr, yd, yu;
            scanf("%d %d %d %d", &xl, &yd, &xr, &yu);
            Data data;
            data.index=i,data.typ=0; // typ=0 means rectangle
            
            data.side = 0, data.val = xl; px.push_back(data); // side=0 means left
            data.side = 1, data.val = xr; px.push_back(data); // side=1 means right
            
            data.side = 0, data.val = yd; py.push_back(data);
            data.side = 1, data.val = yu; py.push_back(data);
        }
        scanf("%d", &q);
        for(int i=0;i<q;i++){
            int xl, xr, yd, yu;
            scanf("%d %d %d %d", &xl, &yd, &xr, &yu);
            Data data;
            data.index=i,data.typ=1; // typ=1 means  query
            
            data.side = 0, data.val = xl; px.push_back(data);
            data.side = 1, data.val = xr; px.push_back(data);
            
            data.side = 0, data.val = yd; py.push_back(data);
            data.side = 1, data.val = yu; py.push_back(data);
        }
        sort(px.begin(), px.end());
        sort(py.begin(), py.end());
        int s = px.size();
        mx=1,my=1;
        for(int i=0;i<s;i++) {
           // if(i>0 && px[i].val==px[i-1].val+1) ++mx;
            if(i>0 && px[i].val>px[i-1].val+1) mx+=2;
            if(px[i].typ==0)
                rec[px[i].index].x[px[i].side] = mx;
            else qu[px[i].index].x[px[i].side] = mx;
            
            //if(i>0 && py[i].val==py[i-1].val+1) ++my;
            if(i>0 && py[i].val>py[i-1].val+1) my+=2;
            if(py[i].typ==0)
                rec[py[i].index].y[py[i].side] = my;
            else qu[py[i].index].y[py[i].side] = my;
        }
        for(int i=0;i<=mx+1;i++)
            for(int j=0;j<=my+1;j++)
                grid[i][j]=0;
        for(int i=0;i<n;i++){
//            cout << rec[i].x[0] << " " << rec[i].y[0] << ", " << rec[i].x[1] << " " << rec[i].y[1] << "\n";
            for(int r=rec[i].x[0];r<=rec[i].x[1];r++) 
                for(int c = rec[i].y[0];c<=rec[i].y[1];c++)
                    grid[r][c] = 1;
        }
//        for(int i=0;i<=mx+1;i++){
//            for(int j=0;j<=my+1;j++) cout << grid[i][j];
//            cout << "\n";
//        }
        printf("Labyrinth #%d\n", cas);
        for(int i=0;i<q;i++){
//            cout << qu[i].x[0] << " " << qu[i].y[0] << ", " << qu[i].x[1] << " " << qu[i].y[1] << " : ";
            int d = bfs(qu[i].x[0], qu[i].y[0], qu[i].x[1], qu[i].y[1]);
            if(d==-1)
                printf("Impossible.\n");
            else printf("%d\n", d);
        }
    }
    return 0;
}
