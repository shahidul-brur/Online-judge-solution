#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("537.txt", "r", stdin);
    int t,c,i,j,len,p,u,k,l,cnt;
    double P,U,I,f;
    char str[500];
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++)
    {
        gets(str);
        len=strlen(str);
        P=U=I=0.0;
        u=p=i=0;

        for(j=0;j<len;j++)
        {
            if(str[j]=='U' && str[j+1]=='=')
            {
                u=1;

                for(k=j+2;(str[k]>='0'&&str[k]<='9');k++)
                    U=U*10+(str[k]-'0');

                if(str[k]=='.')
                {
                    f=0.0;
                    cnt=0;
                    for(j=k+1;(str[j]>='0'&&str[j]<='9');j++)
                    {
                        f=f*10+(str[j]-'0');
                        cnt++;
                    }

                    while(cnt-->0)
                    {
                        f/=10;
                    }

                    U+=f;
                    k=j;
                }
                if(str[k]=='m')
                    U/=1000;
                else if(str[k]=='k')
                    U*=1000;
                else if(str[k]=='M')
                    U*=1000000;
            }
            else if(str[j]=='I' && str[j+1]=='=')
            {
                i=1;

                for(k=j+2;(str[k]>='0'&&str[k]<='9');k++)
                    I=I*10+(str[k]-'0');
                if(str[k]=='.')
                {
                    f=0.0;
                    cnt=0;
                    for(j=k+1;(str[j]>='0'&&str[j]<='9');j++)
                    {
                        f=f*10+(str[j]-'0');
                        cnt++;
                    }

                    while(cnt-->0)
                    {
                        f/=10;
                    }

                    I+=f;
                    k=j;
                }
                if(str[k]=='m')
                    I/=1000;
                else if(str[k]=='k')
                    I*=1000;
                else if(str[k]=='M')
                    I*=1000000;
            }
            else if(str[j]=='P' && str[j+1]=='=')
            {
                p=1;

                for(k=j+2;(str[k]>='0'&&str[k]<='9');k++)
                    P=P*10+(str[k]-'0');
                if(str[k]=='.')
                {
                    f=0.0;
                    cnt=0;
                    for(j=k+1;(str[j]>='0'&&str[j]<='9');j++)
                    {
                        f=f+(str[j]-'0');
                        cnt++;
                    }

                    while(cnt-->0)
                    {
                        f/=10;
                    }
                    P+=f;
                    k=j;
                }
                if(str[k]=='m')
                    P/=1000.0;
                else if(str[k]=='k')
                    P*=1000.0;
                else if(str[k]=='M')
                    P*=1000000.0;
            }
        }
        printf("Problem #%d\n",c);
        if(p==0)
            printf("P=%.2lfW\n\n",U*I);
        else if(u==0)
            printf("U=%.2lfV\n\n",P/I);
        else if(i==0)
            printf("I=%.2lfA\n\n",P/U);

    }
    return 0;
}
