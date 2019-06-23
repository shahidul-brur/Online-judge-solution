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
int a[maxn], l[maxn], r[maxn];
int b[maxn], n, m;
vi segId[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    f1(i,n) cin>>a[i];
    f1(i,m){
        cin>>l[i]>>r[i];
        f2(j,l[i],r[i]) segId[j].pb(i);
    }
    int ans, id, mx = a[1], mini = a[1];
    int q = 0;
    f1(i,n){
        mx = max(mx, a[i]);
        mini = min(mini, a[i]);
    }
    ans = mx - mini;
    if(m==0){
        cout << ans << "\n" << "0\n";
        return 0;
    }
    f1(i,n){
        f1(j,n) b[j] = a[j];
        int k = segId[i].size();
        //cout << i << ":\n=========\n";
        f0(j,k){
            int seg = segId[i][j];
            //cout << seg << ", ";
            f2(idx, l[seg], r[seg])
                b[idx]--;
        }
        // cout << "\n ==> ";
        // f1(j,n) cout << b[j] << " ";
        // cout << "\n\n";
        int mx = b[1], mini = b[1];
        f1(j,n) {
            mx = max(b[j], mx);
            mini = min(b[j], mini);

        }
        int cur= mx - mini;
        if(cur>ans){
            ans = cur;
            id = i;
            q = k;
        }
    }
    cout << ans << "\n";
    if(q==0){
        cout << "0\n";
        return 0;
    }
    cout << q << "\n";
    if(q>0){
        f0(i,q) cout << segId[id][i] << " ";
    }
    return 0;
}
