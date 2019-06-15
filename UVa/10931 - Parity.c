//Accepted

#include<stdio.h>
int main()
{
    int n,count,p,k,deci,i;
    char string[100],t;
    while(scanf("%u",&n) && n!=0){
    deci=n;
    i = 0;
    string[i++] = '\0';

    do
    {
        string[i++] = (n % 2) == 0 ? '0' : '1';
        n /= 2;
    } while (n != 0);

    k = 0;
    while (--i > k)
    {
        char t = string[i];
        string[i] = string[k];
        string[k++] = t;
    }
        count=0;
        while(deci)
        {
            count+=deci&1;
            deci>>=1;
        }
        printf("The parity of %s is %d (mod 2).\n",string,count);
    }
    return 0;
}
