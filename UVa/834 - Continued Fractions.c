//Accepted

#include<stdio.h>
int main()
{
    int x,y,div,rem,n,f;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        printf("[");
        n=x/y;
        printf("%d;",n);
        rem=x%y;
        while(rem>1)
        {
            x=y;
            y=rem;
            n=x/y;
            rem=x%y;
            if(rem==0)
                break;
            printf("%d,",n);
        }
        printf("%d]\n",y);
    }
    return 0;
}
