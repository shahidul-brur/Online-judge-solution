#include<stdio.h>
#include<string.h>
int main()
{
    int a1,a2,a3,a4,len,i,sum=0;
    char str[100000];
    scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
    scanf("%s",&str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='1') sum+=a1;
        if(str[i]=='2') sum+=a2;
        if(str[i]=='3') sum+=a3;
        if(str[i]=='4') sum+=a4;
    }
    printf("%d\n",sum);
    return 0;
}