#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n, x,y,d,a,b,c,ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d",&n, &x, &y, &d);
        a = (abs(x-y)%d==0)?abs(x-y)/d:INT_MAX;
        b = ((y-1)%d==0)?((x-1+d-1)/d + (y-1)/d):INT_MAX;
        c = ((n-y)%d==0)?((n-x+d-1)/d + (n-y)/d):INT_MAX;
        ans = min(a,min(b,c));
        printf("%d\n", (ans==INT_MAX)?-1:ans);
    }
    return 0;
}
