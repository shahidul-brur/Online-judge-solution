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
int c[maxn], a[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, val, mx = 0;
    cin>>n;
    f1(i,n)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    f0(i,maxn) if(c[i]>mx){
        val = i;
        mx = c[i];
    }
    vi pos;
    f1(i,n) if(a[i]==val)
    {
        if((i>1 && a[i-1]!=val) || (i<n && a[i+1]!=val))
            pos.pb(i);
    }
    cout << n - mx << "\n";
    while(pos.size()>0)
    {
        int p = pos.back();
        pos.pop_back();
        if(p>1 && a[p-1]!=val){
            if(a[p-1]<val) cout << "1 ";
            else cout << "2 ";
            cout << p-1 << " " << p << "\n";
            a[p-1] = val;
            if(p-1>1 && a[p-2]!=val) pos.pb(p-1);
        }
        if(p<n && a[p+1]!=val){
            if(a[p+1]<val) cout << "1 ";
            else cout << "2 ";
            cout << p+1 << " " << p << "\n";
            a[p+1] = val;
            if(p+1<n && a[p+2]!=val) pos.pb(p+1);
        }
    }
    return 0;
}
