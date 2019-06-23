/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;
const int MX = 100002;
int ara[MX];
struct Node{
    int lVal, rVal;
    int lCnt, rCnt;
    int mxCnt;
}node[4*MX];
void build(int cur, int b, int e)
{
    if(b==e){
        node[cur].lVal = node[cur].rVal = ara[b];
        node[cur].lCnt = node[cur].rCnt = node[cur].mxCnt = 1;
        return;
    }
    int m = (b+e)/2,L = cur*2,R=L+1;
    build(L, b, m);
    build(R, m+1, e);
    node[cur].lVal = node[L].lVal;
    node[cur].rVal = node[R].rVal;;
    node[cur].lCnt = node[L].lCnt;
    node[cur].rCnt = node[R].rCnt;
    node[cur].mxCnt = max(node[L].mxCnt,node[R].mxCnt);
    
    if(node[L].rVal==node[R].lVal){
        node[cur].mxCnt = max(node[cur].mxCnt, node[L].rCnt+node[R].lCnt);
        if(node[L].lVal==node[L].rVal)
            node[cur].lCnt += node[R].lCnt;
        if(node[R].lVal==node[R].rVal)
            node[cur].rCnt+=node[L].rCnt;
    }
}
int query(int cur, int b, int e, int l, int r){
    if(r<b || l>e)
        return -1;
    if(b>=l && e<=r) return node[cur].mxCnt;
    int m = (b+e)/2, L=cur*2,R=L+1;
    int qL = query(L, b, m, l, r);
    int qR = query(R, m+1, e, l, r);
    int ans = max(qL, qR);
    if(node[L].rVal==node[R].lVal){
        int lc, rc;
        lc = min(m-l+1, node[L].rCnt);
        rc = min(r-m, node[R].lCnt);
        ans = max(ans, lc+rc);
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, q;
    while(scanf("%d",&n) && n!=0){
        scanf("%d",&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        build(1, 1, n);
        while(q--){
            int l, r;
            scanf("%d %d", &l, &r);
            int ans = query(1, 1, n, l, r);
            printf("%d\n", ans);
        }
    }
    return 0;
}
