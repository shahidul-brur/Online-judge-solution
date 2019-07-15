#include<bits/stdc++.h>
using namespace std;

typedef	 long long ll;

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll ans, d[4], cost[4], td[4];
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
		sort(td, td+3);
		ans = cost[1]*(d[0]+d[1]+d[2]);
		
		ll c3 = min(cost[3], min(cost[1]+cost[2], 3*cost[1]));
		ll c2 = min(cost[2], 2*cost[1]);
		ll c1 = cost[1];
		
		ll typ3 = td[0]; td[1] -= td[0], td[2] -= td[0], td[0] = 0;
		ll typ2 = td[1]; td[2] -= td[1], td[1] = 0;
		ll typ1 = td[2];
		
		ans = min(ans, typ1*c1 + typ2*c2 + typ3*c3);
		
		for(int i = 0;i<3;i++) td[i] = d[i];
		
		if(cost[2]*)
		
		cout << ans << "\n";
    }
	return 0;
}


