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
int main()
{
    //freopen("a.txt", "r", stdin);
    long long n, i, j, mini, maxi, x[100005], d1, d2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            mini=abs(x[i+1]-x[i]);
            maxi=abs(x[n]-x[i]);
        }
        else if(i==n)
        {
            mini=abs(x[i-1]-x[i]);
            maxi=abs(x[1]-x[i]);
        }
        else
        {

            d1=abs(x[i+1]-x[i]);
            d2=abs(x[i-1]-x[i]);
            if(d1<d2)
                mini=d1;
            else mini=d2;

            d1=abs(x[1]-x[i]);
            d2=abs(x[n]-x[i]);
            if(d1>d2)
                maxi=d1;
            else maxi=d2;
        }
        cout<<mini<<" "<<maxi<< '\n';
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/