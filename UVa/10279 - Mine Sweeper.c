//Accepted
#include<stdio.h>
#include<string.h>
struct board{
char ch[15];
};
int main()
{
    freopen("10279.txt", "r", stdin);
    int t,n,i,j,count,c=1,flag,g;
    struct board in[15];
    struct board line[15];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",&in[i].ch);
        for(i=0;i<n;i++)
            scanf("%s",&line[i].ch);
        for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
            {
                if((line[i].ch[j]=='x' || line[i].ch[j]=='X') && in[i].ch[j]=='*')
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(c>1)
                printf("\n");

        for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
            {

                if(in[i].ch[j]=='*')
                      {
                          if(flag==1)
                              printf("*");
                           else
                              printf(".");
                      }
               else if(line[i].ch[j]=='x' || line[i].ch[j]=='X')
                    {
                        if(in[i].ch[j]=='.')
                        {
                            count=0;
                            if(j!=n-1)
                            {
                                if(in[i].ch[j+1]=='*')
                                count++;
                            }

                            if(j!=0)
                            {
                                if(in[i].ch[j-1]=='*')
                                count++;
                            }

                            if(i!=0)
                            {
                                if(in[i-1].ch[j]=='*')
                                count++;
                            }

                            if(i!=n-1)
                            {
                                if(in[i+1].ch[j]=='*')
                                count++;
                            }

                            if(i!=0 && j!=n-1)
                            {
                                if(in[i-1].ch[j+1]=='*')
                                count++;
                            }

                            if(i!=0 && j!=0)
                            {
                                if(in[i-1].ch[j-1]=='*')
                                count++;
                            }

                            if(i!=n-1 && j!=n-1)
                            {
                                if(in[i+1].ch[j+1]=='*')
                                count++;
                            }

                            if(i!=n-1 && j!=0)
                            {
                                if(in[i+1].ch[j-1]=='*')
                                count++;
                            }

                            printf("%d",count);
                        }
                    }
                    else
                        printf(".");
            }
            printf("\n");
        }
        c++;
    }
    return 0;
}
