//Accepted
 
#include <bits/stdc++.h>
using namespace std;
long long m[20000000];

int main()
{
    int n;
    m[0] = m[1] = 0;
    for(int i=1;i<=20000000;i++)
        for(int j=i;j<=20000000;j+=i)
            m[j] += i;
    for(int i=2;i<=20000000;i++)
        m[i] = m[i-1]+m[i];
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        printf("%lld\n", m[n]-1);
    }
    return 0;
}
