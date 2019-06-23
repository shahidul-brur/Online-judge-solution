/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
ll n, tree[400010];
void build()
{
    for(int i=n-1;i>0;i--)
        tree[i] = tree[i<<1] + tree[i<<1|1];
}
void modify(int p, ll value)
{
    for(tree[p+=n]+=value;p>1;p>>=1)
        tree[p>>1] = tree[p] + tree[p^1];
}
ll query(int l, int r)
{
    ll res=0;
    for(l+=n, r+=n;l<r;l>>=1, r>>=1)
    {
        if(l&1)
            res+=tree[l++];
        if(r&1)
            res+=tree[--r];
    }
    return res;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cas=1, t, q, i, j, l, r;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=0;i<n;i++)
        {
            cin>>tree[n+i];
        }
        build();
        cout << "Case " << cas++ << ":\n";
        while(q--)
        {
            int typ, p;
            ll val;
            cin>>typ;
            if(typ==1)
            {
                cin>>p;
                cout << tree[n+p] << "\n";
                modify(p, -tree[n+p]);
            }
            else if(typ==2)
            {
                cin>>p>>val;
                modify(p, val);
            }
            else
            {
                cin>>l>>r;
                cout << query(l, r+1) << "\n";
            }
        }
    }
    return 0;
}
