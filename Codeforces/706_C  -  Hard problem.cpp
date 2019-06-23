#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100005;
string S[MAX][2];
ll dp[MAX][2], c[MAX];
int n;
ll fn(int pos, bool rev)
{
	if(pos>n)
		return 0;
	if(dp[pos][rev]!=-1)
		return dp[pos][rev];
	ll c0 = LLONG_MAX, c1 = LLONG_MAX;
	if(pos==1){
		c0 = fn(pos+1, 0);
		ll nxt = fn(pos+1, 1);
		if(nxt!=LLONG_MAX)
			c1 = c[pos] + nxt;
		dp[pos][0] = c0;
		dp[pos][1] = c1;
		return min(c0, c1);
	}
	if(S[pos][0]>= S[pos-1][rev]){
		ll nxt = fn(pos+1, 0);
		if(nxt!=LLONG_MAX)
			c0 = nxt;
	}
	if(S[pos][1]>=S[pos-1][rev]){
		ll nxt = fn(pos+1, 1);
		if(nxt!=LLONG_MAX)
			c1 = c[pos] + nxt;
	}
	dp[pos][rev] = min(c0, c1);
	return dp[pos][rev];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++){
		string tem;
		cin>>tem;
		S[i][0] = tem;
		reverse(tem.begin(), tem.end());
		S[i][1] = tem;
	}
	memset(dp, -1, sizeof(dp));
	ll ans = fn(1, 0);
	if(ans == LLONG_MAX) cout << "-1\n";
	else   cout << ans << "\n";
	return 0;
}
