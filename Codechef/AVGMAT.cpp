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
int ans[1005];
char s[305][305];
int col[305][305], lsum[305][305][610];
int rsum[305][305][610];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, t;
    cin>>t;
    while(t--)
    {
        mem(lsum, 0);
        mem(rsum, 0);
        mem(col, 0);
        mem(ans, 0);
        cin>>n>>m;
        f0(i,n) cin>>s[i];
        /*
        f1(j,m) f1(i,n)
            col[j][i] = col[j][i-1]+s[i][j]-'0';
        */
        f0(i,n) 
        {
            f0(j,m)
            {
                lsum[i][j][i+j] = s[i][j]-'0';
                if(i>0)
                    lsum[i][j][i+j] +=lsum[i-1][j][i+j];
                //cout << i << " " << j << ": " << sum[i][j][i+j] << "\n";
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                
                rsum[i][j][i+m-1-j] = s[i][j]-'0';
                if(i>0)
                    rsum[i][j][i+m-1-j] +=rsum[i-1][j][i+m-1-j];
            }
        }
        f0(i,n) f0(j,m)
        {
            if(s[i][j]=='0') continue;
            for(int k=0;k<=n+m;k++){
                if(i-k>=1)
                    ans[k]+=s[i-k][j] - '0';
                
                if(j>0 && i+j-k>=1){
                ans[i+j-k] +=lsum[i][j-1][k];
                cout << i << ", " << j << " : " << i+j-k << " => " << i << ", " << j-1 << ": " << k << " = ";
                cout << lsum[i][j-1][k] << "\n";
                }
                if(j<m && i+m-j-1-k>=1){
                    ans[i+m-j-1-k] +=rsum[i][j+1][k];
                }
            }
        }
        f1(i,n+m-2)
        {
            if(i>1) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}



