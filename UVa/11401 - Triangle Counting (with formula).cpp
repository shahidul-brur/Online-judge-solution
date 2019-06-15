#include<bits/stdc++.h>
using namespace std;
unsigned long long tri[1000002];
int main()
{
    //freopen("in.txt", "r", stdin);
    unsigned long long cnt, n,i,step;
    for(i=4;i<=1000000;i++){
        step=i-3;
        if(step%2==0)
            tri[i]=tri[i-1]+2*(step/2)*(step/2+1)/2;
        else tri[i]=tri[i-1]+2*(step/2)*(step/2+1)/2 + step/2+1;
    }
    while(scanf("%llu",&n)&&n>=3){
        printf("%llu\n",tri[n]);
    }
    return 0;
}
