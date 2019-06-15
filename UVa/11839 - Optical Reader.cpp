//Accepted
#include<stdio.h>
int main()
{
    freopen("11839.txt", "r", stdin);
    int n,a,b,c,d,e,i,mark;
    char ans;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            mark=0;
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
            if(a<=127)
            {
                ans='A';
                mark++;
            }
            if(b<=127)
            {
                ans='B';
                mark++;
            }
            if(c<=127)
            {
                ans='C';
                mark++;
            }
            if(d<=127)
            {
                ans='D';
                mark++;
            }
            if(e<=127)
            {
                ans='E';
                mark++;
            }
            if(mark==1)
                printf("%c\n",ans);
            else
                printf("*\n");

        }
    }
    return 0;
}
