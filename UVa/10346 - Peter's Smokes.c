//Accepted
#include<stdio.h>
int main()
{
    int a, b,ans;
    while(scanf("%d %d",&a,&b)!=EOF){
        ans=a;
        while(a>=b){
            ans+=a/b;
            a=a/b+(a%b);
        }
        printf("%d\n",ans);
    }
    return 0;
}
