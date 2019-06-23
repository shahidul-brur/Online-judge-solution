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
bool big(string a, string b){
    if(b.size()>a.size()) return 1;
    if(b.size()<a.size()) return 0;
    int l = a.size();
    f0(i,l) if(b[i]>a[i])
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q;
    cin>>q;
    while(q--){
        string s;
        int n;
        cin>>n;
        cin>>s;
        if(s.size()==2 && s[0]>=s[1]){
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << "2\n";
            cout << s[0] << " ";
            f1(i,n-1) cout << s[i];
            cout << "\n";
        }
        /*
        string pre;
        pre+=s[0];
        vector<string> ans;
        ans.pb(pre);
        bool ok = 1;
        f1(i,n-1){
            string cur;
            cur+=s[i];
            while(!big(pre,cur) && i+1<n){
                cur+=s[i+1];
                ++i;
            }
            if(!big(pre, cur)){
                ok=0;
            }
            ans.pb(cur);
            pre = cur;
        }
        if(!ok) cout << "NO\n";
        else{
            cout << "YES\n";
            int k = ans.size();
            cout << k << "\n";
            f0(i,k) cout << ans[i] << " ";
            cout << "\n";
        }
        */
    }
    return 0;
}
