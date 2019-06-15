//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("706.txt", "r", stdin);
    int s,i,j,k,len,digit[20];
    char num[15];
    while(scanf("%d %s",&s,&num)==2)
    {
        if(s==0 && num[0]=='0' && num[1]=='\0')
            break;
        len=strlen(num);
        for(i=0;i<len;i++)
            digit[i]=num[i]-'0';



        /* first   */
        for(i=0;i<len;i++)
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
            if(i<len-1)
                printf(" ");
        }
        printf("\n");



        /* 2nd    */
        for(k=1;k<=s;k++)
        {
            for(i=0;i<len;i++)
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
                if(i<len-1)
                    printf(" ");
            }
            printf("\n");
        }



        /* 3rd */

        for(i=0;i<len;i++)
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
            if(i<len-1)
                printf(" ");
        }
        printf("\n");


        /*    4th    */

        for(k=1;k<=s;k++)
        {
            for(i=0;i<len;i++)
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
                if(i<len-1)
                    printf(" ");
            }
            printf("\n");
        }


        /*    5th    */
        for(i=0;i<len;i++)
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
            if(i<len-1)
                printf(" ");
        }
        printf("\n\n");

    }
    return 0;
}

