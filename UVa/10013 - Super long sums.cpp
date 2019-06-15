//Accepted
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("10013.txt", "r", stdin);
    int i,c,t,n,carry;
    vector <int> f(1000005),s(1000005),ans(1000005);
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&f.at(i),&s.at(i));
        }
        carry=0;
        for(i=n;i>=1;i--)
        {
            ans[i]=(carry+f.at(i)+s.at(i))%10;
            carry=(carry+f.at(i)+s.at(i))/10;
        }
        if(c>1)
            printf("\n");
        for(i=1;i<=n;i++)
        {
            printf("%d",ans.at(i));
        }
        printf("\n");
    }
    return 0;
}
