//Accepted
#include <stdio.h>
long square(long x)
{
    return x*x;
}
int main()
{
    freopen("11634.txt", "r", stdin);
    long num, i, rand[5000], c, brk;
    while(scanf("%ld",&num)!=EOF)
    {
        if(num==0)
            break;
        brk=c=0;
        rand[c++]=num;
        num=square(num);
        num=num%1000000;
        num=num/100;
        if(num==0)
        {
            rand[c++]=num;
            brk=1;
        }
        else if(num==rand[0])
        {
            brk=1;
        }
        while(brk==0 && num>0)
        {
            rand[c++]=num;
            num=square(num);
            num=num%1000000;
            num=num/100;
            if(num==0)
            {
                rand[c++]=num;
            }
            for(i=0;i<c;i++)
            {
                if(num==rand[i])
                {
                    brk=1;
                    break;
                }
            }
        }
        printf("%ld\n",c);
    }
    return 0;
}
