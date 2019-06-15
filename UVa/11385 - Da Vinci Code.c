//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("11385.txt", "r", stdin);
    long int t,n,fib[55],i,j,num[500],len,max,p[70];
    char in[105],s[105], out[105];
    fib[1]=1;
    fib[2]=2;
    for(i=3;i<=54;i++)
        fib[i]=fib[i-1]+fib[i-2];
    scanf("%ld",&t);
    while(t--)
    {
        strcpy(s, "");
        max=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
            scanf("%ld",&num[i]);
        getchar();
        gets(in);
        len=strlen(in);
        for(i=1;i<=60;i++)
            p[i]=0;
        for(i=0,j=0;i<len;i++)
        {
            if(in[i]>='A' && in[i]<='Z')
            {
                s[j]=in[i];
                j++;
            }
        }
        s[j]='\0';
        for(i=0;i<n;i++)
        {
            for(j=0;j<=54;j++)
            {
                if(num[i]==fib[j])
                {
                    if(j>max)
                        max=j;
                    p[j]=j;
                    out[j-1]=s[i];
                    break;
                }
            }
        }
        for(i=1;i<max;i++)
        {
            if(p[i]==0)
                out[i-1]=' ';
        }
        out[max]='\0';
        puts(out);
    }
    return 0;
}
