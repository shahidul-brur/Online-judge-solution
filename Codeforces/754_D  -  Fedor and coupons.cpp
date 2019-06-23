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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
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
const int maxn = (int)7e5+5;
const int LOGN = 20;
int L[maxn], R[maxn], n, k, val;
int l[maxn], r[maxn];
int compr[maxn];
set<int> coupons;
vector<pair<int, ii> > v;
vi add[maxn], rem[maxn];
ordered_set beg;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>k;
    f0(i,n){
        cin>>l[i]>>r[i];
        v.pb(mp(l[i], mp(1,i)));
        v.pb(mp(r[i], mp(2,i)));
    }
    sort(all(v));
    val=1;
    f0(i,2*n){
        if(i>0 && v[i].ff>v[i-1].ff)
            ++val;
        compr[val] = v[i].ff;
        if(v[i].ss.ff==1)
            L[v[i].ss.ss] = val;
        else
            R[v[i].ss.ss] = val;
    }
    f0(i,n){
        add[L[i]].pb(i);
        rem[R[i]].pb(i);
    }
    int mx = 0, b, e;
    f1(i,val){
        for(int x:add[i])
            beg.insert(mp(l[x], x));
        if(beg.size()>=k){
            ii p = *beg.find_by_order(k-1);
            if(compr[i]-p.ff+1>mx){
                //cout << i << ": "<< compr[i] << " " << p.ff << "\n";
                mx = compr[i]-p.ff+1;
                b = p.ff;
                e = compr[i];
            }
        }
        for(int x:rem[i])
            beg.erase(mp(l[x], x));
    }
    //cout << "here..\n";
    set<int> ans;
    f0(i,n){
        if(ans.size()==k) break;
        if(l[i]<=b && r[i]>=e)
            ans.insert(i+1);
    }
    if(ans.size()==0)
        f1(i,k) ans.insert(i);
    cout << mx << "\n";
    for(int x:ans)
        cout << x << " ";
    return 0;
}