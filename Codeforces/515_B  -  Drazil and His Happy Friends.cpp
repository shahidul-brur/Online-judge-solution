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
bool happy_boy[102];
bool happy_girl[102];
bool vis[102][102];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, hb, hg;
    cin>>n>>m;
    cin>>hb;
    f1(i,hb){
    	int boy;
    	cin>>boy;
    	happy_boy[boy] = 1;
    }
    cin>>hg;
    f1(i,hg){
    	int girl;
    	cin>>girl;
    	happy_girl[girl] = 1;
    }
    int i = 0;
    while(1){
    	int b = i%n, g = i%m;
    	if(vis[b][g]) break;
    	happy_boy[b]|=happy_girl[g];
    	happy_girl[g]|=happy_boy[b];
    	vis[b][g] = 1;
    	i++;
    }
    mem(vis,0);
    i = 0;
    while(1){
    	int b = i%n, g = i%m;
    	if(vis[b][g]) break;
    	happy_boy[b]|=happy_girl[g];
    	happy_girl[g]|=happy_boy[b];
    	vis[b][g] = 1;
    	i++;
    }
    int cnt = 0;
    f0(i,n) cnt+=happy_boy[i];
    f0(i,m) cnt+=happy_girl[i];
    if(cnt==n+m) cout << "Yes";
    else cout << "No";
    return 0;
}
