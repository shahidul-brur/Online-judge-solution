#include<stdio.h>
int main()
{
    freopen("10101.txt", "r", stdin);
    unsigned long long int n,c=1,l,l2,k,k2,h,h2,s,s2,ed;
    while(scanf("%llu",&n)!=EOF){
    k=n/100000000000000;
    l=(n%100000000000000)/1000000000000;
    h=(n%1000000000000)/10000000000;
    s=(n%10000000000)/1000000000;
    k2=(n%1000000000)/10000000;
    l2=(n%10000000)/100000;
    h2=(n%100000)/1000;
    s2=(n%1000)/100;
    ed=n%100;

    if(c<10)
        printf("   ");
    else if(c>9 &&c<100)
        printf("  ");
    else if(c>99 && c<1000)
        printf(" ");
    printf("%llu.",c);
    if(k>0)
        printf(" %llu kuti",k);
    if(l>0)
        printf(" %llu lakh",l);
    if(h>0)
        printf(" %llu hajar",h);
    if(s>0)
        printf(" %llu shata",s);
    if(k2>0)
        printf(" %llu",k2);
    if(n>9999999)
        printf(" kuti");
    if(l2>0)
        printf(" %llu lakh",l2);
    if(h2>0)
        printf(" %llu hajar",h2);
    if(s2>0)
        printf(" %llu shata",s2);
    if(ed>0)
        printf(" %llu",ed);
    if(n==0)
        printf(" 0");
    printf("\n");
    c++;
    }
    return 0;
}
