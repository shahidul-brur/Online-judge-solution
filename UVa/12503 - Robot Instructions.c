//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("12503.txt", "r", stdin);
    int t, n, ins[110],i,j,go,k,p;
    char in[1000],sl[1000];
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++)
        {
            gets(in);
            if(in[0]=='L')
                ins[i]=-1;
            else if(in[0]=='R')
                ins[i]=1;
            else if(in[0]=='S')
            {
                for(j=8;j<=strlen(in);j++)
                {
                    sl[j-8]=in[j];
                }
                go=atoi(sl);
                ins[i]=ins[go];
            }
            if(ins[i]==1)
                p++;
            else if(ins[i]==-1)
                    p--;
        }
       printf("%d\n",p);
    }
    return 0;
}
