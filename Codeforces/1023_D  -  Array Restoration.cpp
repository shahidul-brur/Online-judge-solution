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

const int maxn = (int)2e5+5;
int a[maxn], B[maxn], E[maxn];
struct node{
    node *left, *right;
    int cnt = 0;
    node(int v = 0, node *b = NULL, node *e = NULL):
        cnt(v), left(b), right(e){}

    void build(int l, int r){
        if(l==r) {
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

    node *update(int l, int r, int idx, int add=1){
        if(idx>r || idx<l) return this;
        if(l==r) {
            node *ret = new node(cnt);
            ret->cnt+=add;
            return ret;
        }

        int mid = l + r >> 1;

        node *ret = new node(cnt);
        ret->left = left->update(l, mid, idx);
        ret->right = right->update(mid+1, r, idx);
        ret->cnt = ret->left->cnt + ret->right->cnt;
        return ret;
    }

    int query(int l, int r, int i, int j){
        if(j<l || i>r) return 0;

        if(l>=i && r<=j) return cnt;

        int mid = l + r >> 1;
        return left->query(l, mid, i, j) + right->query(mid+1, r, i, j);
    }
}*root[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, q, z=0, hi=0;
    cin>>n>>q;
    root[0] = new node();
    root[0]->build(0, n);
    f1(i,n) 
    {
        cin>>a[i];
        if(a[i]==0) 
        {
            a[i] = q+1;
            z++;
        }
        if(a[i]==q)
            hi++;
        if(B[a[i]]==0) B[a[i]]=i;
        E[a[i]]=i;
        root[i] = root[i-1]->update(0, n, a[i]);
    }
    if(hi==0 && z==0)
    {
        cout << "NO\n";
        return 0;
    }
    if(z==n || hi==n)
    {
        cout << "YES\n";
        f1(i,n) cout << q << " ";
        cout << "\n";
        return 0;
    }
    if(hi==0)
    {
        f1(i,n) if(a[i]==q+1) 
        {
            a[i] = q;
            hi=1;
            break;
        }
    }
    
    f1(i,q)
    {
        if(B[i]==E[i]) continue;
        int t = root[E[i]-1]->query(0, n, 0, i-1) - root[B[i]]->query(0, n, 0, i-1);
        if(t!=0)
        {
            cout << "NO\n";
            return 0;
        }
    }
    f2(i,2,n)
    {
        if(a[i]==q+1)
        {
            if(a[i-1]!=q+1)
                a[i] = a[i-1];
        }
    }
    fr(i,n-1,1)
    {
        if(a[i]==q+1)
        {
            if(a[i+1]!=q+1)
                a[i] = a[i+1];
        }
    }
    cout << "YES\n";
    f1(i,n)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
