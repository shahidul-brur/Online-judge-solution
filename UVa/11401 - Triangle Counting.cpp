/*
 100000 -> 83329583375000
 1000000 -> 83332958333750000

*/

#include<bits/stdc++.h>
using namespace std;
//unsigned long long tri[1000002];
int main()
{
    //freopen("in.txt", "r", stdin);
    unsigned long long cnt, n,i, j, k;
    /*
    //for(n=1;n<=1000000;n++)
    //{
        n=1000002;
        cnt=0;
        for(i=2;i<n-1;i++)
        {
            j=n-i;
            if(j>i)
                cnt+=(j-i)*(i-1);
            k=i-1;
            if(j<i)
                k=j-1;
            cnt+=k*(k+1)/2;
            tri[i]=cnt;
        }
    //}

    */
    while(scanf("%llu",&n)&&n>=3)
    {
        cnt=0;
        for(i=2;i<n-1;i++)
        {
            j=n-i;
            if(j>i)
                cnt+=(j-i)*(i-1);
            k=i-1;
            if(j<i)
                k=j-1;
            cnt+=k*(k+1)/2;
        }
        printf("%llu\n",cnt);
    }
    return 0;
}

/*
//////////////////////////////////////////////////
    j=n-i;
    if(j>i)
        cnt+=(j-i)*(i-1); // i+j - (j+1) = i-1)
    k=i-1;
    if(j<i)
        k=j-1;
    cnt+=k*(k+1)/2;
/////////////////////////////////////////////////
    for(j=i+1;j<n;j++)
    {
        if(n>=i+j)
            cnt+=(i-1); // i+j - (i+1) = i-1
        else cnt+=(n-j);
    }
/////////////////////////////////////////////////

    for(k=j+1;k<(i+j) && k<=n;k++)
    {
        if(i+j>k&&j+k>i&&k+i>j)
            cnt++;
    }
////////////////////////////////////////////////
*/
