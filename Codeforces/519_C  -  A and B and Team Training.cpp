#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[3], ans;
    cin>>a[0]>>a[1];
    sort(a, a+2);
    if(a[1]>=2*a[0])
        ans = a[0];
    else ans = (a[0]+a[1])/3;
    cout << ans << "\n";
    return 0;
}
