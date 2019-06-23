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
map<pair<deque<int>, deque<int>>, bool> vis;
int cnt, win=-1;
void visit(deque<int> v1, deque<int> v2)
{
    if(v1.size()==0)
    {
        win=2;
        return;
    }
    if(v2.size()==0) 
    {
        win=1;
        return;
    }
    if(vis.find(mp(v1,v2))!=vis.end())
        return;
    ++cnt;
    vis[mp(v1,v2)]=1;
    int x1 = v1.front(); v1.pop_front();
    int x2 = v2.front(); v2.pop_front();
    if(x1>x2){
        v1.pb(x2);
        v1.pb(x1);
    }
    else
    {
        v2.pb(x1);
        v2.pb(x2);
    }
    visit(v1,v2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k1,k2;
    cin>>n;
    cin>>k1;
    deque<int> v1, v2;
    f1(i,k1){
        int x; cin>>x;
        v1.pb(x);
    }
    cin>>k2;
    f1(i,k2){
        int x; cin>>x;
        v2.pb(x);
    }
    visit(v1,v2);
    if(win==-1) cout << "-1";
    else cout << cnt << " " << win;
    return 0;
}
