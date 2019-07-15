#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, cnt, a[100005], n, i, even, ev[100005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        even = 0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
                even++;
            ev[i] = even;
        }
        cnt = 0;
        for(i=n-1;i>0;i--)
        {
            if(a[i]%2==0)
                cnt+=i;
            else
                cnt+=ev[i-1];
        }
        cout << cnt << "\n";
    }
    return 0;
}
