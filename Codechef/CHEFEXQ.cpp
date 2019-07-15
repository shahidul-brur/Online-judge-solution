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
const int MAX = 1000002;
const int N = 100002;

int arr[N], blk_sz, n, cnt[320][MAX];
int lazy[350], xorr[N];

void update(int idx, int rep)
{
    for (; idx<n && idx%blk_sz != 0; idx++){
        cnt[idx/blk_sz][xorr[idx]]--;
        xorr[idx] ^= rep;
        cnt[idx/blk_sz][xorr[idx]]++;
    }
    
    for(;idx<n;idx+=blk_sz){
        lazy[idx/blk_sz]^=rep;
    }
    
    while(idx<n){
        cnt[idx/blk_sz][xorr[idx]]--;
        xorr[idx] ^= rep;
        cnt[idx/blk_sz][xorr[idx]]++;
        idx++;
    }
}

int query(int idx, int k)
{
    int sum = 0, cur;
    for(cur = 0; (cur+1)*blk_sz-1<=idx; cur++){
        int val = k^lazy[cur];
        sum+=cnt[cur][val];
    }
    
    for(int i = cur*blk_sz;i<=idx;i++){
        if ((xorr[i]^lazy[cur]) == k)CHEFEXQ 
            sum++;
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, i;
    cin>>n>>q;
    blk_sz = sqrt(n);
    cin>>arr[0];
    xorr[0] = arr[0];
    cnt[0][xorr[0]]++;
    for(i=1;i<n;i++){
        cin>>arr[i];
        xorr[i] = xorr[i-1]^arr[i];
        cnt[i/blk_sz][xorr[i]]++;
    }
    
    while(q--){
        int tp, idx, x;
        cin>>tp>>idx>>x;
        --idx;
        
        if(tp==1){
            int rep = arr[idx]^x;
            update(idx, rep);
            arr[idx] = x;
        }
        else {
            int ans = query(idx, x);
            cout << ans << "\n";
        }
    }
    return 0;
}
