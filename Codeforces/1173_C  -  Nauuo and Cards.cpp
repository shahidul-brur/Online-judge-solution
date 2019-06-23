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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vi p;
    set<int> h;
    int n;
    cin>>n;
    f1(i,n)
    {
        int x;
        cin>>x;
        if(x!=0) h.insert(x);
    }
    f1(i,n)
    {
        int x;
        cin>>x;
        p.pb(x);
    }
    int nx = 1;
    f0(i,n)
    {
        if(p[i]!=1)continue;
        int ok=1;
        f2(j,i,n-1)
        {
            if(p[j]!=nx){
                //cout << j << " " << nx << ": " << p[j] << "..\n";
                ok=0;
                break;
            }
            nx++;
        }
        if(ok) nx = p.back()+1;
        else {
                nx = 1;
                //cout << "!\n";
        }
    }
    if(nx==n+1){
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    int last = 0;
    //cout << nx << " : ";
    while(last<n && h.count(last+1)) ++last;
    f0(i,n)
    {
        cnt++;
        if(h.count(nx)){
            nx++;
            //cout << nx << ", ";
        }
        else nx = last+1;
        if(nx==n+1) break;
        if(p[i]!=0) h.insert(p[i]);
        while(last<n && h.count(last+1)) ++last;
    }
    //if(p.back()==1) nx=2;
    //cout << nx << " : ";
    cnt+=n-nx+1;
    cout << cnt << "\n";
    return 0;
}
