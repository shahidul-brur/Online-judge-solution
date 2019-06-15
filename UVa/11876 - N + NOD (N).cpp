/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   Accepted
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
int NOD[1000003], seq[1000003];
void calDiv(int n)
{
    for(int i=1;i<=n;i++)
    {
        NOD[i]=0;
        int root=sqrt(i);
        for(int j=1;j<=root;j++)
        {
            if(i%j==0)
            {
                if(i/j==j)
                    NOD[i]++;
                else NOD[i]+=2;
            }
        }
    }
}
void calSeq(int n)
{
    int now;
    int pre = 1;
    seq[0]=0;
    seq[1]=1;
    for(int i=2;i<=n;i++)
    {
        now  = pre + NOD[pre];
        for(int j=i;j<now;j++)
        {
            seq[j] = seq[i-1];
        }
        seq[now] = seq[i-1] + 1;
        pre = now;
        i=pre;
    }
}
int main()
{
    //in;
    //out;
    calDiv(1000000);
    calSeq(1000000);
    int test, cas, A, B, i, j;
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &A, &B);
        printf("Case %d: %d\n", cas, seq[B] - seq[A-1]);
    }
    return 0;
}
