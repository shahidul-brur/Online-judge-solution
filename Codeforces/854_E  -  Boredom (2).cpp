#include<bits/stdc++.h>
using namespace std;
#define ll       long long
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
const int MX = 200010;
int arr[MX];
int n;
vector<int> t[4*MX];

void build(int node=1, int l=1, int r=n) {

	if(l == r) {
		t[node].push_back(arr[l]);
		return;
	} 
	int mid = (l + r) >> 1; 
	int left = node << 1;
	int right = left+1;
	build(left, l, mid);
	build(right, mid+1, r);
	merge(all(t[left]), all(t[right]),back_inserter(t[node]));
}

int query(int i, int j, int k, int node=1, int l=1, int r=n) 
{

	if(i > r || l > j || i>j) return 0;
	if(i <= l && r <= j) {
		return lower_bound(all(t[node]), k) 
			         - t[node].begin();
	} 
	int mid = l + r >> 1, 
		left = node << 1, right = left|1;
	return query(i, j, k,left, l, mid) + 
		   query(i, j, k,right, mid+1, r);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int q;
    scanf("%d %d", &n, &q);
    f(i, 1, n)
    {
        scanf("%d", &arr[i]);
    }
    build();

    int l,r, u, d;
    while(q--)
    {
        scanf("%d", &l);
        scanf("%d", &d);
        scanf("%d", &r);
        scanf("%d", &u);
        
        ll ans = 0LL;
        
        int les_d = query(1, l-1, d);
        int les_eq_u = query(1, l-1, u+1) - les_d;
        int gret_u = l-1 - les_eq_u-les_d; 
        
        int les_dr = query(r+1, n, d);
        int les_eq_ur = query(r+1, n, u+1) - les_dr;
        int gret_ur = n-r - les_eq_ur-les_dr;
        
        int les_dm = query(l, r, d);
        int les_eq_um = query(l, r, u+1) - les_dm;
        int gret_um = r-l+1 - les_eq_um -les_dm;
        
        ans+=1LL*les_eq_um*(les_eq_um-1)/2;
        ans+=1LL*les_d * (gret_um + les_eq_um + les_eq_ur + gret_ur);
        ans+=1LL*les_eq_u * (gret_um + les_eq_um + les_dm + les_dr + les_eq_ur + gret_ur);
        ans+=1LL*gret_u * (les_eq_um + les_dm + les_dr + les_eq_ur);
        
        ans+=1LL*les_dm * (gret_um + les_eq_um + les_eq_ur + gret_ur);
        ans+=1LL*les_eq_um * (gret_um + les_dr + les_eq_ur + gret_ur);
        ans+=1LL*gret_um * (les_dr + les_eq_ur);
        
        printf("%lld\n", ans);
    }
    return 0;
}