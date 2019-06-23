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
const int MX = 200005;
int ara[MX];
struct node
{
    node *left, *right;
    int cnt = 0;
    node(int v = 1, node *b = NULL, node *e = NULL):
        cnt(v), left(b), right(e){}
        
    void build(int l, int r)
    {
        if(l==r) 
        {
            cnt = 0;
            return;
        }
        int mid = l+r>>1;
        left = new node();
        right = new node();
        left->build(l, mid);
        right->build(mid+1, r);
        cnt = left->cnt + right->cnt;
    }
    
    node *update(int l, int r, int idx)
    {
        if(idx>r || idx<l) return this;
        if(l==r) {
            node *ret = new node(cnt);
            ret->cnt+=1;
            return ret;
        }
        
        int mid = l + r >> 1;
        
        node *ret = new node(cnt);
        ret->left = left->update(l, mid, idx);
        ret->right = right->update(mid+1, r, idx);
        ret->cnt = ret->left->cnt + ret->right->cnt;
        return ret;
    }
    
    int query(int l, int r, int i, int j)
    {
        if(j<l || i>r) return 0;
        
        if(l>=i && r<=j) return cnt;
        
        int mid = l + r >> 1;
        return left->query(l, mid, i, j) + right->query(mid+1, r, i, j);
    }
}*root[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    root[0] = new node();
    root[0]->build(1, n);
    for(int i = 1;i<=n;i++)
    {
        cin>>ara[i];
        root[i] = root[i-1]->update(1, n, ara[i]);
    }
    int l,r, u, d;
    while(q--)
    {
        cin>>l>>d>>r>>u;
        
        ll ans = 0LL;
        
        int les_d_L = root[l-1]->query(1, n, 1, d-1);
        int les_eq_u_L = root[l-1]->query(1, n, 1, u) - les_d_L;
        int gret_u_L = l-1 - les_eq_u_L - les_d_L;
        
        int les_d_full = root[n]->query(1, n, 1, d-1);
        int les_eq_u_full = root[n]->query(1, n, 1, u) - les_d_full;
        int gret_u_full = n - les_eq_u_full-les_d_full;
        
        int les_d_R = root[r]->query(1, n, 1, d-1);
        int les_eq_u_R = root[r]->query(1, n, 1, u) - les_d_R;
        int gret_u_R = r - les_eq_u_R -les_d_R;
        
        int les_d_M = les_d_R - les_d_L;
        int les_eq_u_M = les_eq_u_R - les_eq_u_L;
        int gret_u_M = gret_u_R - gret_u_L;
        
        int les_d_r = les_d_full - les_d_R;
        int les_eq_u_r = les_eq_u_full - les_eq_u_R;
        int gret_u_r = gret_u_full - gret_u_R;
        
        //cout << les_d_M << ", ";
        //cout << les_eq_u_M << ", ";
        //cout << gret_u_M << " => ";
        
        ans+=1LL*les_eq_u_M*(les_eq_u_M-1)/2;
        ans+=1LL*les_d_L * (gret_u_M + les_eq_u_M + les_eq_u_r + gret_u_r);
        ans+=1LL*les_eq_u_L * (gret_u_M + les_eq_u_M + les_d_M + les_d_r + les_eq_u_r + gret_u_r);
        ans+=1LL*gret_u_L * (les_eq_u_M + les_d_M + les_d_r + les_eq_u_r);
        
        ans+=1LL*les_d_M * (gret_u_M + les_eq_u_M + les_eq_u_r + gret_u_r);
        ans+=1LL*les_eq_u_M * (gret_u_M + les_d_r + les_eq_u_r + gret_u_r);
        ans+=1LL*gret_u_M * (les_d_r + les_eq_u_r);
        
        cout << ans << "\n";
    }
    return 0;
}
