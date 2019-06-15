//Accepted

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;


int main()
{
    freopen("725.txt", "r", stdin);
    int abcde, fghij, N, used[11], cnt, n, sol, cas=1;
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        sol=0;
        if(cas>1)
            printf("\n");
        for(abcde=1234;abcde<=98765/N;abcde++)
        {
            fghij=abcde*N;
            if(fghij>98765)
                break;
            if(abcde<10000 && fghij<10000)
                continue;
            cnt=0;
            memset(used, 0, sizeof used);
            if(abcde<9999)
            {
                used[0]=1;
                cnt++;
            }
            if(fghij<9999)
            {
                used[0]=1;
                cnt++;
            }
            n=abcde;
            while(n>0)
            {
                if(used[n%10]==0)
                {
                    used[n%10]=1;
                    cnt++;
                }
                n/=10;
            }
            n=fghij;
            while(n>0)
            {
                if(used[n%10]==0)
                {
                    used[n%10]=1;
                    cnt++;
                }
                n/=10;
            }
            if(cnt==10)
            {
                printf("%05d / %05d = %d\n", fghij, abcde, N);
                sol++;
            }
        }
        if(sol==0)
            printf("There are no solutions for %d.\n", N);
        cas++;
    }
    return 0;
}
