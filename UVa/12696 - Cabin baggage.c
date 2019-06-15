#include<stdio.h>
int main()
{
    freopen("12696.txt", "r", stdin);
    int t,total=0;
    float l,w,d,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%f %f %f %f",&l,&w,&d,&m);
        if(l<=56.0 && w<=45.0 && d<=25.0 && m<=7.0)
        {
            printf("1\n");
            total++;
        }
        else if((l+w+d)<=125.0 && m<=7.0)
        {
            printf("1\n");
            total++;
        }
        else printf("0\n");
    }
    printf("%d\n",total);
    return 0;
}
