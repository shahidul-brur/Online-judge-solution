#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,i,ans;
    while(scanf("%ld",&n)!=EOF)
    {
        long num = 0;
        for(i=1;;i++){
            num = num*10 + 1;
            if(num%n==0){
                ans=i;
                break;
            }
            num%=n;
        }
        printf("%ld\n",ans);
    }
    return 0;
}