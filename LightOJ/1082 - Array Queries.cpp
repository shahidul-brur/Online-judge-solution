//Accepted

#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long

// ---------------- typedef ------------------------------
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

// --------------   template ends  ------------------------

int n, q;
int a[100005], st[300005];
void init(int node, int b, int e)
{
    if(b==e)
        st[node] = a[b];
    else
    {
        int mid = (b+e)/2;
        int left = 2*node;
        int right = 2*node+1;
        init(left, b, mid);
        init(right, mid+1, e);
        
        st[node] = min(st[left], st[right]);
    }
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 1e9;
    if(i<=b && j>=e) return st[node];
    else
    {
        int mid = (b+e)/2;
        int left = 2*node;
        int right = 2*node+1;
        
        int p1 = query(left, b, mid, i, j);
        int p2 = query(right, mid+1, e, i, j);
        
        return min(p1,p2);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, cas, i, j, q, from, to;
    scanf("%d", &test);
    F(cas,1,test)
    {
        scanf("%d %d", &n, &q);
        F(i, 1, n)
        {
            scanf("%lld", &a[i]);
        }
        mem(st, 0);
        init(1, 1, n);
        
        printf("Case %d:\n", cas);
        F(i, 1, q)
        {
            scanf("%d %d", &from, &to);
            printf("%lld\n", query(1, 1, n, from, to));
        }
    }
    return 0;
}
