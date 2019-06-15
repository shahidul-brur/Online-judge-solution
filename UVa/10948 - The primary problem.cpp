//Accepted

#include <bits/stdc++.h>
using namespace std;
int prime[1000002];
int main()
{
    //freopen("10948.txt", "r", stdin);
    int N, a, i, j, imp;
    memset(prime, 0, sizeof(prime));
    for(i=4;i<=1000000;i+=2)
        prime[i]=1;
    for(i=3;i<=1000000/i;i+=2)
        if(prime[i]==0)
            for(int j=i*i;j<=1000000;j+=i) prime[j]=1;
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        imp=1;
        if(prime[N-2]==0)
        {
            a=2;
            imp=0;
        }
        else
        {
            for(a=3;a<=N/2;a++)
                if(prime[a]==0)
                    if(prime[N-a]==0)
                    {
                        imp=0;
                        break;
                    }
        }
        if(imp==1)
            printf("%d:\nNO WAY!\n", N);
        else printf("%d:\n%d+%d\n", N, a, N-a);
    }
    return 0;
}
