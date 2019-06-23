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
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
char s[510][510];
int cr[510], cc[510];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r, c, st = 0;
    cin>>r>>c;
    f0(i,r) {
        cin>>s[i];
        f0(j,c) {
            st+=s[i][j]=='*';
            cr[i]+=s[i][j]=='*';
            cc[j]+=s[i][j]=='*';
        }
    }
    bool ok=0;
    f1(i,r-2)
    {
        f1(j,c-2)
        {
            if(s[i][j]=='*' && s[i][j-1]=='*' && s[i][j+1]=='*' && s[i+1][j]=='*' && s[i-1][j]=='*'
               && cr[i]+cc[j]-1==st){
                bool tst = 1;
                f2(k,j+2,c-2) if(s[i][k]=='.' && s[i][k+1]=='*') tst=0;
                f2(k,i+2,r-2) if(s[k][j]=='.' && s[k+1][j]=='*') tst=0;
                fr(k,j-2,1) if(s[i][k]=='.' && s[i][k-1]=='*') tst=0;
                fr(k,i-2,1) if(s[k][j]=='.' && s[k-1][j]=='*') tst=0;
                if(tst==1) ok=1;
            }
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
