//Accepted

#include<stdio.h>
int main()
{
    freopen("11462.txt", "r", stdin);
    int n, i,a,age[102],c;
    while(scanf("%d",&n) && n!=0)
        {
            c=0;
            for(i=1;i<=100;i++)
                age[i]=0;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&a);
                age[a]++;
            }
            for(i=1;i<=100;i++)
            {
                if(age[i]>0)
                {
                    while(age[i]--)
                    {
                        c++;
                        printf("%d",i);
                        if(c<n)
                            printf(" ");
                    }

                }
            }
            printf("\n");

        }
    return 0;
}
