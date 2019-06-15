#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11340.txt", "r", stdin);
    int t,p,line,len,i,j,k,val[110];
    double sum,ans;
    char art[10020], ch[110];
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            while (getchar() != '\n');
            scanf("%c %d",&ch[i],&val[i]);
        }

        scanf("%d",&line);
        while (getchar() != '\n');
        while(line--)
        {
            gets(art);
            len=strlen(art);
            for(i=0;i<len;i++)
            {
                for(j=0;j<p;j++)
                {
                    if(art[i]==ch[j])
                    {
                        sum+=val[j];
                        break;
                    }
                }
            }
        }
        ans=sum/100;
        printf("%.2lf$\n",ans);
    }
    return 0;
}
