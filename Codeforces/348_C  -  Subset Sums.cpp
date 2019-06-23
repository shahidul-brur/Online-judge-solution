#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 100003;
ll arr[MX];
bool exist[MX];
ll add[MX];
ll ini_sum[MX];
ll heavy_sum[MX];
vector<int> Set[MX];
vector<pair<int, ll> > intersection[MX]; // <setid, cnt>
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q ;
	for (int i = 1 ; i <= n ; i++ ) {
		cin >> arr[i] ;
	}
	int sqt = sqrt(n);
	for (int i = 1; i <= m ; i++ ) {
		int siz;
		cin>>siz;
		ini_sum[i] = 0LL;
		while(siz--) {
			int idx;
			cin >> idx;
			Set[i].push_back(idx);
			ini_sum[i]+=arr[idx];
		}
	}
	
	for (int i = 1; i <= m ; i++ ) { 
		if(Set[i].size()<sqt) continue;
		memset(exist, 0, sizeof exist);
		for (int j = 0; j < Set[i].size() ; j++ ) exist[Set[i][j]] = 1;
		for (int j = 1; j <= m ; j++ ) {
			int match = 0;
			for (int k = 0; k < Set[j].size() ; k++ )
				if(exist[Set[j][k]]) {match++;};
			intersection[j].push_back({i, match});
		}
	}
	
	while(q--){
		char type;
		cin>>type;
		if(type == '+'){
			int setId;
			ll val;
			cin >> setId >> val;
			for(int i = 0; i < intersection[setId].size();i++){
				heavy_sum[intersection[setId][i].first]+=intersection[setId][i].second*val;
			}
			if(Set[setId].size()>=sqt){
				add[setId]+=val;
			}
			else {
				for(int i = 0; i < Set[setId].size(); i++){
					arr[Set[setId][i]]+=val;
				}
			}
		}
		else {
			int setId;
			cin >> setId;
			if(Set[setId].size()>=sqt){
				cout << ini_sum[setId] + heavy_sum[setId] << "\n";
			}
			else {
				long long ans = 0LL;
				for(int i = 0; i < Set[setId].size(); i++)
					ans += arr[Set[setId][i]];
				for (int i = 0;i<intersection[setId].size(); i++){
					ans += add[intersection[setId][i].first]*intersection[setId][i].second;
				}
				cout << ans << "\n";
			}
		}
	}
	return 0;
}

