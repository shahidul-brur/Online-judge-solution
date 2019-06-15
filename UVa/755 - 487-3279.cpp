#include<stdio.h>
#include<string.h>
int main()
{
    freopen("755.txt", "r", stdin);
    char str[50];
    int t,n,num[100010],f[100010],len,i,j,N,prev,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        for(i=1;i<=n;i++)
            f[i]=0;
        c=1;
        for(j=1;j<=n;j++)
        {
            gets(str);
            len=strlen(str);
            N=0;
            for(i=0;i<len;i++)
            {
                if(str[i]>='0' && str[i]<='9')
                    N=N*10+str[i]-'0';
                else if(str[i]=='A' || str[i]=='B' || str[i]=='C')
                    N=N*10+2;
                else if(str[i]=='D' || str[i]=='E' || str[i]=='F')
                    N=N*10+3;
                else if(str[i]=='G' || str[i]=='H' || str[i]=='I')
                    N=N*10+4;
                else if(str[i]=='J' || str[i]=='K' || str[i]=='L')
                    N=N*10+5;
                else if(str[i]=='M' || str[i]=='N' || str[i]=='O')
                    N=N*10+6;
                else if(str[i]=='P' || str[i]=='R' || str[i]=='S')
                    N=N*10+7;
                else if(str[i]=='T' || str[i]=='U' || str[i]=='V')
                    N=N*10+8;
                else if(str[i]=='W' || str[i]=='X' || str[i]=='Y')
                    N=N*10+9;
            }
            //printf("%d\n",N);
            prev=0;
            for(i=1;i<c;i++)
            {
                if(num[i]==N)
                {
                    f[i]++;
                    prev=1;
                    break;
                }
            }
            if(prev==0)
            {
                num[c++]=N;
                f[c-1]++;
            }

        }
        for(i=1;i<c;i++)
           printf("%d %d\n",num[i],f[i]);
    }
    return 0;
}
