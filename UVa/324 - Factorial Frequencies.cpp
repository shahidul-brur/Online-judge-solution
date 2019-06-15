//Accepted
#include<stdio.h>
#include<string.h>
char f[1000], fact[370][1000];
int main()
{

    int i,j,k,div,n,len,L,m,sum,fq[12];

    fact[0][0]='1';
    fact[1][0]='1';
    strcpy(f,"1");
    for(k=2;k<=367;k++)
    {
        len=strlen(f);
        div=0;
        i=0;
        while(i<len)
        {
            sum=div+(f[i]-'0')*k;
            f[i]=(sum%10)+'0';
            div=sum/10;
            i++;
        }
        while(div>0)
        {
            f[i]=(div%10) + '0';
            div=div/10;
            i++;
        }
        f[i]='\0';
        for(j=0;j<i;j++)
            fact[k][j]=f[j];
        fact[k][j]='\0';
    }
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<10;i++)
            fq[i]=0;
        L=strlen(fact[n]);
        for(m=0;m<L;m++)
            fq[fact[n][m]-'0']++;
        printf("%d! --\n",n);
        for(i=0;i<10;i++)
        {
           printf("   (%d)",i);
           if(fq[i]<10)
                printf("    %d",fq[i]);
           else if(fq[i]>9 && fq[i]<100)
                printf("   %d",fq[i]);
           else if(fq[i]>99 && fq[i]<1000)
                printf("  %d",fq[i]);
           if(i==4)
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
