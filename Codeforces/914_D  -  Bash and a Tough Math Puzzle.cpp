#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
int arr[MAX], gcd[4*MAX], n;
#define lrm int mid = (tl+tr)>>1, lft = 2*node, rgt = 2*node+1
#define push_up gcd[node] = __gcd(gcd[lft], gcd[rgt]);
void build(int node, int tl, int tr)
{
	if(tl==tr)
	{
		gcd[node] = arr[tl];
		return;
	}
	lrm;
	build(lft, tl, mid);
	build(rgt, mid+1, tr);
	push_up;
}
void update(int node, int tl, int tr, int idx, int val)
{
	if(idx<tl || idx>tr) return;
	if(tl==tr && tl==idx)
	{
		gcd[node] = arr[idx] = val;
		return;
	}
	lrm;
	if(idx<=mid)
		update(lft, tl, mid, idx, val);
	else
		update(rgt, mid+1, tr, idx, val);
	push_up;
}
int cnt;
void query(int node, int tl, int tr, int l, int r, int x)
{
	if(l>tr || r<tl || gcd[node]%x==0 || cnt>1)
		return;
	if(tl==tr){
		if(gcd[node]%x!=0){
			cnt++;
		}
		return;
	}
	lrm;
	query(lft, tl, mid, l, r, x);
	query(rgt, mid+1, tr, l, r, x);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>arr[i];
	build(1, 1, n);
	int q;
	cin>>q;
	while(q--)
	{
		int typ;
		cin>>typ;
		if(typ==1){ // query
			int l, r, x;
			cin>>l>>r>>x;
			cnt = 0;
			query(1, 1, n, l, r, x);
			if(cnt>1)
				cout << "NO\n";
			else cout << "YES\n";
		}
		else{
			int idx, val;
			cin>>idx>>val;
			update(1, 1, n, idx, val);
		}
	}
	return 0;
}
