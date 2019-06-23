#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("1024.txt", "r", stdin);
    int t;
    scanf("%llu", &t);
    for(int cas = 1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<total;j++){
            scanf("%llu",&num[j]);
        }
        lcm=num[0];
        for(j=1;j<total;j++)
        {
           lcm=LC(lcm,num[j]);
        }
        printf("Case %llu: %llu\n",i,lcm);
    }
    return 0;
}
