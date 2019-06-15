//Accepted
#include<stdio.h>
int main()
{
    freopen("11494.txt", "r", stdin);
    int r1,c1,r2,c2,k,r,c;
    while(scanf("%d %d %d %d",&r1,&c1,&r2,&c2)!=EOF)
    {
        if(r1==0&&c1==0&&r2==0&&c2==0)
        {
            break;
        }
        r=r1-r2;
        c=c1-c2;
        if(r<0)
            r=0-r;
        if(c<0)
            c=0-c;
        if(r1==r2 && c1==c2)
            k=0;
        else if((r1==r2 && c1!=c2)||(r1!=r2 && c1==c2))
            k=1;
        else if(r==c)
            k=1;
        else
            k=2;
        printf("%d\n",k);
    }
    return 0;
}
