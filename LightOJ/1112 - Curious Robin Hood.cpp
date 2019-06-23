//ACCEPTED

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

ll ar[100005], segTree[400005];
void init(int node, int b, int e)
{
    if(b==e)
    {
        segTree[node]=ar[b];
        return;
    }
    int mid = (b+e)/2;
    int left = 2*node;
    int right = 2*node + 1;
    init(left, b, mid);
    init(right, mid+1, e);
    segTree[node]=segTree[left]+segTree[right];
}

void update(int node, int b, int e, int i, int newVal)
{
    if(i<b || i>e)
        return;
        
    if(i==b && i==e)  // if(b==e) gives TLE 
    {
        segTree[node]+=newVal;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = left + 1;
    update(left, b, mid, i, newVal);
    update(right, mid+1, e, i, newVal);
    segTree[node] = segTree[left] + segTree[right];
}

ll query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return segTree[node];
    int mid = (b+e)/2;
    int left = node*2;
    int right = left + 1;
    
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    
    return p1+p2;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, cas, i, j, q, n, from, to, act, id;
    ll val;
    scanf("%d", &test);
    F(cas, 1, test)
    {
        scanf("%d %d", &n, &q);
        F(i, 1, n)
        {
            scanf("%lld", &ar[i]);
        }
        init(1, 1, n);
        printf("Case %d:\n", cas);
        F(i, 1, q)
        {
            scanf("%d", &act);
            if(act==1)
            {
                scanf("%d", &id);;
                id++;
                val = ar[id];
                printf("%d\n", val);
                ar[id]=0;
                update(1, 1, n, id, -val);
            }
            else if(act==2)
            {
                scanf("%d %lld", &id, &val);
                id++;
                ar[id] +=val; 
                update(1, 1, n, id, val);
            }
            else
            {
                scanf("%d %d", &from, &to);
                from++, to++;
                printf("%lld\n",query(1, 1, n, from, to));
            }
        }
    }
    return 0;
}
