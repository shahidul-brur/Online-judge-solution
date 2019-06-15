//Accepted

#include<stdio.h>
#include<string.h>
int isPrime(int num)
{
    if(num<2)
        return 0;
    int i;
    for(i=2;i<=num/i;i++)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    freopen("10789.txt", "r", stdin);
    int i,t,j,f,c,len,p;
    char str[2190];
    char ch;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {

        scanf("%s",&str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            for(j=0;j<len-1;j++)
            {
                if(str[j]>str[j+1])
                {
                    ch=str[j];
                    str[j]=str[j+1];
                    str[j+1]=ch;
                }
            }
        }
        p=0;
        printf("Case %d: ",c);
        for(i=0;i<len;i++)
        {
            f=0;
            ch=str[i];
            while(str[i]==ch)
            {
                f++;
                i++;
            }
            if(isPrime(f))
            {
                p=1;
                printf("%c",ch);
            }
            i--;
        }
        if(p==0)
            printf("empty");
        printf("\n");
    }
    return 0;
}
