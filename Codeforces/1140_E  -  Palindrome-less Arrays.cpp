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
const int mod = 998244353;
const int maxn = (int)2e5+5;
const int LOGN = 20;
int diff[maxn], same[maxn], pK_1[maxn];
int k;
vi arr[2];
int solve(int idx)
{
    int n = arr[idx].size();
    int ret = 1;
    f0(r,n)
    {
        if(arr[idx][r]!=-1) continue;
        
        int l = r;
        while(r+1<n && arr[idx][r+1]==-1) ++r;
        int len = r-l+1;
        if(l==0 && r==n-1)
            ret = k*1LL*pK_1[len-1]%mod;
        else if(l==0 || r==n-1) 
            ret = ret*1LL*pK_1[len]%mod;
        else if(arr[idx][l-1]==arr[idx][r+1])
            ret = ret*1LL*same[len]%mod;
        else ret = ret*1LL*diff[len]%mod;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x;
    cin>>n>>k;
    pK_1[0] = 1;
    same[1] = k-1, diff[1] = k-2;
    f1(i,n)
    {
        cin>>x;
        if(x!=-1 && arr[i&1].size()>0 && arr[i&1].back()==x){
            cout << "0";
            return 0;
        }
        arr[i&1].pb(x);
        pK_1[i] = pK_1[i-1]*1LL*(k-1)%mod;
        if(i>1) {
            same[i] = diff[i-1]*1LL*(k-1)%mod;
            diff[i] = (diff[i-1]*1LL*(k-2)%mod + same[i-1])%mod;
        }
    }
    cout << solve(0)*1LL*solve(1)%mod;
    return 0;
}
