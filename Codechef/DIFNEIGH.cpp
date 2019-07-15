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
const int LOGN = 20;
int a[52][52];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
    	int n, m;
    	cin>>n>>m;
    	int mx = 0;
    	if(n==1){
    		f0(j,m) {
    			if(j%4<2)
    				a[0][j] = 1;
    			else a[0][j] = 2;
    			mx = max(mx, a[0][j]);
    		}
    	}
    	else if(m==1){
    		f0(i,n) {
    			if(i%4<2)
    				a[i][0] = 1;
    			else a[i][0] = 2;
    			mx = max(mx, a[i][0]);
    		}
    	}
    	else if(n==2 || m==2){
    		f0(i,n){
	    		f0(j,m){
	    			if(n==2)
	    				a[i][j] = j%3 + 1;
	    			else a[i][j] = i%3 + 1;
	    			mx = max(mx, a[i][j]);
	    		}
	    	}
    	}
    	else{
    		f0(i,n){
    			int x,y;
    			if(i%4==0) x = 1, y = 2;
    			else if(i%4==1) x = 3, y = 4;
    			else if(i%4==2) x = 2, y = 1;
    			else x = 4, y = 3;
	    		f0(j,m){
	    			if(j%4<2) a[i][j] = x;
	    			else a[i][j] = y;
	    			mx = max(mx, a[i][j]);
		    	}
	    	}
	    }
    	cout << mx << "\n";
    	f0(i,n){
    		f0(j,m)
    		{
    			if(j>0) cout << " ";
    			cout << a[i][j];
    		}
    		cout << "\n";
    	}
    }
    return 0;
}
