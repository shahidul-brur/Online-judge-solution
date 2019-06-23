//Accepted

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define Maxi 10001
int main()
{
    freopen("12049.txt", "r", stdin);
    int t, M, cas, N, i, j, L1[Maxi], L2[Maxi], removed, contain;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>N>>M;
        for(i=0;i<N;i++)
            cin>>L1[i];
        for(i=0;i<M;i++)
            cin>>L2[i];
        sort(L1, L1+N);
        sort(L2, L2+M);
        removed=0;
        for(i=0,j=0;i<N;i++)
        {
            contain=0;
            for(;j<M;j++)
            {
                if(L2[j]>L1[i])
                    break;
                if(L1[i]==L2[j])
                {
                    contain=1;
                    j++;
                    break;
                }
            }
            if(contain==0)
                removed++;
        }

        for(i=0,j=0;j<M;j++)
        {
            contain=0;
            for(;i<N;i++)
            {
                if(L1[i]>L2[j])
                    break;
                if(L1[i]==L2[j])
                    {contain=1; i++; break;}
            }
            if(contain==0)
                removed++;
        }
        cout<<removed<<endl;
    }
    return 0;
}
