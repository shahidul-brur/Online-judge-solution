#include<stdio.h>
#include<string.h>
long long int fact(long long n)
{
    int l;
    if(n==0)
        return 1;
    long long int f=1;
    for(l=1;l<=n;l++)
        f*=l;
    return f;
}
int main()
{
    freopen("10338.txt", "r", stdin);
    int T,i,j,c=1,fq[30],len;
    long long int R,N,ans;
    char str[30];
    scanf("%d",&T);
    getchar();
    while(T-->0)
    {
        gets(str);
        len=strlen(str);
        N=fact(len);
        R=1;
        for(i=1;i<=30;i++)
            fq[i]=0;
        for(i=0;i<len;i++)
        {
            fq[str[i]-'A']++;
        }
        for(i=0;i<26;i++)
            R=R*fact(fq[i]);

        ans=N/R;
        printf("Data set %d: %lld\n",c,ans);
        c++;
    }
    return 0;
}
