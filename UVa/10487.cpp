//Accepted

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("10487.txt", "r", stdin);
    int n, m, sum, i, j, k,num[1001], q, mini, cas=1, ans;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
            cin>>num[i];
        cin>>m;
        cout<<"Case "<<cas<<":"<<endl;
        for(i=0;i<m;i++)
        {
            cin>>q;
            mini=10000000;
            for(j=0;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(num[j]!=num[k])
                    {
                        sum=num[j]+num[k];
                        if(abs(sum-q)<=mini)
                        {
                            mini=abs(sum-q);
                            ans=sum;
                        }
                    }
                }
            }
            cout<<"Closest sum to "<<q<<" is "<<ans<<"."<<endl;
        }
        cas++;
    }
    return 0;
}
