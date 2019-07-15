#include<bits/stdc++.h>
using namespace std;
 
#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>
 
#define pb              push_back
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
//             0123456789
const int MX = 100002;
int n;
int a[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, i, j;
    cin>>n>>q;
    //xor[0] = 0;
    for(i=1;i<=n;i++){
        cin>>a[i];
        //xor[i] = xor[i-1] ^ a[i];
    }
    while(q--){
        int tp, pos, x;
        cin>>tp>>pos>>x;
        if(tp==1){
            a[pos] = x;
        }
        else {
            int ans = 0, xx = 0;
            for(i = 1;i<=pos;i++) {
                xx^=a[i];
                if(xx==x) 
                    ans++;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
