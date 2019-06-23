#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a[200];
    int i, v, mx, mn,n;
    while(cin>>n)
    {for(i=1;i<=n;i++)
    {
        cin>>v;
        if(v==1)
            mn=i;
        else if(v==n)
            mx=i;
    }
    int maxi = abs(mx-mn);
    maxi=max(maxi, abs(mx-1));
    maxi=max(maxi, abs(mn-1));
    maxi=max(maxi, abs(mx-n));
    maxi=max(maxi, abs(mn-n));
    /*
    maxi=abs(mn-1);
    maxi=abs(n-mx);
    maxi=abs(n-mn);
    */
    cout << maxi << "\n";
    }
    return 0;
}
