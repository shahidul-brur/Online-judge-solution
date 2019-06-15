//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    int t,L,D,i,j,k,d;
    char plate[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&plate);
        k=plate[0]-'A';
        j=plate[1]-'A';
        i=plate[2]-'A';
        L=i+j*26+k*26*26;
        D=(plate[7]-'0')+(plate[6]-'0')*10+(plate[5]-'0')*100+(plate[4]-'0')*1000;
        if(L>D)
            d=L-D;
        else d=D-L;
        if(d<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
