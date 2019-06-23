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
int a[405], m[21][21];
int cnt[1001];
vi occ[4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    set<int> st;
    cin>>n;
    int t=n*n;
    f1(i,t) {
        cin>>a[i];
        st.insert(a[i]);
        cnt[a[i]]++;
    }
    for(int x:st) {
        fr(k,4,1){
            f1(i,cnt[x]/k){
                if(k==4) f1(j,4) occ[0].pb(x);
                else if(k==3) occ[2].pb(x), occ[2].pb(x), occ[1].pb(x);
                else f1(j,k) occ[k].pb(x);
            }
            cnt[x]%=k;
        }
    }
    if(n&1){
        // cout << occ[1].size() << " - 1\n";
        // cout << occ[2].size() << " - 2\n";
        // cout << occ[0].size() << " - 4\n";
        if(occ[1].size()!=1 || occ[2].size()>2*(n-1)){
            cout << "NO\n";
            return 0;
        }
    }
    else{
        if(occ[0].size()!=t){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    sort(all(occ[0]));
    sort(all(occ[2]));
    if(n&1){
        m[n/2+1][n/2+1] = occ[1].back();
        f1(i,n/2){
            if(occ[2].size()>0){
                m[i][n/2+1] = occ[2].back();
                occ[2].pop_back();
                m[n-i+1][n/2+1] = occ[2].back();
                occ[2].pop_back();
            }
            else{
                m[i][n/2+1] = occ[0].back();
                occ[0].pop_back();
                m[n-i+1][n/2+1] = occ[0].back();
                occ[0].pop_back();
            }

            if(occ[2].size()>0){
                m[n/2+1][i] = occ[2].back();
                occ[2].pop_back();
                m[n/2+1][n-i+1] = occ[2].back();
                occ[2].pop_back();
            }
            else{
                m[n/2+1][i] = occ[0].back();
                occ[0].pop_back();
                m[n/2+1][n-i+1] = occ[0].back();
                occ[0].pop_back();
            }
        }
    }
    f1(i, n/2){
        f1(j,n/2){
            m[i][j] = occ[0].back();
            occ[0].pop_back();
            m[i][n-j+1] = occ[0].back();
            occ[0].pop_back();

            m[n-i+1][j] = occ[0].back();
            occ[0].pop_back();
            m[n-i+1][n-j+1] = occ[0].back();
            occ[0].pop_back();
        }
    }
    f1(i,n){
        f1(j,n){
            if(j>1) cout << " ";
            cout << m[i][j];
        } 
        cout << "\n";
    }
    return 0;
}
