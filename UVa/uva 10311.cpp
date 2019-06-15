#include<bits/stdc++.h>
using namespace std;
#define N 100000000
int p[N/32+2];
vector<int> prime;

void setBit(int index, int pos)
{
    p[index] |= (1<<pos);
}
bool checkBit(int n, int pos)
{
    return (n & (1<<pos));
}
void sieve(int n)
{
    //0 is not prime
    setBit(0, 0);
    setBit(0, 1);
    for(int i=4;i<=n;i+=2)
        setBit(i>>5, i&31);
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(checkBit(p[i>>5], i&31)==0)
        {
            prime.push_back(i);
            for(int j=i+i;j<=n;j+=i)
                setBit(j>>5, j&31);
        }
    }
}
int main()
{
    freopen("10311.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    sieve(100000000);

    int siz = prime.size();
    while(scanf("%d",&n)!=EOF)
    {
        bool y=0;
        int d=999999999;
        int a, b;
        if(n>4 && (n&1) && !checkBit(p[(n-2)>>5], (n-2)&31))
        {
            y = 1;
            a = 2;
            b = n-2;
        }
        else if(n>4 && n%2==0)
        for(int i=0;i<siz;i++)
        {
            int n1 = prime[i];
            if(a>n/2)
                break;
            int n2 = n-prime[i];
            if(n2>n1 && !checkBit(p[n2>>5], n2&31) && n1!=n2 && abs(n1-n2)<d)
            {
                y=1;
                a = prime[i];
                b = n-prime[i];
                d = abs(a-b);
            }
        }
        if(y)
            printf("%d is the sum of %d and %d.\n",n,a,b);
        else
            printf("%d is not the sum of two primes!\n", n);
    }
    return 0;
}
