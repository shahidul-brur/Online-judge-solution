#include <bits/stdc++.h>
using namespace std;
 
const int MX = 1e5+2;
int tree[4*MX][3];
int lazy[4*MX];
void propagate(int node, int b, int e)
{
    lazy[node]%=3;
    if(lazy[node]==0)
        return;
    for(int i = 1;i<=lazy[node];i++){
        swap(tree[node][0], tree[node][1]);
        swap(tree[node][0], tree[node][2]);
    }
    if(b!=e){
        lazy[2*node]+=lazy[node];
        lazy[2*node]%=3;
        lazy[2*node+1]+=lazy[node];
        lazy[2*node+1]%=3;
    }
    lazy[node] = 0;
}
void build(int node, int b, int e)
{
    if (b == e){
        tree[node][0] = 1;
        tree[node][1] = 0;
        tree[node][2] = 0;
        lazy[node] = 0;
        return;
    }
    
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node][0] = tree[Left][0] + tree[Right][0];
    tree[node][1] = tree[node][2] = 0;
    lazy[node] = 0;
}
 
int query(int node, int b, int e, int l, int r)
{
    propagate(node, b, e);
    if(l>e || r<b)
        return 0;
    if(b>=l && e<=r)
        return tree[node][0];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    return query(Left, b, mid, l, r)+query(Right, mid + 1, e, l, r);
}
 
void update(int node, int b, int e, int l,int r)
{
    propagate(node, b, e);
    if(l>e || r<b)
        return;
    if(b>=l && e<=r){
        lazy[node]++;
        propagate(node, b, e);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, l, r);
    update(Right, mid + 1, e, l, r);
    tree[node][0] = tree[Left][0] + tree[Right][0];
    tree[node][1] = tree[Left][1] + tree[Right][1];
    tree[node][2] = tree[Left][2] + tree[Right][2];
}
 
int main()
{
    int n,q,l,r,typ,t;
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d %d", &n, &q);
        build(1,1,n);
        printf("Case %d:\n",cas);
        while(q--){
            scanf("%d %d %d", &typ, &l, &r);
            ++l; ++r;
            if(typ==0)
                update(1,1,n,l,r);
            else
                printf("%d\n", query(1,1,n,l,r));
        }
    }
    return 0;
}
