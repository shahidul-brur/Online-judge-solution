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
std::vector<pair<string, int>> v;
bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.ff.length()<b.ff.length();
}
char ans[300];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    f0(i,2*n-2){
        string s; cin>>s;
        v.pb(mp(s,i));
    }
    sort(all(v), cmp);
    string pref, suff;
    pref = v[0].ff, suff = v[1].ff;
    ans[v[0].ss] = 'P';
    ans[v[1].ss] = 'S';
    bool ok=1;
    for(int i = 3;i<2*n-2;i+=2){
        string a = v[i-1].ff, b = v[i].ff;
        if(pref+a.back()==a && b[0]+suff==b){
            pref = a, suff = b;
            ans[v[i-1].ss] = 'P';
            ans[v[i].ss] = 'S';
        }
        else if(pref+b.back()==b && a[0]+suff==a)
        {
            pref = b, suff = a;
            ans[v[i-1].ss] = 'S';
            ans[v[i].ss] = 'P';
        }
        else {
            ok=0;
            break;
        }
    }
    if(!ok){
        suff = v[0].ff, pref = v[1].ff;
        ans[v[0].ss] = 'S';
        ans[v[1].ss] = 'P';
        for(int i = 3;i<2*n-2;i+=2){
            string a = v[i-1].ff, b = v[i].ff;
            if(pref+a.back()==a && b[0]+suff==b){
                pref = a, suff = b;
                ans[v[i-1].ss] = 'P';
                ans[v[i].ss] = 'S';
            }
            else if(pref+b.back()==b && a[0]+suff==a)
            {
                pref = b, suff = a;
                ans[v[i-1].ss] = 'S';
                ans[v[i].ss] = 'P';
            }
        }
    }
    ans[2*n-2] = '\0';
    cout << ans << "\n";
    return 0;
}
