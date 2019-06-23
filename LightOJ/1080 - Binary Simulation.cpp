#include <bits/stdc++.h>
using namespace std;
 
const int MX = 1e5+3;
int tree[4*MX];
bool lazy[4*MX];
char s[MX];
void propagate(int node, int b, int e)
{
    if(lazy[node]==0)
        return;
    tree[node]^=1;
    if(b!=e){
        lazy[2*node]^=1;
        lazy[2*node+1]^=1;
    }
    lazy[node] = 0;
}
void build(int node, int b, int e)
{
    if (b == e){
        tree[node] = (s[b]=='1');
        lazy[node] = 0;
        return;
    }
    
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    lazy[node] = 0;
}
 
int query(int node, int b, int e, int idx)
{
    propagate(node, b, e);
    if(b==idx && e==idx) 
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    if(idx<=mid)
        return query(Left, b, mid, idx);
    else return query(Right, mid+1, e, idx);
}
 
void update(int node, int b, int e, int l,int r)
{
    propagate(node, b, e);
    if(l>e || r<b)
        return;
    if(b>=l && e<=r){
        lazy[node] ^= 1;
        propagate(node, b, e);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, l, r);
    update(Right, mid + 1, e, l, r);
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,q,t;
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%s", s+1);
        printf("Case %d:\n", cas);
        n = strlen(s+1);
        build(1,1,n);
        scanf("%d",&q);
        while(q--){
            char Q[5];
            scanf("%s", Q);
            if(Q[0]=='I')
            {
                int l, r;
                scanf("%d %d", &l, &r);
                update(1,1,n,l,r);
            }
            else
            {
                int idx;
                scanf("%d", &idx);
                printf("%d\n", query(1,1,n,idx));
            }
        }
    }
    return 0;
}
