#include<stdio.h>
int main()
{
    int n,i,m;
    scanf("%d",&n);
    do
    {
       m=n%10;
       n=n/10;
        if(m==0) printf("O-|-OOOO\n");
        else if(m==1) printf("O-|O-OOO\n");
        else if(m==2) printf("O-|OO-OO\n");
        else if(m==3) printf("O-|OOO-O\n");
        else if(m==4) printf("O-|OOOO-\n");
        else if(m==5) printf("-O|-OOOO\n");
        else if(m==6) printf("-O|O-OOO\n");
        else if(m==7) printf("-O|OO-OO\n");
        else if(m==8) printf("-O|OOO-O\n");
        else if(m==9) printf("-O|OOOO-\n");
    }while(n!=0);
    return 0;
}