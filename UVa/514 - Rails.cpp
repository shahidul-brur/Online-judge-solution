/**********************************************************
Status:     WA

Problem:    UVa 514 - Rails

Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh

Date created:  - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    int n, cas=1, i, j, a[1002], num, yes;
    while(cin>>n)
    {
        if(n==0)
            break;
        if(cas>1)
            printf("\n");
        while(cin>>num)
        {
            if(num==0)
                break;
            a[1]=num;
            for(i=2;i<=n;i++)
            {
                cin>>num;
                a[i]=num;
            }
            yes=1;
            if(a[2]>a[1])
                for(i=1;i<=n;i++)
                {
                    if(a[i]!=i)
                    {
                        yes=0;
                        break;
                    }
                }
            else
                for(i=1;i<=n;i++)
                {
                    if(a[i]!=n-i+1)
                    {
                        yes=0;
                        break;
                    }
                }
            if(yes==1)
                cout<<"Yes" << '\n';
            else cout<<"No" << '\n';
        }
        cas++;
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
