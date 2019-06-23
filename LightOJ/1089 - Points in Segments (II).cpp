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
const int maxn = (int)5e4+5;
const int LOGN = 20;
int l[maxn], r[maxn], p[maxn], ans[maxn];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    f1(cas,t)
    {
        int n,q;
        scanf("%d %d",&n, &q);
        vector<pair<int, ii> > pts;
        f1(i,n) 
        {
            scanf("%d %d", &l[i],&r[i]);
            pts.pb(mp(l[i], mp(0,i)));
            pts.pb(mp(r[i], mp(2,i)));
        }
        
        f1(i,q) 
        {
            scanf("%d",&p[i]);
            pts.pb(mp(p[i], mp(1,i)));
        }
        sort(all(pts));
        int cnt = 0;
        int siz = pts.size();
        f0(i,siz)
        {
            if(pts[i].ss.ff==1) ans[pts[i].ss.ss]=cnt;
            if(pts[i].ss.ff==0) ++cnt;
            if(pts[i].ss.ff==2) --cnt;
        }
        printf("Case %d:\n", cas);
        f1(i,q) printf("%d\n",ans[i]);
    }
    return 0;
}



