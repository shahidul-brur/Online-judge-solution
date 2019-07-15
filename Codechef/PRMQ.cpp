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
const int MX = 1000000;
bool p[MX+2];
int a[100005];
int smallest_prime[MX+2], n;
vi factors[MX+2];
int ara[1900005], tot;
int st[MX+2], en[MX+2];

void sieve()
{
    for(int i = 2;i<=MX;i+=2)
        smallest_prime[i] = 2;
    for(int i=3;i<=MX;i+=2)
    {
        if(p[i]==0)
        {
            smallest_prime[i] = i;
            if(i>1000)
                continue;
            for(int j=i;j<=MX/i;j+=2)
                if(!p[i*j])
                    p[i*j]=1, smallest_prime[i*j] = i;
        }
    }
}

void prime_factorize()
{
    for(int i = 2;i<=MX;i++)
    {
        int x = i;
        while(x>1)
        {
            factors[i].pb(smallest_prime[x]);
            x/=smallest_prime[x];
        }
        //sort(all(factors[i]));
    }
}
void make_array()
{
    tot = 0;
    f(i, 1, n)
    {
        int val = a[i];
        int siz = factors[val].sz;
        st[i] = tot+1;
        f(j, 0, siz-1)
        {
            ara[++tot] = factors[val][j];
        }
        en[i] = tot;
    }
}
vi tree[4*1900002];
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].pb(ara[b]);
//        cout << node << " : ";
//        cout << tree[node][0] << "\n";
        return;
    }
    int mid = (b+e)/2;
    int lft = 2*node;
    int rgt = 2*node+1;
    build(lft, b, mid);
    build(rgt, mid+1, e);
    int ls = tree[lft].sz;
    int rs = tree[rgt].sz;
    f(i, 0, ls-1)
        tree[node].pb(tree[lft][i]);
    f(i, 0, rs-1)
        tree[node].pb(tree[rgt][i]);
    sort(all(tree[node]));
//    cout << node << " : ";
//    f(i, 0, ls+rs-1)
//        cout << tree[node][i] << ", ";
//    cout << "\n";
}

int query(int node, int b, int e, int l, int r, int x, int y)
{
    if(e<l || b>r)
        return 0;
    if(b>=l && e<=r)
    {
        int from = lower_bound(all(tree[node]), x) - tree[node].begin();
        int to = upper_bound(all(tree[node]), y) - tree[node].begin();
        return (to-from);
    }
    int mid = (b+e)/2;
    int lft = 2*node;
    int rgt = 2*node+1;
    int q1 = query(lft, b, mid, l, r, x, y);
    int q2 = query(rgt, mid+1, e, l, r, x, y);
    return q1+q2;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    prime_factorize();
    int q, l, r;
    cin>>n;
    f(i, 1, n) cin>>a[i];
    make_array();
    build(1, 1, tot);
    cin>>q;
    while(q--)
    {
        int x, y;
        cin>>l>>r>>x>>y;
        l = st[l];
        r = en[r];
        //cout << l << " -> " << r << " = ";
        int ans = query(1, 1, tot, l, r, x, y);
        cout << ans << "\n";
    }
    return 0;
}

