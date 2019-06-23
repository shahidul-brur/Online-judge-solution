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
int dx4[] = {0,0,1,-1};
int dy4[] = {1,-1,0,0};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
char s[1003][1003];
//int vis[1003][1003];
int sp[12], cnt[11], n, m, p, step;
void bfs(){
	queue<pair<ii, int> > q[2][12];
	f0(i,n){
    	f0(j,m){
    		if(s[i][j]>='1' && s[i][j]<='9'){
    			q[0][s[i][j]-'0'].push(mp(mp(i,j), 0));
    		}
    	}
    }
    int lev = 0;
    while(1){
    	int mov = 0;
	    f1(player, p){
			while(!q[lev][player].empty()){
				pair<ii, int> state = q[lev][player].front();
				int r = state.ff.ff;
				int c = state.ff.ss;
				int t = state.ss;
				q[lev][player].pop();

				if(t==sp[player]){
					state.ss = 0;
					q[lev^1][player].push(state);
					mov=1;
					continue;
				}
				f0(i,4){
					int rr = r+dx4[i];
					int cc = c+dy4[i];
					if(rr<0 || rr>=n || cc<0 || cc>=m || s[rr][cc]!='.')
						continue;
					q[lev][player].push(mp(mp(rr,cc), t+1));
					s[rr][cc] = '0'+player;
				}
			}
		}
		if(mov==0)
			break;
		lev^=1;
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin>>n>>m>>p){
    	mem(cnt, 0);
	    f1(i,p) cin>>sp[i];
	    f0(i,n){
	    	cin>>s[i];
	    }
	    bfs();
	    f0(i,n) f0(j,m) if(s[i][j]>='1' && s[i][j]<='9')
	    	cnt[s[i][j]-'0']++;
	    f1(i,p)
	    	cout << cnt[i] << " ";
	    cout << "\n";
	}
    return 0;
}
