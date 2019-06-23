#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int sz = 2e5 + 2;
vector<int> g[sz];
ll dp[sz],sum[sz],a[sz];
ll total_sum, ans;
void dfs(int u, int level, int par){
	dp[1] += level * a[u];
	sum[u] = a[u];
	for (int v : g[u]) if(v != par) {
		dfs(v, level + 1, u);
		sum[u] += sum[v];
	}
}

void dfs2(int u, int par){
	for(int v : g[u]) if(v != par){
		dp[v] = dp[u] + total_sum - 2 * sum[v];
		ans = max(ans, dp[v]);
		dfs2(v, u);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total_sum += a[i];
	}
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 0);
	ans = dp[1];
	dfs2(1, 0);
	cout << ans << endl;
	return 0;
}