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
const int maxn = 5010;
const int LOGN = 20;
int a[maxn], n,q;
int l[maxn], r[maxn], cnt[maxn][4];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin>>n>>q){
       mem(a,0);
    f1(i,q){
        cin>>l[i]>>r[i];
        a[l[i]]++; a[r[i]+1]--;
    }
    f1(i,n) a[i]+=a[i-1];
    f1(i,n) {
        f0(j,4) cnt[i][j] = cnt[i-1][j];
        if(a[i]>3) a[i] = 3;
        cnt[i][a[i]]++;
    }
    int mx = 0;
    f1(i,q-1){
        f2(j, i+1, q){
            int l1 = l[i], r1 = r[i];
            int l2 = l[j], r2 = r[j];
            int l3 = 0, r3 = -1;
//            if(l1==l2 && r1==r2){
//                l3 = l1, r3 = r1;
//                l1=l2=r1=r2=0;
//            }
//            else{
                    
                if(l2<l1 || (l2==l1 && r2<r1)){
                    swap(l1, l2);
                    swap(r1, r2);
                }
                if(r1>=l2){
                    l3 = l2;
                    r3 = min(r1,r2);
                    r2 = max(r1,r2);
                    r1 = l2 - 1;
                    l2 = r3+1;
                }
            //}
//            cout << l[i] << " " << r[i] << " => " << l[j] << " " << r[j] << ":\n==========\n";
//            cout << l1 << " " << r1 << "\n";
//            cout << l2 << " " << r2 << "\n";
//            cout << l3 << " " << r3 << "\n";
            int zero = cnt[n][0];
            //cout << zero << " # ";
            if(r1>=l1) {
                    zero+=cnt[r1][1]-cnt[l1-1][1];
            }
            if(r3>=l3) {
                zero+=cnt[r3][2]-cnt[l3-1][2];
            }
            if(r2>=l2) {
                    zero+=cnt[r2][1] - cnt[l2-1][1];
            }
            mx = max(mx, n-zero);
        }
    }
    cout << mx << "\n";
    }
    return 0;
}
