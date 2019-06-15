#include<stdio.h>
int main()
{
    freopen("12356.txt", "r", stdin);
    int n,r,L,R,p[100003],i,j,l,fL,fR,rp,lm,rm;

    while(scanf("%d %d",&n,&rp)!=EOF)
    {
        for(i=1;i<=n;i++)
            p[i]=1;  /* initially all soldiers are alive */
        if(n==0 && rp==0)
            break;

        for(i=1;i<=rp;i++)
        {
            fL=fR=0; //Assume left and right buddies are dead and not exist
            scanf("%d %d",&L,&R);

            for(j=L;j<=R;j++) //from L to R all buddies are killed
                p[j]=0;

            if(L>1)
            {
                for(j=L-1;j>=1;j--)   // search alive left buddy from L-1 to 1
                {
                    if(p[j]>0)
                    {
                        l=j;
                        fL=1;    // as a left alive buddy found
                        break;
                    }
                }
            }
            if(R<n)
            {
                for(j=R+1;j<=n;j++)  // search alive right buddy from R+1 to n
                {
                    if(p[j]>0)
                    {
                        r=j;
                        fR=1;    // as a right alive buddy found
                        break;
                    }
                }
            }
            if(fL==0)  // if left buddy not exist
                printf("* ");
            else
                printf("%d ",l);
            if(fR==0)  // if right buddy not exist
                printf("*\n");
            else
                printf("%d\n",r);



        }
        printf("-\n");
    }
    return 0;
}
