#include<stdio.h>
int main()
{
    int r1,c1,r2,c2,h,n,k,r,c;
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    if(((r1+c1)%2==0&&(r2+c2)%2==0)||((r1+c1)%2==1&&(r2+c2)%2==1))
    {
        if((r1+c1)==(r2+c2)||(r1-c1)==(r2-c2)) h=1;
        else h=2;
    }
    else h=0;
    if(r1==r2||c1==c2) n=1;
    else n=2;
    r=r1-r2;
    c=c1-c2;
    if(r<0) r=0-r;
    if(c<0) c=0-c;
    if(r>=c) k=r;
    else k=c;
    printf("%d %d %d\n",n,h,k);
    return 0;
}