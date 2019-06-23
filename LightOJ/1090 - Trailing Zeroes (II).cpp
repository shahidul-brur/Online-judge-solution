/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6+2;
int cnt5[maxn], cnt2[maxn], n, r, p, q,t;
int main(){
    for(int i = 1;i<=1000000;i++){
        cnt2[i]= cnt2[i-1], cnt5[i]= cnt5[i-1];
        int c = i; while(c%2==0) cnt2[i]++, c/=2;
        c = i; while(c%5==0) cnt5[i]++, c/=5;
    }
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d%d", &n, &r, &p,&q);
        int c5 = cnt5[n]-cnt5[r] - cnt5[n-r] + (cnt5[p] - cnt5[p-1])*q;
        int c2 = cnt2[n]-cnt2[r] - cnt2[n-r] + (cnt2[p] - cnt2[p-1])*q;
        printf("Case %d: %d\n", cas, min(c2,c5));
    }
    return 0;
}
