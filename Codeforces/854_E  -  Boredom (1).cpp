/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 200005;
ll arr[MX];
vector<int> tree[4*MX];
void build(int node, int l, int r) {
	if(l == r) {
		tree[node].push_back(arr[l]);
		return;
	} 
	int mid = l + r >> 1, 
	left = node << 1, right = left|1;
	
	build(left, l, mid);
	build(right, mid+1, r);
	
	merge(all(tree[left]), all(tree[right]), 
	        back_inserter(tree[node]));
}
int query(int node, int l, int r, int i, int j, int k) 
{
	if(i > r || l > j) return 0;
	if(i <= l && r <= j) {
		return lower_bound(all(tree[node]), k) 
			         - tree[node].begin();
	} 
	int mid = l + r >> 1, 
		left = node << 1, right = left|1;
	return query(left, l, mid, i, j, k) + 
		   query(right, mid+1, r, i, j, k);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    while(cin>>n>>q)
    {
        f(i, 1, n)
        {
            cin>>arr[i];
        }
        build(1, 1, n);
        
        int l,r, u, d;
        while(q--)
        {
            cin>>l>>d>>r>>u;
            
            ll ans = 0LL;
            
            int les_d = query(1, 1, n, 1, l-1, d);
            int les_eq_u = query(1, 1, n, 1, l-1, u+1) - les_d;
            int gret_u = l-1 - les_eq_u-les_d; 
            
            int les_dr = query(1, 1, n, r+1, n, d);
            int les_eq_ur = query(1, 1, n, r+1, n, u+1) - les_dr;
            int gret_ur = n-r - les_eq_ur-les_dr;
            
            int les_dm = query(1, 1, n, l, r, d);
            int les_eq_um = query(1, 1, n, l, r, u+1) - les_dm;
            int gret_um = r-l+1 - les_eq_um -les_dm;
            
            ans+=1LL*les_eq_um*(les_eq_um-1)/2;
            ans+=1LL*les_d * (gret_um + les_eq_um + les_eq_ur + gret_ur);
            ans+=1LL*les_eq_u * (gret_um + les_eq_um + les_dm + les_dr + les_eq_ur + gret_ur);
            ans+=1LL*gret_u * (les_eq_um + les_dm + les_dr + les_eq_ur);
            
            ans+=1LL*les_dm * (gret_um + les_eq_um + les_eq_ur + gret_ur);
            ans+=1LL*les_eq_um * (gret_um + les_dr + les_eq_ur + gret_ur);
            ans+=1LL*gret_um * (les_dr + les_eq_ur);
            
            cout << ans << "\n";
        }
    }
    return 0;
}