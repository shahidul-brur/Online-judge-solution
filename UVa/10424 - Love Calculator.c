//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("10424.txt", "r", stdin);
    char b[30], g[30];  //one for boy and other for girl
    int i,sb,sg,r,d,sum;  //sb and sg for digit sum value of boy and girl, r for remainder,
                         //sum for temporary summation, d for divisor
    float ans;   //ans for desired output
    while(gets(b))
    {
        gets(g);
        sb=sg=0;   //initialize
        for(i=0;i<strlen(b);i++)
        {
            if(b[i]>64 &&b[i]<91)
                sb+=b[i]-64;
            else if(b[i]>96 &&b[i]<123)
                sb+=b[i]-96;

        }
        while(sb>9)
        {
            sum=0;
            d=sb;
            while(d!=0)
            {
                r=d%10;
                sum+=r;
                d=d/10;
            }
            sb=sum;
        }

        for(i=0;i<strlen(g);i++)
        {
            if(g[i]>64 &&g[i]<91)
                sg+=g[i]-64;
            else if(g[i]>96 &&g[i]<123)
                sg+=g[i]-96;

        }
        while(sg>9)
        {
            sum=0;
            d=sg;
            while(d!=0)
            {
                r=d%10;
                sum+=r;
                d=d/10;
            }
            sg=sum;
        }

        if(sb==sg)
            printf("100.00 %%\n");
        else if(sb<sg)
        {
            ans=(float)sb*100/sg;
            printf("%.2f %%\n",ans);
        }
        else if(sg<sb)
        {
            ans=(float)sg*100/sb;
            printf("%.2f %%\n",ans);
        }
    }
    return 0;
}
