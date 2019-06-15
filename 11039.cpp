#include <stdio.h>
int main()
{
    int t, a, n, i, j, r, b, red[500005], blue[500005], cnt, temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        r=b=1;
        while(n--)
        {
            scanf("%d",&a);
            if(a>0)
                blue[b++]=a;
            else if(a<0)
                red[r++]=0-a;

        }
        r--;
        b--;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<r;j++)
            {
                if(red[j]<red[j+1])
                {
                    temp=red[j];
                    red[j]=red[j+1];
                    red[j+1]=temp;
                }
            }
        }
        for(i=1;i<=b;i++)
        {
            for(j=1;j<b;j++)
            {
                if(blue[j]<blue[j+1])
                {
                    temp=red[j];
                    blue[j]=blue[j+1];
                    blue[j+1]=temp;
                }
            }
        }
    }
    return 0;
}
