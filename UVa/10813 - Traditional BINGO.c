//Accepted
#include<stdio.h>
int main()
{
    freopen("10813.txt", "r", stdin);
    int t,r1,r2,r3,r4,r5,c1,c2,c3,c4,c5,d1,d2,num[30],n[900],i;
    scanf("%d",&t);
    while(t--)
    {
        r1=r2=r4=r5=c1=c2=c4=c5=0;
        r3=c3=d1=d2=1;
        for(i=1;i<=24;i++)
            scanf("%d",&num[i]);
        for(i=1;i<=75;i++)
            scanf("%d",&n[i]);
        for(i=1;i<=75;i++)
        {
            if(n[i]==num[1]||n[i]==num[2]||n[i]==num[3]||n[i]==num[4]||n[i]==num[5])
                r1++;
            if(n[i]==num[6]||n[i]==num[7]||n[i]==num[8]||n[i]==num[9]||n[i]==num[10])
                r2++;
            if(n[i]==num[11]||n[i]==num[12]||n[i]==num[13]||n[i]==num[14])
                r3++;
            if(n[i]==num[16]||n[i]==num[17]||n[i]==num[18]||n[i]==num[19]||n[i]==num[15])
                r4++;
            if(n[i]==num[20]||n[i]==num[21]||n[i]==num[22]||n[i]==num[23]||n[i]==num[24])
                r5++;
            if(n[i]==num[1]||n[i]==num[6]||n[i]==num[11]||n[i]==num[15]||n[i]==num[20])
                c1++;
            if(n[i]==num[2]||n[i]==num[7]||n[i]==num[12]||n[i]==num[16]||n[i]==num[21])
                c2++;
            if(n[i]==num[3]||n[i]==num[8]||n[i]==num[17]||n[i]==num[22])
                c3++;
            if(n[i]==num[4]||n[i]==num[9]||n[i]==num[13]||n[i]==num[18]||n[i]==num[23])
                c4++;
            if(n[i]==num[5]||n[i]==num[10]||n[i]==num[14]||n[i]==num[19]||n[i]==num[24])
                c5++;
            if(n[i]==num[1]||n[i]==num[7]||n[i]==num[18]||n[i]==num[24])
                d1++;
            if(n[i]==num[5]||n[i]==num[9]||n[i]==num[16]||n[i]==num[20])
                d2++;
            if(r1==5||r2==5||r3==5||r4==5||r5==5||c1==5||c2==5||c3==5||c4==5||c5==5||d1==5||d2==5)
             {
                printf("BINGO after %d numbers announced\n",i);
                break;
             }
        }
    }
    return 0;
}
