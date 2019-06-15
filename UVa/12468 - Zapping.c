//Accepted

#include<stdio.h>
int main()
{
    int a,b,ans1,ans2,min;
    while(scanf("%d %d",&a,&b) && (a!=-1 || b!=-1))
    {
        if(a>b)
        {
            ans1=a-b;
            ans2=b+100-a;
        }
        else if(b>a)
        {
            ans1=b-a;
            ans2=a+100-b;
        }
        else if(a==b)
        {
            ans1=0;
            ans2=0;
        }
        min=(ans1<ans2) ? ans1:ans2;
        printf("%d\n",min);
    }
    return 0;
}
