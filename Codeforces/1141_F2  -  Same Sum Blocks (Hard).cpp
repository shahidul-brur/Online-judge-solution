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
const int maxn = 1502;
const int LOGN = 20;
int a[maxn];
vii rng[maxn*maxn];
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,id=0;
    cin>>n;
    f1(i,n) cin>>a[i];
    f1(i,n)
    {
        int s = 0;
        f2(j,i,n) {
            s+=a[j];
            if(m.find(s)==m.end()) m[s]=++id;
            rng[m[s]].pb({j,i});
        }
    }
    
    int ans, mx_len=0;
    f1(i,id)
    {
        sort(all(rng[i]));
        int cur = 0, last = 0;
        for(ii p:rng[i]) if(p.ss>last) cur++, last = p.ff;
        if(cur>mx_len) mx_len = cur, ans = i;
    }
    cout << mx_len << "\n";
    int last = 0;
    for(ii p:rng[ans]) if(p.ss>last){
        cout << p.ss << " " << p.ff << "\n";
        last = p.ff;
    }
    
    return 0;
}
