/*==============================================*\
ID:          shahidul_brur

Name:     Md. Shahidul Islam
Study:      CSE, BRUR
Address:  Rangpur, Bangladesh

 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English)
\*===============================================*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20, blk_sz = 800;
int BIT[450][maxn], n,m,last_blk;
void upd(int t, int idx, int v){
	while(idx<=n){
		BIT[t][idx]+=v;
		idx+=idx&-idx;
	}
}
int ask(int t, int idx){
	int ret = 0;
	while(idx>0){
		ret+=BIT[t][idx];
		idx-=idx&-idx;
	}
	return ret;
}
int a[maxn], b[maxn], b_idx[maxn], a_idx[maxn];
int query(int la, int ra, int lb, int rb)
{
	int cnt = 0;
	while(la<=ra && la%blk_sz!=0){
		int x = a[la];
		if(b_idx[x]>=lb && b_idx[x]<=rb){
			 cnt++;
			 //cout << la << ": 1 -> 1\n";
		}
		++la;
	}
	while(la+blk_sz-1<=ra){
		cnt+=ask(la/blk_sz, rb) - ask(la/blk_sz, lb-1);
			//cout << la << " : " << block[la/blk_sz] << " -> 2\n";
		la+=blk_sz;
	}
	while(la<=ra){
		int x = a[la];
		if(b_idx[x]>=lb && b_idx[x]<=rb) {
			cnt++;
			//cout << la << " : 1 -> 3\n";
		}
		++la;
	}
	return cnt;
}
void update(int l, int r)
{
	int x=b[l], y=b[r];
	upd(a_idx[x]/blk_sz, l,-1);
	upd(a_idx[x]/blk_sz, r,+1);
	upd(a_idx[y]/blk_sz, r,-1);
	upd(a_idx[y]/blk_sz, l,+1);
	b[l] = y, b[r] = x;
	b_idx[y] = l, b_idx[x] = r;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    /* blk_sz = sqrt(n)+1; */
    f1(i,n) {
    	cin >> a[i];
    	a_idx[a[i]] = i;
    }
    f1(i,n) {
    	cin >> b[i];
    	b_idx[b[i]] = i;
    	upd(a_idx[b[i]]/blk_sz, i, +1);
	}
	while(m--){
		int typ;
		cin>>typ;
		if(typ==1){
			int la, ra, lb, rb;
			cin>>la>>ra>>lb>>rb;
			cout << query(la,ra,lb,rb) << "\n";
		}
		else
		{
			int l, r;
			cin>>l>>r;
			update(l,r);
		}
	}
    return 0;
}