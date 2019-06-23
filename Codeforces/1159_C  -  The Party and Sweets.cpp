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
int b[maxn],g[maxn];
int rem[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll tot=0LL;
    int n,m,bmx=0,gmn=INT_MAX;
    int bmn = INT_MAX, gmx = 0;
    cin>>n>>m;
    f1(i,n)
    {
        cin>>b[i];
        bmx = max(bmx, b[i]);
        bmn = min(bmn, b[i]);
        tot+=b[i]*1LL*m;
    }
    f1(i,m) 
    {
        cin>>g[i];
        gmn=min(gmn,g[i]);
        gmx=max(gmx,g[i]);
    }
    f1(i,n) if(b[i]>gmx)
    {
        cout << "-1\n";
        return 0;
    }
    f1(i,m) if(g[i]<bmx)
    {
        cout << "-1\n";
        return 0;
    }
    
    if(m==1)
    {
        cout << tot << "\n";
        return 0;
    }
    multiset<ii> ms;
    f1(i,n) 
    {
        ms.insert(mp(b[i],i));
        rem[i] = m-1;
    }
    f1(i,m)
    {
        if(g[i]<=bmx) continue;
        if(ms.size()==0){
            cout << "-1\n";
            return 0;
        }
        //cout << i << ": ";
        ii rgt = *ms.rbegin();
        int bb = rgt.ff, id = rgt.ss;
        //cout << bb << "\n";
        tot-=bb;
        tot+=g[i];
        rem[id]--;
        ms.erase(ms.lower_bound(rgt));
        if(rem[id]>0)
            ms.insert(mp(bb,id));
    }
    cout << tot << "\n";
    return 0;
}
