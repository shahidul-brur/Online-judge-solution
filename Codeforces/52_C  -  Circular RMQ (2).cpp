///God help me.
///Created by Al-amin.
///Time : 2018-07-25-14.31

#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 800000;
ll lazy[maxn] , seg[maxn] , arr[200100];
ll mx = 1e18;

void push_down(int x , int l , int r){
    if(lazy[x]){
        int mid = (l + r)/2;
        int left = x * 2;
        int righ = x * 2 + 1;
        if(l != r){
            seg[left] +=  lazy[x];
            seg[righ] +=  lazy[x];
            lazy[left] += lazy[x];
            lazy[righ] += lazy[x];
        }
    }
    lazy[x] = 0;
}
void build(int x , int l , int r){
    if(l == r){
        seg[x] = arr[l];
        lazy[x] = 0;
        return;
    }
    int mid = (l + r)/2;
    build(x * 2 , l , mid);
    build(x * 2 + 1 , mid + 1, r);
    seg[x] = min(seg[x * 2] , seg[x * 2 + 1]);
}

void update(int x , int ss , int se , int qs , int qe , ll v){
    if(lazy[x])push_down(x, ss, se);
    //cout << x << " " << ss << " " << se << " " << qs << " " << qe << endl;
    if (qs <= ss && qe >= se){
        seg[x] +=  v;
        lazy[x] += v;
        push_down(x , ss , se);
        return;
    }
    if (se < qs || ss > qe)
        return;
    int mid = (ss + se)/2;
    update(x * 2, ss , mid , qs , qe , v);
    update(x * 2 + 1, mid + 1 , se , qs , qe , v);
    seg[x] = min(seg[x * 2] , seg[x * 2 + 1]);
}

ll query(int x , int s , int e , int qs , int qe){
    if(lazy[x])push_down(x, s, e);
    if (qs <= s && qe >= e){
        return seg[x];
    }
    if (e < qs || s > qe)
        return mx;
    int mid = (s + e)/2;
    ll lq = query(x * 2 , s , mid , qs , qe);
    ll rq = query(x * 2 + 1 , mid + 1, e , qs , qe);
    return min(lq , rq);
}

int main()
{
    int n , m;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        scanf("%lld",&arr[i]);
    }
    build(1 , 1 , n);
    cin >> m;
    while(m--){
        int tp , l , r , v;
        char c;
        scanf("%d%d%c",&l,&r,&c);
        ++l; ++r;
        if(c != '\n'){
            cin >> v;
            if(r < l){
                update(1,1,n,l,n,v);
                update(1,1,n,1,r,v);
            }
            else update(1 , 1 , n, l , r, v);
        }
        else{
            if(r < l){
                ll pq = query(1 , 1 , n, l , n);
                ll rq = query(1 , 1 , n, 1 , r);
                cout << min(pq,rq) << endl;
            }
            else cout << (query(1 , 1 , n, l , r)) << endl;
        }
    }
    return 0;
}