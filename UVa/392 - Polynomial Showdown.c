//Accepted

#include<stdio.h>
int main()
{
    //freopen("392.txt", "r", stdin);
    int c1,c2,c3,c4,c5,c6,c7,c8,d;
    while(scanf("%d %d %d %d %d %d %d %d %d",&c8,&c7,&c6,&c5,&c4,&c3,&c2,&c1,&d)!=EOF)
    {
        if(c8!=0 && c8!=1 && c8!=-1)
            printf("%dx^8",c8);
        else if(c8==1)
            printf("x^8");
        else if(c8==-1)
            printf("-x^8");
        if(c8==0)
        {
            if(c7!=0 && c7!=1 && c7!=-1)
                printf("%dx^7",c7);
            else if(c7==1)
                printf("x^7");
            else if(c7==-1)
                printf("-x^7");
        }
        else{
        if(c7<-1)
            printf(" - %dx^7",0-c7);
        else if(c7>1)
            printf(" + %dx^7",c7);
        else if(c7==1)
            printf(" + x^7");
        else if(c7==-1)
            printf(" - x^7");
        }
        if(c8==0 && c7==0)
        {
            if(c6!=0 && c6!=1 && c6!=-1)
                printf("%dx^6",c6);
            else if(c6==1)
                printf("x^6");
            else if(c6==-1)
                printf("-x^6");
        }
        else{
        if(c6<-1)
            printf(" - %dx^6",0-c6);
        else if(c6>1)
            printf(" + %dx^6",c6);
        else if(c6==1)
            printf(" + x^6");
        else if(c6==-1)
            printf(" - x^6");
        }
        if(c8==0 && c7==0 && c6==0)
        {
            if(c5!=0 && c5!=1 && c5!=-1)
                printf("%dx^5",c5);
            else if(c5==1)
                printf("x^5");
            else if(c5==-1)
                printf("-x^5");
        }
        else{
        if(c5<-1)
            printf(" - %dx^5",0-c5);
        else if(c5>1)
            printf(" + %dx^5",c5);
        else if(c5==1)
            printf(" + x^5");
        else if(c5==-1)
            printf(" - x^5");
        }
        if(c8==0 && c7==0 && c6==0 && c5==0)
        {
            if(c4!=0 && c4!=1 && c4!=-1)
                printf("%dx^4",c4);
            else if(c4==1)
                printf("x^4");
            else if(c4==-1)
                printf("-x^4");
        }
        else{
        if(c4<-1)
            printf(" - %dx^4",0-c4);
        else if(c4>1)
            printf(" + %dx^4",c4);
        else if(c4==1)
            printf(" + x^4");
        else if(c4==-1)
            printf(" - x^4");
        }
        if(c8==0&&c7==0&&c6==0&&c5==0&&c4==0)
        {
            if(c3!=0 && c3!=1 && c3!=-1)
                printf("%dx^3",c3);
            else if(c3==1)
                printf("x^3");
            else if(c3==-1)
                printf("-x^3");
        }
        else{
        if(c3<-1)
            printf(" - %dx^3",0-c3);
        else if(c3>1)
            printf(" + %dx^3",c3);
        else if(c3==1)
            printf(" + x^3");
        else if(c3==-1)
            printf(" - x^3");
        }
        if(c8==0&&c7==0&&c6==0&&c5==0&&c4==0&&c3==0)
        {
            if(c2!=0 && c2!=1 && c2!=-1)
                printf("%dx^2",c2);
            else if(c2==1)
                printf("x^2");
            else if(c2==-1)
                printf("-x^2");
        }
        else{
        if(c2<-1)
            printf(" - %dx^2",0-c2);
        else if(c2>1)
            printf(" + %dx^2",c2);
        else if(c2==1)
            printf(" + x^2");
        else if(c2==-1)
            printf(" - x^2");
        }
        if(c8==0&&c7==0&&c6==0&&c5==0&&c4==0&&c3==0&&c2==0)
        {
            if(c1!=0 && c1!=1 && c1!=-1)
                printf("%dx",c1);
            else if(c1==1)
                printf("x");
            else if(c1==-1)
                printf("-x");
        }
        else{
        if(c1<-1)
            printf(" - %dx",0-c1);
        else if(c1>1)
            printf(" + %dx",c1);
        else if(c1==1)
            printf(" + x");
        else if(c1==-1)
            printf(" - x");
        }
        if(c8==0&&c7==0&&c6==0&&c5==0&&c4==0&&c3==0&&c2==0&&c1==0)
        {
            printf("%d",d);
        }
        else{
        if(d>0)
            printf(" + %d",d);
        else if(d<0)
            printf(" - %d",0-d);
        }
        printf("\n");
    }
    return 0;
}
