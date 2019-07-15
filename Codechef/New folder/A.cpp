/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
#define mx 1152921504606846976
long long bc(long long deci, int base)
{
    long long int N=0,rem,p=1;
    while(deci!=0)
        {
            rem=deci%base;
            N=N+p*rem;
            deci=deci/base;
            p=p*10;
        }
        return N;
}
long long rever(long long div)
{
    long long rem, rev=0;
    while(div!=0)
    {
        rem=div%10;
        rev=rev*10+rem;
        div/=10;
    }
    return rev;
}
int main()
{
    long long n, i, cas, cnt, nb1, nb2, r1, r2;
    int t, b1, b2;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        cnt=0;
        scanf("%d %d", &b1, &b2);
        printf("1");
        for(i=2;i<mx;i++)
        {
            nb1=bc(i, b1);
            nb2=bc(i, b2);
            r1=rever(nb1);
            r2=rever(nb2);

            if(nb1==r1 && nb2==r2)
            {
                printf(" %lld", i);
                cnt++;
                if(cnt==1000)
                    break;
            }
            //printf("  ##%lld\n", i);
        }
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

