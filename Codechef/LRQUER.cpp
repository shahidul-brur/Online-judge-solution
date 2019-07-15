/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
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
const int MX = 100000;
int tree[4*MX][2]; // 0->mini, 1-> maxi
int arr[MX];
void build(int node, int b, int e){
    if (b == e) {
        tree[node][0] = arr[b];
        tree[node][1] = arr[b];
        return;
    }
    int Left=node<<1, Right=Left|1, mid=(b+e)>>1;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node][0] = min(tree[Left][0], tree[Right][0]);
    tree[node][1] = max(tree[Left][0], tree[Right][0]);
}

int queryMini(int node, int b, int e, int l, int r){
    if (l > e || r < b)  return INT_MAX;
    if (b >= l && e <= r) return tree[node][0];
    int Left=node<<1, Right=Left|1, mid=(b+e)>>1;
    int p1 = queryMini(Left, b, mid, l, r);
    int p2 = queryMini(Right, mid + 1, e, l, r);
    return min(p1, p2);
}
int queryMaxi(int node, int b, int e, int l, int r){
    if (l > e || r < b)  return INT_MIN;
    if (b >= l && e <= r) return tree[node][1];
    int Left=node<<1, Right=Left|1, mid=(b+e)>>1;
    int p1 = queryMaxi(Left, b, mid, l, r);
    int p2 = queryMaxi(Right, mid + 1, e, l, r);
    return max(p1, p2);
}

void update(int node, int b, int e, int ind, int newvalue){
    if (b == e) {
        tree[node][0] = newvalue;
        tree[node][1] = newvalue;
        arr[ind] = newvalue;
        return;
    }
    int mid = (b + e) / 2;
    if(ind<=mid)
        update(2*node, b, mid, ind, newvalue);
    else
        update(2*node+1, mid + 1, e, ind, newvalue);
    tree[node][0] = min(tree[2*node][0], tree[2*node+1][0]);
    tree[node][1] = max(tree[2*node][1], tree[2*node+1][1]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        f(i, 1, n) cin>>arr[i];
        while(q--){
            int tp, L, R, x, y;
            cin>>tp;
            if(tp==1){
                cin>>L>>R;
//                int mini = queryMini(1, 1, n, L, R);
//                int maxi = queryMaxi(1, 1, n, L, R);
//                ll ans = 1LL*(maxi-arr[L])*(arr[R]-mini);
                //ans = max(0LL, ans);
                ll ans = -1000000000000000000;
                f(i, L, R){
                    ans = max(ans, 1LL*(arr[i]-arr[L])*(arr[R]-arr[i]));
                }
                cout << ans << "\n";
            }
            else{
                cin>>x>>y;
                //update(1, 1, n, x, y);
                arr[x] = y;
            }
        }
    }
    return 0;
}

