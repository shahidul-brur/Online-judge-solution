//Accepted
#include<stdio.h>
#include<string.h>
struct web{
char link[110];
int rank;
};
int main()
{
    freopen("12015.txt", "r", stdin);
    struct web in[12];
    int t,i,c,max;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        max=0;
        for(i=1;i<=10;i++)
        {
            scanf("%s",&in[i].link);
            scanf("%d",&in[i].rank);
            if(in[i].rank>max)
            {
                max=in[i].rank;
            }
        }
        printf("Case #%d:\n",c);
        for(i=1;i<=10;i++)
        {
            if(in[i].rank==max)
                printf("%s\n",in[i].link);
        }
    }
    return 0;
}
