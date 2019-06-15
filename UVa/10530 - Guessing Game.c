//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10530.txt", "r", stdin);
    char str[20];
    int n,b,h[5000],l[5000],r,i,j,k,dis;
    while(scanf("%d",&n)&&n!=0)
    {
        dis=i=j=b=0;
        getchar();
        gets(str);
        if(str[4]=='h')
        {
            h[i]=n;
            i++;
        }
        else if(str[4]=='l')
        {
            l[j]=n;
            j++;
        }
        if(str[0]=='r')
            b=1;
        while(b!=1)
        {
            scanf("%d",&n);
            getchar();
            gets(str);
            if(str[0]=='r')
            {
                b=1;
                r=n;
                break;
            }
            if(str[4]=='h')
            {
                h[i]=n;
                i++;
            }
            else if(str[4]=='l')
            {
                l[j]=n;
                j++;
            }
        }
        for(k=0;k<i;k++)
        {
            if(h[k]<=r)
            {
                dis=1;
                break;
            }
        }
        for(k=0;k<j;k++)
        {
            if(l[k]>=r)
            {
                dis=1;
                break;
            }
        }
        if(dis==0)
            printf("Stan may be honest\n");
        else if(dis==1)
            printf("Stan is dishonest\n");
    }
    return 0;
}
