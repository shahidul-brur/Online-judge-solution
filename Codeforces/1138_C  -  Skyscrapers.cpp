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
const int maxn = 1002;
const int LOGN = 20;
vi row[maxn], col[maxn];
int a[maxn][maxn];
int v[maxn][maxn];
int vv[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    f1(i,n) 
    {
        f1(j,m) 
        {
            cin>>a[i][j];
            row[i].pb(a[i][j]);
            col[j].pb(a[i][j]);
        }
    }
    f1(i,n)
    {
        sort(all(row[i]));
        row[i].erase( unique( row[i].begin(), row[i].end() ), row[i].end());
        f1(j,m)
        {
            v[i][j] = lower_bound(all(row[i]),a[i][j]) - row[i].begin();
        }
    }
    f1(j,m)
    {
        sort(all(col[j]));
        col[j].erase( unique( col[j].begin(), col[j].end() ), col[j].end());
        f1(i,n)
        {
            vv[i][j] = lower_bound(all(col[j]),a[i][j]) - col[j].begin();
        }
    }
    f1(i,n)
    {
        f1(j,m)
        {
            int v1 = row[i].size();
            if(vv[i][j]>v[i][j]) v1+=abs(vv[i][j]-v[i][j]);
            int v2 = col[j].size();
            if(v[i][j]>vv[i][j]) v2+=abs(vv[i][j]-v[i][j]);
            cout << max(v1,v2) << " ";
            
        }
        cout << "\n";
    }
    return 0;
}
