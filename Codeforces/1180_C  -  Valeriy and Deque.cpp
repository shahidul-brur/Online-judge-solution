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
const int maxn = (int)3e5+5;
const int LOGN = 20;
int a[maxn], n, mid, arr[maxn];
ii ans[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q;
    cin>>n>>q;
    int mx = -1;
    deque<int> dq;
    f1(i,n) {
        cin>>a[i];
        dq.pb(a[i]);
        if(a[i]>mx) mx = a[i], mid = i;
    }
    f1(i,mid-1){
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();;
        dq.pop_front();
        ans[i] = mp(a,b);
        if(a>b){
            dq.push_front(a);
            dq.push_back(b);
        }
        else {
            dq.push_front(b);
            dq.push_back(a);
        }
    }
    int i = 1;
    while(dq.size()>0){
        arr[i] = dq.front();
        i++;
        dq.pop_front();
    }
//    f1(i,n) cout << arr[i] << ", ";
//    cout << "\n";
    while(q--)
    {
        ll k;
        cin>>k;
        if(k<mid) cout << ans[k].first << " " << ans[k].second << "\n";
        else{
            k-=mid-1;
            k%=(n-1);
            if(k==0) k = n-1;
            //cout << k << ": ";
            cout << arr[1] << " " << arr[1+k] << "\n";
        }
    }
    return 0;
}
