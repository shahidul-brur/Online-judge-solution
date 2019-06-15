//Accepted

#include<stdio.h>
int main()
{
    freopen("10450.txt", "r", stdin);
    unsigned long long n,t,i,j,c,arr[55];
    arr[0]=0;
    arr[1]=2;
    arr[2]=3;
    for(i=3;i<=50;i++)
        arr[i]=arr[i-1]+arr[i-2];
    scanf("%llu",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%llu",&n);

        printf("Scenario #%llu:\n",c);
        printf("%llu\n",arr[n]);
        printf("\n");
    }
    return 0;
}
