#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, mn=0, mx=0, i, j, y;
    cin>>n;
    
    for(i=1;i<=n;i++)
    {
        if(i%7==1 || i%7==2)
            mx++;
    }
    for(i=1;i<=n;i++)
    {
        if(i%7==0 || i%7==6)
            mn++;
    }
    cout << mn << " " << mx << "\n";
    return 0;
}
