/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1000005
#define inf             1e9

int tree[4*N], a[N];
void build(int v, int b, int e)
{
    if(b==e)
    {
        tree[v] = a[b];
        return;
    }
    int m = (b+e)>>1;
    int l=2*v, r=l+1;
    build(l, b, m);
    build(r, m+1, e);
    tree[v] = tree[l]*tree[r];
}

void update(int v, int b, int e, int pos, int val)
{
    if(pos>e || pos<b)
        return;
    if(b==e)
    {
        tree[v] = val;
        return;
    }
    int m = (b+e)>>1;
    int l=2*v, r=l+1;
    update(l, b, m, pos, val);
    update(r, m+1, e, pos, val);
    tree[v] = tree[l]*tree[r];
}
int query(int v, int b, int e, int l, int r)
{
    if(r<b || l>e)
        return 1;
    if(b>=l && e<=r)
        return tree[v];
    int m = (b+e)>>1;
    return query(2*v, b, m, l, r)*query(2*v+1, m+1, e, l, r);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    while(cin>>n>>q)
    {
        rep1(i, n)
        {
            int x;
            cin>>x;
            if(x<0)
                x = -1;
            else if(x>0)
                x = 1;
            a[i] = x;
        }
        build(1, 1, n);
        while(q--)
        {
            char cmd;
            int l, r, ans, pos, val;
            cin>>cmd;
            
            if(cmd=='C')
            {
                cin>>pos>>val;
                if(val<0)
                    val = -1;
                else if(val>0)
                    val = 1;
                update(1, 1, n, pos, val);
            }
            else
            {
                cin>>l>>r;
                ans = query(1, 1, n, l, r);
                if(ans==1)
                    cout << "+";
                else if(ans<0)
                    cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}
