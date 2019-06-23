#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[3], ans;
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    if(a[2]>=2*(a[0]+a[1]))
        ans = a[0]+a[1];
    else ans = (a[0]+a[1]+a[2])/3;
    cout << ans << "\n";
    return 0;
}
