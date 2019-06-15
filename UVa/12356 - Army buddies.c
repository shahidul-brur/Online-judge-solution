//Accepted

#include<stdio.h>
int main()
{
    freopen("12356.txt", "r", stdin);
    int n,r,L,R,Left[100003],Right[100003],i,j,l,fL,fR,rp,lm,rm;

    while(scanf("%d %d",&n,&rp)!=EOF)
    {
        if(n==0 && rp==0)
            break;
        for(i=1;i<n;i++)
        {
            Left[i]=i-1;
            Right[i]=i+1;
        }
        Right[n]=0;
        for(i=1;i<=rp;i++)
        {
            scanf("%d %d",&L,&R);

            if(Left[L]==0)
                printf("* ");
            else
                printf("%d ",Left[L]);
            if(Right[R]==0)
                printf("*\n");
            else
                printf("%d\n",Right[R]);

            Left[Right[R]]=Left[L];
            Right[Left[L]]=Right[R];

        }
        printf("-\n");
    }
    return 0;
}

