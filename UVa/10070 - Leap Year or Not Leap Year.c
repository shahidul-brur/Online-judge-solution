//Accepted

#include<stdio.h>
#include<string.h>
long Mod(char *n, long d)
{
    long long r=0,len,i;
    len=strlen(n);
    for(i=0;i<len;i++)
    {
        r=r*10+(n[i]-'0');
        r=r%d;
    }
    return r;
}
int main()
{
    freopen("10070.txt", "r", stdin);
    int lp,h,b,c=1;
    char yr[1000005];
    while(scanf("%s",&yr)!=EOF)
    {
        if(c>1)
            printf("\n");
        lp=h=b=0;
        if((Mod(yr,4)==0 && Mod(yr,100)!=0) || Mod(yr,400)==0)
            lp=1;
        if(Mod(yr,15)==0)
            h=1;
        if(lp==1 && Mod(yr,55)==0)
            b=1;
        if(lp==1)
            printf("This is leap year.\n");
        if(h==1)
            printf("This is huluculu festival year.\n");
        if(b==1)
            printf("This is bulukulu festival year.\n");
        if(lp==0 && h==0 && b==0)
            printf("This is an ordinary year.\n");

        c++;

    }
    return 0;
}
