#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, sum=0, m=10000000009, x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        if(x%2!=0)
            m = min(m, x);
    }
    if(sum%2!=0)
        sum-=m;
    cout << sum << "\n";
    return 0;

}
