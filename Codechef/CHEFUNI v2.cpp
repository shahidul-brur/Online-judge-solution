#include<bits/stdc++.h>
using namespace std;

#define ll	   long long
ll ans, d[4], cost[4], td[4];
ll dis[105][105][105];
int dx[] = {0, 0, 0, 1, 1, 1, 1};
int dy[] = {0, 1, 1, 0, 0, 1, 1};
int dz[] = {1, 0, 1, 0, 1, 0, 1};
ll p[8];
void cal(){
	p[0] = p[1] = p[3] = cost[1];
	p[2] = p[4] = p[5] = cost[2];
	p[6] = cost[3];
}
void bfs()
{
	memset(dis, -1, sizeof dis);
	dis[0][0][0] = 0;
	queue<pair<int, pair<int, int> > > q;
	q.push({0, {0, 0}});
	while(!q.empty()){
		ll x = q.front().first;
		ll y = q.front().second.first;
		ll z = q.front().second.second;
		q.pop();
		for(int i = 0; i<7; i++){
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			ll nz = z + dz[i];
			if(nx>d[0] || ny>d[1] || nz>d[2]) continue;
			if(dis[nx][ny][nz]==-1 || dis[nx][ny][nz] > dis[x][y][z] + p[i]){
				dis[nx][ny][nz] = dis[x][y][z] + p[i];
				//cout << x << " " << y << " " << z << " -> " <<  nx << " " << ny << " " << nz << "\n";
				q.push({nx, {ny, nz}});
			}
		}
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("corr_out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
		for(int i = 0;i<3;i++){
			cin >> d[i];
			td[i] = d[i];
		}
		for(int i = 1;i<=3;i++){
			cin >> cost[i];
		}
		sort(d, d+3);
		if(d[0]<=100 && d[1]<=100 && d[2]<=100){
			cal();
			bfs();
			cout << dis[d[0]][d[1]][d[2]] << "\n";
			continue;
		}
		sort(td, td+3);
		ans = cost[1]*(d[0]+d[1]+d[2]);
		ll c3 = min(cost[3], min(cost[1]+cost[2], 3*cost[1]));
		ll c2 = min(cost[2], 2*cost[1]);
		ll c1 = cost[1];
		ll typ3 = d[0];
		d[1] -= d[0], d[2] -= d[0], d[0] = 0;
		ll typ2 = d[1];
		d[2] -= d[1], d[1] = 0;
		ll typ1 = d[2];
		
		ans = min(ans, typ1*c1 + typ2*c2 + typ3*c3);
		
		for(int i = 0; i < 3; i++) 
			d[i] = td[i];
		
		if(d[0] + d[1] > d[2]){
			typ2 = d[2] + (d[0]+d[1])/2;
			typ1 = (d[0]+d[1])%2;
		}
		else {
			typ2 = d[0]+d[1];
			typ1 = d[2] - (d[0]+d[1]);
		}
		ans = min(ans, typ1*c1 + typ2*c2);
		cout << ans << "\n";
    }
	return 0;
}
