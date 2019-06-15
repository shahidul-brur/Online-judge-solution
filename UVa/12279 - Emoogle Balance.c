//Accepted
#include<stdio.h>
int main()
{
    int given, toGive,n,i,c=1,in;
    while(scanf("%d",&n) && n!=0)
    {
        given=toGive=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&in);
            if(in==0)
                given++;
            else toGive++;
        }
        printf("Case %d: %d\n",c,toGive-given);
        c++;
    }
    return 0;
}
