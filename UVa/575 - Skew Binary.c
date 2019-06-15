//Accepted

#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    //freopen("575.txt", "r", stdin);
    long long int len,sum,i,j,d;
    char num[1000];
    while(gets(num) && num[0]!='0')
    {
        sum=0;
        j=1;
        len=strlen(num);
        for(i=len-1;i>=0;i--)
        {
            d=num[i]-'0';
            sum+=d*(pow(2,j)-1);
            j++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
