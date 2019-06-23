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
char t[3][3];
char s[1005][1005];
int n, m;
bool ok(int r, int c, int x, int y)
{
    int r1 = r-x;
    int c1 = c-y;
    for(int i=r1;i<=r1+2;i++)
        for(int j=c1;j<=c1+2;j++){
            if(i==r1+1 && j==c1+1) continue;
            if(i<0 || i==n || j<0 || j==m || s[i][j] != t[i-r1][j-c1])
                return 0;
        }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    strcpy(t[0], "###");
    strcpy(t[1], "#.#");
    strcpy(t[2], "###");
    cin>>n>>m;
    f0(i,n) cin>>s[i];
    f0(i,n)
    {
        f0(j,m)
        {
            if(s[i][j]=='.') continue;
            bool okk = 0;
            f0(k,3)
            {
                f0(l,3)
                {
                    if(k==1 && l==1) continue;
                    if(ok(i,j,k,l)){
                       // cout << i << ", " << j << ": " << k << ", " << l << "\n";
                        okk=1;
                        break;
                    }
                }
            }
            if(!okk){
                //cout << i << " " << j << ": ";
                cout << "NO\n";
                return 0;
            }
            
        }
    }
    cout << "YES\n";
    return 0;
}


