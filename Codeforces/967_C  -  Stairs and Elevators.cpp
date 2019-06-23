#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 100002;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int r, c, s, e, v;
	cin>>r>>c>>s>>e>>v;
	vector<int> stair, elev;
	f(i, 0, s-1)
	{
	    int id;
	    cin>>id;
	    stair.pb(id);
	}
	f(i, 0, e-1)
	{
	    int id;
	    cin>>id;
	    elev.pb(id);
	}
	int q;
	cin>>q;
	while(q--)
    {
        int r1, c1;
        int r2, c2;
        cin>>r1>>c1;
        cin>>r2>>c2;
        if(r1==r2)
        {
            cout << abs(c1-c2) << "\n";
            continue;
        }
        int rE=-1, rS=-1; 
        int lE=-1, lS=-1;
        if(e==1)
        {
            rE = elev[0];
        }
        else if(e==2)
        {
            lE = elev[0];
            rE = elev[1];
        }
        else if(e>2)
        {
            auto it = upper_bound(all(elev), c1);
            if(it!=elev.end())
                rE = elev[it - elev.begin()];
            if(it!=elev.begin())
                lE = elev[it-1 - elev.begin()];
        }
        
        if(s==1)
        {
            rS = stair[0];
        }
        else if(s==2)
        {
            lS = stair[0];
            rS = stair[1];
        }
        else if(s>2)
        {
            auto it = upper_bound(all(stair), c1);
            if(it!=stair.end())
                rS = stair[it - stair.begin()];
            if(it!=stair.begin())
                lS = stair[it-1 - stair.begin()];
        }
        
        int ans = INT_MAX;
        //cout << rE << " " << lE << ", " << rS << " " << lS << " -> ";
        if(rE!=-1)
            ans = min(ans, abs(rE - c1) + abs(rE-c2) + (abs(r1-r2)+v-1)/v);
        if(lE!=-1)
            ans = min(ans, abs(lE - c1) + abs(lE-c2) + (abs(r1-r2)+v-1)/v);
        
        if(rS!=-1)
            ans = min(ans, abs(rS - c1) + abs(rS-c2) + abs(r1-r2));
        if(lS!=-1)
            ans = min(ans, abs(lS - c1) + abs(lS-c2) + abs(r1-r2));
        
        cout << ans << "\n";
    }
	return 0;
}
