#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int)1e9+7;
const int maxn = (int)4e5+5;

struct node{
	ll mul, lazy;
	ll range_mask, lazy_mask;
}tree[maxn<<2];

int l, r, val, a[maxn], inv[63], p;
vector<int> prime;
ll mask[302];

int bin_exp(int b, int p){
	if(p==-1) p = mod-2;
	ll ret = 1;
	b%=mod;
	while(p>0){
		if(p&1) ret = ((ll)ret*b)%mod;
		b=(ll)b*b%mod;
		p>>=1;
	}
	return ret;
}
void push_down(int id, int b, int e){
	if(tree[id].lazy==1) return;
	int lft = id<<1, rgt = lft|1;
	tree[id].mul = (ll)tree[id].mul * bin_exp(tree[id].lazy, e-b+1)%mod;
	tree[id].range_mask|=tree[id].lazy_mask;
	if(b!=e){
		tree[lft].lazy = (ll)tree[lft].lazy*tree[id].lazy%mod;
		tree[rgt].lazy = (ll)tree[rgt].lazy*tree[id].lazy%mod;

		tree[lft].lazy_mask |= tree[id].lazy_mask;
		tree[rgt].lazy_mask |= tree[id].lazy_mask;
	}
	tree[id].lazy = 1;
	tree[id].lazy_mask = 0;
}
void combine(int id){
	int lft = id<<1, rgt = lft|1;
	tree[id].mul = (ll)tree[lft].mul*tree[rgt].mul%mod;
	tree[id].range_mask = tree[lft].range_mask|tree[rgt].range_mask;
}
void build(int id, int b, int e){
	tree[id].lazy = 1;
	tree[id].lazy_mask = 0LL;
	if(b==e){
		tree[id].mul = a[b];
		tree[id].range_mask = mask[a[b]];
		return;
	}
	int mid = (b+e)>>1, lft = id<<1, rgt = lft|1;
	build(lft,b,mid);
	build(rgt,mid+1,e);
	combine(id);
}
void update(int id, int b, int e){
	push_down(id, b, e);
	if(b>r || e<l) return;
	if(b>=l && e<=r){
		tree[id].lazy = val;
		tree[id].lazy_mask = mask[val];
		push_down(id,b,e);
		return;
	}
	int mid = (b+e)>>1, lft = id<<1, rgt = lft|1;
	update(lft,b,mid);
	update(rgt,mid+1,e);
	combine(id);
}
pair<ll,ll> query(int id, int b, int e){
	push_down(id, b, e);
	if(b>=l && e<=r)
		return make_pair(tree[id].mul,tree[id].range_mask);
	int mid = (b+e)>>1, lft = id<<1, rgt = lft|1;
	if(r<=mid)
		return query(lft,b,mid);
	if(l>mid)
		return query(rgt,mid+1,e);
	pair<ll,ll> L = query(lft,b,mid);
	pair<ll,ll> R = query(rgt,mid+1,e);
	L.first = (ll)L.first*R.first%mod;
	L.second |= R.second;
	return L;
}

bool isprime(int num){
	for(int i=2;i<num;i++) if(num%i==0)
		return 0;
	return 1;
}
void prime_precal(){
	for(int i = 2;i<=300;i++) {
 		if(isprime(i)){
			inv[prime.size()] = bin_exp(i,-1);
			prime.push_back(i);
		}
	}
	p = prime.size();
	for(int i = 2;i<=300;i++){
		mask[i] = 0;
		for(int j=0;j<p && prime[j]<=i;j++)
			if(i%prime[j]==0) mask[i]|=1LL<<j;
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    prime_precal();
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    build(1,1,n);
    while(q--){
    	string cmd;
    	cin>>cmd;
    	if(cmd[0]=='T'){
    		cin>>l>>r;
    		pair<ll,ll> ret = query(1,1,n);
    		ll ans = ret.first;
    		for(int j=0;j<p;j++) if((1LL<<j) & ret.second){
				ans = (ll)ans*(prime[j]-1)%mod;
				ans = (ll)ans*inv[j]%mod;
			}
    		cout << ans << "\n";
    	}
    	else{
    		cin>>l>>r>>val;
    		if(val==1) continue;
    		update(1,1,n);
    	}
    }
    return 0;
}
