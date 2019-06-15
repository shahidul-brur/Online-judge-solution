//ACCEPTED

#include<stdio.h>
#include<string.h>
int isPrime(int num)
{
    int i;
    for(i=2;i<=num/i;i++)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    int i,j,sum,len;
    char word[50];
    while(gets(word))
    {
        sum=0;
        len=strlen(word);
        for(i=0;i<len;i++)
        {
            if(word[i]>='a' && word[i]<='z')
                sum+=1+word[i]-'a';
            else if(word[i]>='A' && word[i]<='Z')
                sum+=27+word[i]-'A';
        }
        if(isPrime(sum))
            printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
