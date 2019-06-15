#include<stdio.h>
#include<string.h>
int main()
{
    freopen("706.txt", "r", stdin);
    int s,i,j,k,n,len,digit[20];

    while(scanf("%d%d",&s,&n)==2)
    {
        if(s==0 && n==0)
            break;
        i=0;
        do
        {
            digit[i]=n%10;
            n=n/10;
            i++;
        }while(n>0);
        len=i-1;



        /* first   */
        for(i=len;i>=0;i--)
        {
            if(digit[i]==0 || digit[i]==2 || digit[i]==3 || digit[i]==5 || digit[i]==6 || digit[i]==7 || digit[i]==8 || digit[i]==9)
            {
                printf(" ");
                for(j=1;j<=s;j++)
                    printf("-");
                printf(" ");
            }
            else if(digit[i]==1 || digit[i]==4)
            {
                for(j=1;j<=s+2;j++)
                    printf(" ");

            }
            if(i>0)
                printf(" ");
        }
        printf("\n");



        /* 2nd    */
        for(k=1;k<=s;k++)
        {
            for(i=len;i>=0;i--)
            {
                if(digit[i]==0 || digit[i]==8 || digit[i]==9|| digit[i]==4)
                {
                    printf("|");
                    for(j=1;j<=s;j++)
                        printf(" ");
                    printf("|");
                }
                else if(digit[i]==1 || digit[i]==2 || digit[i]==3 || digit[i]==7 )
                {
                    for(j=1;j<=s+1;j++)
                        printf(" ");
                    printf("|");

                }
                else if(digit[i]==5 || digit[i]==6)
                {
                    printf("|");
                    for(j=1;j<=s+1;j++)
                        printf(" ");

                }
                if(i>0)
                    printf(" ");
            }
            printf("\n");
        }



        /* 3rd */

        for(i=len;i>=0;i--)
        {
            if(digit[i]==2 || digit[i]==3 || digit[i]==4 || digit[i]==5 || digit[i]==6 || digit[i]==8  || digit[i]==9)
            {
                printf(" ");
                for(j=1;j<=s;j++)
                    printf("-");
                printf(" ");
            }
            else if(digit[i]==1 || digit[i]==0 || digit[i]==7)
            {
                for(j=1;j<=s+2;j++)
                    printf(" ");
            }
            if(i>0)
                printf(" ");
        }
        printf("\n");


        /*    4th    */

        for(k=1;k<=s;k++)
        {
            for(i=len;i>=0;i--)
            {
                if(digit[i]==0 || digit[i]==8 || digit[i]==6)
                {
                    printf("|");
                    for(j=1;j<=s;j++)
                        printf(" ");
                    printf("|");
                }
                else if(digit[i]==1 || digit[i]==3 || digit[i]==4 || digit[i]==5 || digit[i]==7 || digit[i]==9 )
                {
                    for(j=1;j<=s+1;j++)
                        printf(" ");
                    printf("|");

                }
                else if(digit[i]==2)
                {
                    printf("|");
                    for(j=1;j<=s+1;j++)
                        printf(" ");

                }
                if(i>0)
                    printf(" ");
            }
            printf("\n");
        }


        /*    5th    */
        for(i=len;i>=0;i--)
        {
            if(digit[i]==0 || digit[i]==2 || digit[i]==3 || digit[i]==5 || digit[i]==6 || digit[i]==8 || digit[i]==9)
            {
                printf(" ");
                for(j=1;j<=s;j++)
                    printf("-");
                printf(" ");
            }
            else if(digit[i]==1 || digit[i]==4 || digit[i]==7)
            {
                for(j=1;j<=s+2;j++)
                    printf(" ");

            }
            if(i>0)
                printf(" ");
        }
        printf("\n\n");

    }
    return 0;
}

