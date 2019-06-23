/*=================================*\
               wrong sol
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100002, MOD = 1000000007;
const int INF = 10000000;
int tree[4*MX][2], a[MX];
void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node][0] = a[l];
        tree[node][1] = INF;
        //cout << node << ": " << l << " -> " << r << " => " << tree[node][0] << ", " << tree[node][1] << "\n";
        return;
    }
    int mid = (l+r)/2;
    int lef = 2*node;
    int rgt = 2*node + 1;
    
    build(lef, l, mid);
    build(rgt, mid+1, r);
    
    int tem[6];
    tem[0] = tree[lef][0];
    tem[1] = tree[lef][1];
    tem[2] = tree[rgt][0];
    tem[3] = tree[rgt][1];
    sort(tem, tem+4);
    tree[node][0] = tem[0];
    tree[node][1] = tem[1];

    //cout << node << ": " << l << " -> " << r << " => ";
    //cout << tree[node][0] << ", " << tree[node][1] << "\n";
    //cout << tree[3][0] << ", " << tree[3][1] << " (rgt)\n";
}

pii query(int node, int tl, int tr, int ql, int qr)
{
    //cout << node << ": " << tl << " -> " << tr << " => ";
    if(tl>=ql && tr<=qr)
    {
        //cout << " relevant ! " << tree[node][0] << " " << tree[node][1] << "\n";
        return {tree[node][0], tree[node][1]};
    }
    if(tl>qr || tr<ql)
    {
        //cout << " INF\n";
        return {INF, INF};
    }
    int mid = (tl+tr)/2;
    int lef = 2*node;
    int rgt = 2*node+1;
    //cout << "Go " << lef << "(" << tl << " -> " << mid << ") and ";
    //cout << rgt << "(" << mid+1 << " -> " << tr << ")\n";
    pii q1 = query(lef, tl, mid, ql, qr);
    pii q2 = query(rgt, mid+1, tr, ql, qr);
    int tem[6];
    tem[0] = q1.first;
    tem[1] = q1.second;
    tem[2] = q2.first;
    tem[3] = q2.second;
    sort(tem, tem+4);
    //cout << "   .... << " << node << ": " << tem[0] << " " << tem[1] << "\n";
    return {tem[0], tem[1]};
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t;
    cin>>t;
    f(cas, 1, t)
    {
        cin>>n>>q;
        f(i, 1, n) cin>>a[i];
        build(1, 1, n);
        cout << "Case " << cas << ":\n";
        f(i, 1, q) 
         {
            int a, b;
            cin>>a>>b;
            ++a;
            ++b;
            //cout << "\n" << a << " -> " << b << ":\n";
            pii ans = query(1, 1, n, a, b);
            cout << ans.second - ans.first << "\n";
        }
    }
    return 0;
}
