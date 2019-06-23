#include<bits/stdc++.h>
using namespace std;
long long a[2005], b1[1005], b2[1005];
int main()
{
    long long n, sum=0, x, y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a[x+y]++;
        if(x>y)
            b1[x-y]++;
        else b2[y-x]++;
    }
    for(int i=2;i<=2000;i++)
    {
        if(a[i]>0)
            sum+=(a[i]-1)*a[i]/2;
    }
    for(int i=1;i<=1000;i++)
    {
        if(b1[i]>0)
            sum+=(b1[i]-1)*b1[i]/2;
    }
    for(int i=0;i<=1000;i++)
    {
        if(b2[i]>0)
            sum+=(b2[i]-1)*b2[i]/2;
    }
    cout << sum << "\n";
    return 0;

}
