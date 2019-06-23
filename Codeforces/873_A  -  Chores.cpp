#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x, ans = 0;
    cin>>n>>k>>x;
    for(int i = 1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(i<=n-k)
            ans+=a;
        else ans+=x;
    }
    cout << ans << "\n";
    return 0;
}
