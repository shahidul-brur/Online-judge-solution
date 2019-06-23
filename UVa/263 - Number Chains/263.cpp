//Accepted

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("263.txt", "r", stdin);
    int n, n1, n2, digits[12], appear[1002], i, j, chain, ap, stop;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        printf("Original number was %d\n", n);
        stop=0;
        ap=chain=0;
        while(stop==0)
        {
            for(i=0;n>=0;i++)
            {
                digits[i]=n%10;
                n/=10;
                if(digits[i]==0 && n==0)
                    break;
            }
            sort(digits, digits+i);
            n1=n2=0;
            for(j=0;j<i;j++)
            {
                n1=n1*10+digits[j];
            }
            for(j=i-1;j>=0;j--)
            {
                n2=n2*10+digits[j];
            }
            n=n2-n1;
            printf("%d - %d = %d\n", n2, n1, n);
            appear[ap++]=n;
            for(i=0;i<ap-1;i++)
            {
                if(appear[i]==n)
                {
                    stop=1;
                    break;
                }
            }
        }
        printf("Chain length %d\n\n", ap);
    }
    return 0;
}
