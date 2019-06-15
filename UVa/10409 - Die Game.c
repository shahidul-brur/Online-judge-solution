//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    int c,i,n,s,e,w,t,b,temp;
    char comm[10];
    while(scanf("%d",&c)&&c!=0)
    {
        t=1;
        b=6;
        n=2;
        s=5;
        w=3;
        e=4;
        while(c--)
        {
            scanf("%s",comm);
            if(comm[0]=='n')
            {
                temp=n;
                n=t;
                t=s;
                s=b;
                b=temp;
            }
            else if(comm[0]=='s')
            {
                temp=s;
                s=t;
                t=n;
                n=b;
                b=temp;
            }
            else if(comm[0]=='e')
            {
                temp=e;
                e=t;
                t=w;
                w=b;
                b=temp;
            }
            else if(comm[0]=='w')
            {
                temp=w;
                w=t;
                t=e;
                e=b;
                b=temp;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
